// loop demos simple while loop for infinite loop
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Now starting an infinite loop.\n");
    while (1) {
	sleep(1);
        printf("Hello world.\n");
    }
} // end main(void)


