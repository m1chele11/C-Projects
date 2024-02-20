// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
	char code;

	printf("Enter a grade code: ");
	scanf("%c", &code);
	
	switch (code) { 
		case 'A': 
		case 'a':
			printf("You entered %c which is a an A\n", code);
			break;
		case 'B' :
		case 'b' :
			printf("You entered %c which is a an B\n", code);
			break;
		case 'C' :
		case 'c' :
			printf("You entered %c which is a an C\n", code);
			break;
		case 'D' :
		case 'd' :	
			printf("You entered %c which is a an D\n", code);
			break;
		case 'F' :
		case 'f' :
			printf("You entered %c which is a an F\n", code);
			break;
		default :
			printf("You  entered an invalid grade code. \n");

	} // end switch
} // end main()




