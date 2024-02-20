/* 
 * Basic C program to print out hello world! 
 * Author: Kurt Seiffert
*/

#include <stdio.h>
#include <unistd.h>


int main(void) {
  int myNumber = 0;

  for (int i = 0; i < 10; i++) {
      printf("%d ");
      sleep(2);

  }
  printf("\n");

  if (0) 
    printf("Zero\n");
//   printf("Hello: Welcome to C291!\n");
//   printf("Please enter a number and press ENTER: ");
//   scanf("%d", &myNumber);  
//   printf("Here is the number yor entered: %d\n",myNumber);
  return(0); 
}


