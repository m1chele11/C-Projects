// Couning letter grades with switch
#include <stdio.h>

int main(void) {
    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int eCount = 0;
    unsigned int fCount = 0;

    puts("Enger the letter grades.");
    puts("Enger the EOF character to end input.");

    int grade;  // one grade

    // loop until the user types end-of-file key sequence
    while ((grade = getchar()) != EOF ) {

        // determine which grade was input
        switch (grade) {  // switch nested in a while loop
            case 'A':   // grade was uppercase A
            case 'a':   // grade was lowercase a
                ++aCount;
                break;  // necessary to exit switch
            case 'B': 
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F': 
            case 'f':
                ++fCount;
                break;
            case '\n':  // ignore new lines
            case '\t':  // ignore tabs,
            case ' ':   // ignore spaces
                break;
            default:    // catch all for any other characters
                printf("%s", "Incorrect letter grade entered.");
                puts("Enger a new grade.");
                break;  // optional; will exit the switch anyway
        }   // end switch
    }   // end while

    // output the results
    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount);
    printf("B: %u\n", bCount);
    printf("C: %u\n", cCount);
    printf("D: %u\n", dCount);
    printf("F: %u\n", fCount);


}   // end main

// what is the EOF character?
