// loop demos simple while loop for infinite loop
#include <stdio.h>
#include <unistd.h>

int counter = 0;

int main(void) {
    printf("Now starting an infinite loop.\n");
    while (1) {
	if (counter == 0)
		printf("Hello world");
        if (counter < 5) {
            printf(".");
	    counter = counter + 1;
	    fflush(stdout);
	    sleep(1);
	} else {
            printf("\n");
            counter = 0;
        }
    }
} // end main(void)
