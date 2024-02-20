// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
    char ch = 'B';
   printf("Character Data\t\t\t:%c\n", ch); //printing character data

   //print decimal or integer data with d and i
   int x = 45, y = 90;
   printf("Integer with %%d\t\t\t:%d\n", x);
   printf("INteger with %%i\t\t\t:%i\n\n", y);
   
   float f = 12.67;
   printf("Float with %%f\t\t\t:%f\n", f); //print float value
   printf("Float with %%e\t\t\t:%e\n", f); //print in scientific notation
   printf("Float 8 char\t\t\t:%8.1f\n", f); //print formatted to 8 characters
   printf("Float 8 0 pad\t\t\t:%08.1f\n\n", f); //print formatted to 8 characters with single digit precision 

   int a = 67;
   printf("Octal integer\t\t\t:%o\n", a); //print in octal format
   printf("Hex integer\t\t\t:%x\n", a); //print in hex format
   printf("Hex integer 0X\t\t\t:%#x\n", a); //print in hex format
   printf("Pointer\t\t\t\t:%p\n\n", &a); // print a pointer value
   
   char str[] = "Hello World";
   printf("String\t\t\t\t:%s\n", str);
   printf("20 char string\t\t\t:%20s\n", str); //shift to the right 20 characters including the string
   printf("String left justified\t\t:%-20s\n", str); //left align
   printf("20 to right 5 char from string\t:%20.5s\n", str); //shift to the right 20 characters including the string, and print string up to 5 character
   printf("String left align\t\t:%-20.5s\n\n", str); //left align and print string up to 5 character

   float fp = 20.567;
   for (int i = 0; i < 5; i++) {
	   printf("Variable width %i\t\t:%0*.0f\n", i, i, fp);
   }
   printf("\n");
   for (int i = 0; i < 5; i++) {
	   printf("Variable precision %i\t\t:%.*f\n", i, i, fp);
   }

} // end main()




