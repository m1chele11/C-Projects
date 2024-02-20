// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	char score;

	printf("Enter the score: ");
	scanf("%c", &score);

	if (score != 'A') { 
		printf("Score %d is not enough for an A.\n", score);
	} else {
		printf("Score %d is an A. \n", score);
	} // if else

} // end main()




