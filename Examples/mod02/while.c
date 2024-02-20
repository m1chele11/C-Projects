// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int counter = 0;
	int sum = 0;

	while (++counter < 10) {
		sum +=  2;
		printf("Sum %d and count %d\n", sum, counter);
	}

} // end main()




