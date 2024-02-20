// Deomonstrates using counter iteration with a for loop
// Author: Kurt Seiffert
#include <stdio.h>
#include <unistd.h>

int main(void) {

    // note we declare, initialize, iteration condition and increment the counter
    // in one statement.
    for (char i = 120, int j = 2; i+j <= 127; i++, j++) {
        printf("%d\n", i);
        sleep(1);
    }
}

// What happens if we change the 10 to a 9? How many times does it iterate? How could we fix that?
// Can we increment by 2?
// what happens if we decrement the counter instead of increment?
// What happens if we change to an unsigned int?
// What happens if we change to a char?
// Exiting based on another value?
// Using two control variables i and j and a conditional based on both i + j < 10.
// 
