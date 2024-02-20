// Simple program to play with fgets()
#include <stdio.h>
#define BUF_LIMIT 10

int main(void) {
    char buf[10];
    int myInt;

    double myDouble;
    long int myLong = 98;
    float myFloat;
    int count = 0;

    printf("Enter an integer, a double, a long, and a float: ");
    count = scanf("%d, %lf, %ld %f", &myInt, &myDouble, &myLong, &myFloat);
    printf("You entered: %d %lf %ld %f\n", myInt, myDouble, myLong, myFloat);
    printf("scanf read %d value.\n", count);
    return 0;
  /*
  for (int i = 0; i <4; i++) { 
    char myChar;
    printf("Enter A code and value: ");
    count = scanf("%c %d", &myChar, &myInt); 
    printf("You entered %c and value %d with count of %d\n", myChar, myInt,count);
  }
  return 0;
 i*/
} // end main
