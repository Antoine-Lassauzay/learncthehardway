#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

void die(const char *message)
{
    if(errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void print_arr(int *numbers, int count) {

    int i = 0;

    for(i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}

// typedef creates a fake type
// sort of an alias for another more complex type
// here it creates a function pointer

typedef int (*compare_cb)(int a, int b);
typedef int *(*algo_cb)(int *numbers, int count, compare_cb cmp);

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int *insertion_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;

    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(j=1; j < count; j++)
    {
        temp = target[j];
        i = j - 1;

        while(i >= 0 && cmp(target[i], temp) > 0)
        {
            target[i+1] = target[i];
            i = i - 1;
        }

        target[i+1] = temp;
    }

    return target;
}

int sorted_order(int a, int b)
{
    // printf("Comparing %d and %d: %s\n", a, b, (a - b) > 0 ? "true" : "false");

    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    }
    else {
        return a % b;
    }
}

clock_t test_sorting(int *numbers, int count, algo_cb algo, compare_cb cmp)
{
    clock_t t = clock();

    int *sorted = algo(numbers, count, cmp);

    t = clock() - t;

    if(!sorted) {
        die("Failed to sort.");
    }

    printf ("Took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

    if(count < 10) {
        print_arr(sorted, count);
    }

    free(sorted);

    // accessing method bodies as hexadecimal values
    // unsigned char *data = (unsigned char *)cmp;

    // for(i = 0; i < 25; i++) {
    //     printf("%02x:", data[i]);
    // }
    // printf("\n");

    return t;
}

int main(int argc, char const *argv[])
{
    int *numbers;
    int count = 0;
    int i = 0;

    if(argc < 2) {

        count = 10000;

        numbers = malloc(sizeof(int) * count);

        if(!numbers) {
            die("Memory error.");
        }

        for(i = 0; i < count; i++) {
            numbers[i] = rand() * count;
        }

        printf("Using random number sequence (%d items)\n", count);
    }
    else {
        count = argc - 1;


        char **inputs = argv + 1;

        numbers = malloc(sizeof(int) * count);

        if(!numbers) {
            die("Memory error.");
        }

        for(i = 0; i < count; i++) {
            numbers[i] = atoi(inputs[i]);
        }
    }



    // test_sorting(numbers, count, reverse_order);
    // test_sorting(numbers, count, strange_order);

    // this would generate a warning and fail at runtime
    // test_sorting(numbers, count, die);

    // this fails at runtime too (Segmentation fault)
    // test_sorting(numbers, count, NULL);

    printf("------------\nBubble sort:\n");
    clock_t cl_bubble = test_sorting(numbers, count, bubble_sort, sorted_order);

    printf("------------\nInsertion sort:\n");
    clock_t cl_insert = test_sorting(numbers, count, insertion_sort, sorted_order);

    free(numbers);

    return 0;
}
