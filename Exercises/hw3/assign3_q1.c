//michele Barrantes homework 3 question 1 
//
//

#include <stdio.h>
#define MAX_LENGTH 100 
	int main(){
	//1	A:
		unsigned int num1 = 1001;
		printf("%6u", num1);
		//B:
		char m[MAX_LENGTH];
		int i = 0;
		char c;
		while((c = getchar()) != 'z'){
			m[i++] = c; 
		}
		m[i] = '\0';
		//C:
		double num2 = 7.350;
		printf("%08.3f", num2);
		//D:
		int octal; 
		printf("Enter octal value: ");
		scanf("%o", &octal);
		printf("The value is: %d\n", octal);
		//E:
		int num3 = 300; 
		printf("with sign: %+d\n", num3);
		printf("without sign: %d\n", num3);
		//F:
		int num4 = -300;
		printf("As an unsigned number: %u\n", (unsigned int)num4);
		//G:
		int num5 = 100;
		printf("octal: %#o\n", num5);
		//H:
		int hex; 
		printf("Enter hexadecimal: ");
		scanf("%x", &hex);
		printf("The value in decimal is: %d\n", hex);
		//L:
		int num6 = 100;
		printf("hexa form: %#x\n", num6);
		//J:
		int hr, min, sec; 
		printf("Enter time in hh-mm-ss: ");
		scanf("%d-%*d-%*d", &hr, &min, &sec);
		printf("The time entered is: %02d:%02d:%02d\n", hr, min, sec);
		//K:
		int hr2, min2, sec2;
    		printf("Enter a time in format hh:mm:ss: ");
    		scanf("%d:%d:%d", &hr2, &min2, &sec2);
     		printf("The time entered is: %02d:%02d:%02d\n", hr, min, sec);
		//I:
		char s[100];
		printf("Enter string format \"chars\":");
		scanf("\"%[^\"]s",s);
		printf("the String is: %s\n",s);
		
	return 0;
	}
