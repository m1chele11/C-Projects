// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {

	int limit = 5;

	for (int i = 0; i < 10; i++) {

		printf("Value of i is %d and it is %s\n", i, (i % 2) ? "ODD" : "EVEN" );  // ternary ?: 

	} // end for

	printf("Loop as finished.");

} // end main()




