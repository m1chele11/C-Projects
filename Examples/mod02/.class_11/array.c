// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int numbers[20];
	
	for(int i = 0; i <= 20; i++) {
		numbers[i] = 2 * i;
		printf("Array[%d] %d in memory location %p;\n", i, numbers[i], &numbers[i]);
	} // for 

} // end main()




