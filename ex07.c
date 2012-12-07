#include <stdio.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;
    printf("You have %d bugs at the imaginary rate of of %f\n",
        bugs, bug_rate);

    unsigned long universe_of_defects = 4096L * 4096L * 4096L * 4096L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("Your are expected to have %f bugs.\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
        part_of_universe);

    char null_byte = '\0';
    int care_percentage = bugs * null_byte;

    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;
}
