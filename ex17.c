#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database
{
    struct Address rows[MAX_ROWS];
};

typedef struct Connection_s
{
    FILE *file;
    struct Database *db;
} Connection;

Connection *conn;

void die(const char *message)
{
    if(errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
        addr->id, addr->name, addr->email);
}

void Database_load()
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) {
        die("Failed to load database");
    }
}

void Database_open(const char *filename, char mode)
{
    conn = malloc(sizeof(Connection));

    if(!conn) {
        die("Memory error");
    }

    conn->db = malloc(sizeof(struct Database));

    if(!conn->db) {
        die("Memory error");
    }

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    }
    else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) {
        die("Failed to open the file");
    }
}

void Database_close()
{
    if(conn) {
        if(conn->file) {
            fclose(conn->file);
        }
        if(conn->db) {
            free(conn->db);
        }
        free(conn);
    }
}

void Database_write()
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

    if(rc != 1) {
        die("Failed to write to database");
    }

    rc = fflush(conn->file);

    if(rc == -1) {
        die("Cannot flush database.");
    }

}

void Database_create()
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void Database_set(int id, char * name, char *email)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        die("Already set, delete it first");
    }

    addr->set = 1;
    // contains a bug
    char *res = strncpy(addr->name, name, MAX_DATA);

    if(!res) {
        die("Name copy failed.");
    }

    res = strncpy(addr->email, email, MAX_DATA);

    if(!res) {
        die("Email copy failed");
    }
}

void Database_get(int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    }
    else {
        die("ID is not set");
    }
}

void Database_delete(int id)
{
    struct Address addr = {.id = id , .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list()
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

void Database_find(char * lookup)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            if(strstr(cur->name, lookup) != NULL) {
                Address_print(cur);
            }
            else if(strstr(cur->email, lookup) != NULL) {
                Address_print(cur);
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    if(argc < 3) {
        die("USAGE ex17 <dbfile> <action> [action params]");
    }

    char *filename = (char *)argv[1];
    char action = argv[2][0];

    // Connection *conn = Database_open(filename, action);
    Database_open(filename, action);
    int id = 0;

    if(argc > 3) {
        id = atoi(argv[3]);
    }

    if(id >= MAX_ROWS) {
        die("There's too many records.");
    }

    switch(action) {

        case 'c':
            Database_create();
            Database_write();
            break;

        case 'g':
            if(argc != 4) {
                die("Need an id to get");
            }
            else {
                Database_get(id);
            }
            break;

        case 's':
            if(argc != 6) {
                die("Need an id, name, email to set");
            }
            else {
                Database_set(id, (char *)argv[4], (char *)argv[5]);
                Database_write();
            }
            break;

        case 'd':
            if(argc != 4) {
                die("Need an id to delete");
            }
            else {
                Database_delete(id);
                Database_write();
            }
            break;

        case 'l':
            Database_list();
            break;

        case 'f':

            if(argc != 4) {
                die("Need a string to search");
            }

            Database_find((char *)argv[3]);
            break;

        default:
            die("Invalid actions, use:\n c:create, g:get, s:set, d:del, l:list, f:find");
    }

    Database_close();

    return 0;
}
