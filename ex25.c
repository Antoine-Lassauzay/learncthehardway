#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#define MAX_DATA 5

int read_string(char **out_string, int max_buffer)
{
    *out_string = calloc(1, max_buffer + 1);

    assert(out_string != NULL);

    char *result = fgets(*out_string, max_buffer, stdin);
    assert(result != NULL);

    return 0;
}

int read_int(int *out_int)
{
    char *input = NULL;

    int rc = read_string(&input, MAX_DATA);
    assert(rc == 0);

    *out_int = atoi(input);

    free(input);

    return 0;
}

int read_scan(const char *fmt, ...)
{
    int i = 0;
    int rc = 0;
    int *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);

    for(i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;

            switch(fmt[i]) {

                case '\0':
                    printf("Invalid format.\n");
                    return -1;
                    break;

                case 'd':
                    out_int = va_arg(argp, int *);
                    rc = read_int(out_int);
                    assert(rc == 0);
                    break;

                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;

                case 's':
                    max_buffer = va_arg(argp, int);
                    out_string = va_arg(argp, char **);
                    rc = read_string(out_string, max_buffer);
                    assert(rc == 0);
                    break;

                default:
                    printf("Invalid char: %c\n", fmt[i]);
                    return -1;
            }
        }
        else {
            fgetc(stdin);
        }

        assert(!feof(stdin) && !ferror(stdin));
    }

    va_end(argp);
    return 0;
}

int main(int argc, char const *argv[])
{
    char *first_name = NULL;
    char initial = ' ';
    char *last_name = NULL;

    int age = 0;

    printf("What's your first name? ");
    int rc = read_scan("%s", MAX_DATA, &first_name);
    assert(rc == 0);

    printf("What's your initial? ");
    rc = read_scan("%c\n", &initial);
    assert(rc == 0);

    printf("What's your last name? ");
    rc = read_scan("%s", MAX_DATA, &last_name);
    assert(rc == 0);

    printf("How old are you? ");
    rc = read_scan("%d", &age);
    assert(rc == 0);

    printf("==== Results ====\n");
    printf("First Name: %s", first_name);
    printf("Initial: %c\n", initial);
    printf("Last Name: %s", last_name);
    printf("Age: %d\n", age);

    free(first_name);
    free(last_name);

    return 0;
}
