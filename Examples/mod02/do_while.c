// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int counter = 0;
	int sum = 0;

	do {
		sum +=  2;
		printf("Sum %d and count %d\n", sum, counter);
	} while (counter++ < 10);

} // end main()




