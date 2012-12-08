#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
Structure composed of fields
to represent a person
*/
struct Person
{
    char *name;
    int age;
    int height;
    int weight;
};

/*
Function that creates a Person
*/
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // you actually need to allocate memory manually
    // you need to specifiy who many bytes to allocate
    // malloc returns void * , which is an untyped pointer
    struct Person *who = malloc(sizeof(struct Person));

    // make sure the pointer is valid
    // this can be the case if there is an problem when allocating memory
    // for instance when no memory is available
    assert(who != NULL);

    // copy the name to the Person field

    // do the same for each property
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

/*
Function that destroys a Person (from memory!)
*/
void Person_destroy(struct Person *who)
{
    // make sure the input is valid
    assert(who != NULL);

    // free the memory used by "name" (remember it was actually copied)
    // if not, the memory used by name is never reclaimed (memory leak)
    free(who->name);

    // free the memory used by the given pointer
    free(who);
}

/*
Function that prints a person - nothing fancy here
*/
void Person_print(struct Person *who)
{
    printf("\tName:%s, age:%d, height:%d, weight:%d\n",
        who->name, who->age, who->height, who->weight);
}

int main(int argc, char const *argv[])
{
    // create Person and store them in pointers
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    printf("Joe is a memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is a memory location %p:\n", frank);
    Person_print(frank);

    // Modify fields
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // free memory occupied by the value the pointers refer to
    Person_destroy(joe);
    Person_destroy(frank);

    // this causes an error - Assertion failed (abort trap)
    // Person_destroy(NULL);

    return 0;
}
