// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	char score;

	printf("Enter test score for student: ");
	scanf("%c",&score);
	printf("You entered a %d\t %c\t %x:\n", score, score, score);
	if (score == 'A') { 
		printf("That is an A.\n");
	} else {
	       printf("That is not an A.\n");
	} 

} // end main()




