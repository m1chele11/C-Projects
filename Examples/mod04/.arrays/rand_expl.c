// Program to investigate using rand() 
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    printf("RAND_MAX: %d\n", RAND_MAX);
    printf("A random number: %d", rand());

    int max, min;
    max = min = 0;
    #define TRIALS 10000

    for(int i = 0; i < TRIALS; i++) {
        int new_num = (rand() % 9000) + 1000;
        if (new_num > max)
            max = new_num;
        if (new_num < min)
            min = new_num;
    }
    printf("After %d trials - MAX: %d  MIN: %d\n", TRIALS, max, min);
}