/* 
 * Basic C program to print out hello world! 
 * Assignment 01, this is Assigment 0 modified. 
 * Author:Michele Barrantes
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("\"*****{Welcome to C291 Fall 2021 @ IU}, %%% Golden Rule: Start working on everything as early as possible %%% Thanks***** \"");
   printf("\n");
	int num = 100;
 	 while(num > 0){
	 	 if(num % 2 == 0 ) {
			printf("%d", num);
	  		 for(int x = 0; x < 5; x++){
	   		 printf(".");
			 fflush(stdout);
	   		 sleep(1);
	  		 }
		  printf("\n");	 
		 }else{
		 printf("%d\n", num);  
	 }	 
 	 num--;
  }  
  return(0);
}


