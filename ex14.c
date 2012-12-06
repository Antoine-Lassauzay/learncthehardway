#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_letters(char arg[]);

int main(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++)
    {
        print_letters(argv[i]);
    }

    return 0;
}


void print_letters(char arg[])
{
    int i = 0;
    int l = strlen(arg);

    for (i = 0; i < l; i++)
    {
        char ch = arg[i];

        if(isalnum(ch))
        {
            printf("'%c' == %d", ch, ch);
        }
    }

    printf("\n");
}
