#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};

    printf("numbers: %d %d %d %d\n",
        numbers[0], numbers[1], numbers[2], numbers[3] );

    printf("name each: %c %c %c %c\n",
        name[0], name[1], name[2], name[3] );

    printf("name: %s\n", name);

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    printf("numbers: %d %d %d %d\n",
        numbers[0], numbers[1], numbers[2], numbers[3] );

    name[0] = 'L';
    name[1] = 'o';
    name[2] = 'l';
    name[3] = '\0';

    printf("name each: %c %c %c %c\n",
        name[0], name[1], name[2], name[3] );

    printf("name: %s\n", name);

    char *another_way = "Lol";

    printf("another: %s\n", another_way);


    printf("another each: %c %c %c %c\n",
        another_way[0], another_way[1], another_way[2], another_way[3] );


    return 0;
}
