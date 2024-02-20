// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {

	char array[] = "Hello world";
/*
	for (int i = 0; i < 20; i++) {
		array[i] = i*2;
	}
*/
	for (int i = 0; i <= sizeof(array) / sizeof(char); i++) {
                printf("Array[%d] is %d at location %p\n", i, array[i], &array[i]);
        }

	printf("Arry is %s\n", array);
	printf("Array is %p\n", array);

} // end main()




