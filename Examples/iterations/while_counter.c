// Deomonstrates using counter iteration with while loop
// Author: Kurt Seiffert
#include <stdio.h>

int main(void) {
    unsigned int counter = 1;   // intialization of counter

    while (counter <= 10) {     // iteration condition
        printf("%u\n", counter);
        ++counter;  //increment
    }
}

// Note we can make the while loop a little more concise and remove a line from the block. 
// What could we do?