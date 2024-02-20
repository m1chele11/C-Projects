/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a calculator 
    The program should ask for the input until 'q' is entered. 
    For each operation, print the result and then print whether the result is >100 or <100 or equal to 100
    Finally, print the number of calculations done until 'q' is entered */

// Check for possible logical errors and rectify them 


#include<stdio.h>

int main(void){
  char input;
  int num1, num2, result, count = 1;
   
  while(input != 'q' ){
	   
  printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: \n");

  scanf(" %c", &input);

  if(input == 'A' || input == 'S' || input == 'M' || input == 'D'){
	  count++;
    printf("Enter both numbers in required sequence: ");
    scanf("%d %d", &num1, &num2);
    switch(input){
        case 'A': 
                result = num1 + num2;
                break;  
        case 'S': 
                result = num1 - num2;
		break;
        case 'D':
                result = num1 / num2;
		break;
        case 'M': 
                result = num1 * num2;
	      	break; 	
    }
    printf("Result is %d \n", result);
    if(result < 100){
      printf("less than 100.\n");
    }
    if(result == 100){
      printf("Equal to  100\n");
    }if(result > 100){
      printf("greater than 100\n");
    }
  }
  else if(input == 'Q'){
	  break;}
  else{
    printf("Please choose a valid operation\n");
  }
  
  
  printf("Number of operations performed: %d \n",count);
  }
  printf("Quit the menu.\n");
  return(0);
  }
 
