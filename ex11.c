#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    i = 0;

    while(i < num_states) {
        printf("state %d : %s\n", i, states[i]);
        i++;
    }

    char *states_inverted[num_states];

    i = num_states - 1;

    while(i >= 0) {

        states_inverted[num_states-i-1] =  states[i];

        printf("state %d : %s\n",
            num_states-i, states_inverted[num_states-i-1]);

        i--;
    }

    return 0;
}
