//Michele Barrantes Question 2 of Assingnment 3


#include <stdio.h>

	int main(void){
		//A:
		printf("%-10d\n", 32100);
		//will print the number 32100 left justified in a 10 char field
		//B:
		//printf("%c\n", "this is a C string");
		//will have a run time error because the argument is invalid, the correct version: 
		printf("%s\n", "This is a C string");
		//C:
		printf("%#o\n%#X\n%#e\n", 17, 17, 1008.80609);
		//this will print the 3 numbers in octal, hecadecimal, and e+03
		//D:
		printf("%ld\n%+ld\n", 1000000, 8000000);
		//will print the numbers then the second number will have the plus sign
		//E:
		printf("%10.3g\n", 26593738);
		//will print the values in a 10 char field and 3 numbers after the decimal point
		//F:
		//printf("%*.lf\n", 8,3,8125.923738);
		//will result in compiler error because the format is incorrect^^, the correct way is:
		printf("%*.*lf\n", 8, 3, 8125.923738);
		//G:
		printf("%10.3E\n", 953.92738);
		//print values in 10 char field and 3 digits after the decimal point
		//H:
		printf("%d\n", 20.987);
		//will print out the number. 
	return 0;
	}
