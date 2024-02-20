// demonstrates using for loop to sum all even integers from 2 .. 100
// Kurt Seiffert
#include <stdio.h>

int main(void) {
    unsigned int sum = 0;  //initialize the accumulator

    for (unsigned int num = 2; num <= 100; num += 2) {
        sum += num;
    }

    printf("Sum of even integers from 2 to 100: %u\n", sum);
}
