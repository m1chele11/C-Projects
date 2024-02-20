// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	char code;

	printf("Please enter a grade code: ");
	scanf("%c",&code);
	
	switch (code) {
		case 'A':
		case 'a':
			printf("You enter code  %c which is an A\n", code);
			break;
		case 'B':
			printf("You enter code  %c which is an B\n", code);
			break;
		case 'C':
			printf("You enter code  %c which is an C\n", code);
			// break;
		case 'D':
			printf("You enter code  %c which is an D\n", code);
			break;
		case 'F':
			printf("You enter code  %c which is an F\n", code);
			break;
		default:
			printf("You entered and invalid grade %c\n", code);
	} // end switch

} // end main()




