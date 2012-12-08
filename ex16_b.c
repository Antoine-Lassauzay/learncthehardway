/*
    http://c.learncodethehardway.org/book/learn-c-the-hard-waych17.html
    Ex. 16 but rewritten without the use of pointers and malloc
*/
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
But returns it by value - not a pointer
*/
struct Person Person_create(char *name, int age, int height, int weight)
{
    struct Person who;

    who.name = strdup(name);
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}

/*
Function that destroys a Person (from memory!)
*/
void Person_destroy(struct Person who)
{
    // make sure the input is valid
    assert(&who != NULL);

    // free the memory used by "name" (remember it was actually copied)
    // if not, the memory used by name is never reclaimed (memory leak)
    free(who.name);

    // does not make sense because
    // who only exists as a local variable
    // free(who);
}

/*
Function that prints a person - accessing .
*/
void Person_print(struct Person who)
{
    struct Person * ptr_to_who = &who;

    // illustrate the difference between "->" and "."
    // use "->" to read fields of a struct through a pointer
    // use "." to read fields of a struct through a value
    printf("\tName:%s, age:%d, height:%d, weight:%d\n",
        who.name, who.age, (*ptr_to_who).height, ptr_to_who->weight);
}


int main(int argc, char const *argv[])
{

    struct Person antoine = Person_create("Antoine Lassauzay", 24, 180, 75);

    Person_print(antoine);
    Person_destroy(antoine);

    return 0;
}
