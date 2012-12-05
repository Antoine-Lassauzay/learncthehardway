#include <stdio.h>

int main(int argc, char * argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Antoine";
    char last_name[] = "Lassauzay";

    printf("You are %d kilometers away.\n", distance);
    printf("You have %f levels of powers\n", power);
    printf("You have %f levels of super powers\n", super_power);
    printf("I have a initial %c\n", initial);
    printf("I am %s %s\n", first_name, last_name);

    return 0;
}
