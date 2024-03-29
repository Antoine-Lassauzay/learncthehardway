#include <stdio.h>

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;


int main(int argc, char const *argv[])
{

    Person you = {.age = 0};

    int i = 0;

    char *in = NULL;

    printf("What's your First Name? ");
    in = fgets(you.first_name, MAX_DATA-1, stdin);
    // in = gets(you.first_name); -> DON'T USE gets

    if(in == NULL) {
        printf("Failed to read first name.");
        return 1;
    }

    printf("What's your Last Name? ");
    in = fgets(you.last_name, MAX_DATA-1, stdin);

    if(in == NULL) {
        printf("Failed to read last name.");
        return 1;
    }

    printf("How old are you? ");
    int rc = fscanf(stdin, "%d", &you.age);

    if(rc < 1) {
        printf("Failed to read age.");
        return 1;
    }

    printf("What colors are your eyes:\n");

    for(i = 0; i<= OTHER_EYES; i++) {
        printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
    }

    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);

    if(rc < 1) {
        printf("Failed to read eyes color, please enter a number.");
        return 1;
    }

    you.eyes = eyes -1;

    if(you.eyes >= OTHER_EYES && you.eyes >= 0) {
        printf("Failed to read eyes color.");
        return 1;
    }

    printf("How much you do make an hour? ");

    rc = fscanf(stdin, "%f", &you.income);

     if(rc < 1) {
        printf("Failed to read income, please enter a point number.");
        return 1;
    }


    printf("======== Results =========\n");

    printf("First Name: %s", you.first_name);
    printf("Last name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;
}
