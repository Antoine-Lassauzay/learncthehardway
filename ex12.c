#include <stdio.h>;

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 2) {
        printf("Not enough arguments\n");
    }
    else if(argc > 2 && argc < 5)
    {
        for (i = 0; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Too many arguments\n");
    }

    return 0;
}
