// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	int sum = 0;
	int counter = 0;
	int j = 1;

	for(int i = 0;  i+j < 10; i++, ++j) {
	       printf("Sum %d and count %d\n", sum, i);
	       counter = i;
	} // for loop

	printf("Final value of sum %d and counter %d\n", sum, counter);	

} // end main()




