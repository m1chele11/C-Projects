// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int counter = 0;
	int sum = 0;

	while (++counter < 10) {
		sum += 2;
	}
	printf("This is our sum: %d\n", sum);

} // end main()




