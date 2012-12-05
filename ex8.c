#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{


    int areas[] = {10, 12, 13, 14, 20};
    char first_name[] = {'A', 'n', 't', 'o', 'i', 'n', 'e', '\0'};
    char last_name[] = "Lassauzay";

    int sizeof_int = sizeof(int) * 8;
    int sizeof_uint = sizeof(unsigned int) * 8;

    printf("The size of an int is %d byte(s) or %d bits\n",
        sizeof_int / 8, sizeof_int);
    printf("The size of an unsigned int is %d byte(s) or %d bits\n",
        sizeof_uint / 8, sizeof_uint);
    printf("The maximum value for an int is %d\n",
        (int)pow(2, sizeof_int-1) - 1);
    printf("The maximum value for an unsigned int is %ld\n",
        (long int)pow(2, sizeof_uint) - 1);
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n",
        sizeof(areas) / sizeof(int));
    printf("The first area is %d and the second %d\n",
        areas[0], areas[1]);

    // valgrind says "Conditional jump or move depends on uninitialised value(s)"
    // printf("%d\n", areas[10]);

    printf("The size of a char is %ld byte(s) or %ld bits\n",
        sizeof(char), sizeof(char) * 8);
    printf("The maximum value for a char is %d\n",
        (int)pow(2, sizeof(char)*8) - 1);
    printf("The size of a first_name (char[]): %ld\n", sizeof(first_name));
    printf("The number of chars in first_name: %ld\n",
        sizeof(first_name) / sizeof(char));

    printf("The size of a last_name (char[]): %ld\n", sizeof(last_name));
    printf("The number of chars in last_name: %ld\n",
        sizeof(last_name) / sizeof(char));

    printf("first_name=\"%s\" last_name=\"%s\"\n",
        first_name, last_name);

    return 0;
}
