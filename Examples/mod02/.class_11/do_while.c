// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int counter = 0;
	int sum = 0;

	do   {
		sum += 2;
	} while (counter++ < 10);

	printf("This is our sum: %d\n", sum);

} // end main()




