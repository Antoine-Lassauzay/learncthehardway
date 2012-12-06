#include <stdio.h>

void print_people_ages_1(int ages[], char* names[], int count);
void print_people_ages_2(int *cur_age, char **cur_name, int* count);
void print_people_ages_3(int *cur_age, char **cur_name, int* count);
void print_people_ages_4(int *cur_age, char **cur_name, int* count);

int main(int argc, char *argv[])
{

    int ages[] = {23, 43, 12, 89, 2};
    char* names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    int count = sizeof(ages) / sizeof(int);

    print_people_ages_1(ages, names, count);
    print_people_ages_2(ages, names, &count);
    print_people_ages_3(ages, names, &count);
    print_people_ages_4(ages, names, &count);


    return 0;
}

void print_people_ages_1(int ages[], char* names[], int count)
{
    printf("1: No pointers\n");

    int i = 0;

    for (i = 0; i < count; ++i)
    {
        printf("%s has %d years alive.\n",
            names[i], ages[i]);
    }

}

void print_people_ages_2(int *cur_age, char **cur_name, int* count)
{
    printf("\n2: Pointers with increment *(ptr+1)\n");

    int i = 0;

    for (i = 0; i < *count; ++i)
    {
        printf("%s is %d years old.\n",
            *(cur_name+i), *(cur_age+i));
    }
}

void print_people_ages_3(int *cur_age, char **cur_name, int* count)
{
    printf("\n3: Pointers with array access ptr[i]\n");

    int i = 0;

    for (i = 0; i < *count; ++i)
    {
        printf("%s is %d years old again.\n",
            cur_name[i], cur_age[i]);
    }
}

void print_people_ages_4(int *cur_age, char **cur_name, int* count)
{
    printf("\n4: Pointers arithmetics *(ptr++)\n");

    int* first_age = cur_age;

    for (;
         (cur_age - first_age) < *count;
         cur_name++, cur_age++)
    {

        printf("%s lived %d years so far.\n",
            *cur_name, *cur_age);

        // prints the address of the pointers
        printf("%p %p\n", first_age, cur_age);
    }

}


