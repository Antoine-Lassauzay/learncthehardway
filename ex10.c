#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // argv[0] = name of the program

    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // char state=[] = {
    // would not work, because it would be an array of (char x[])
    // where an array of array of char (char *x[])
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
