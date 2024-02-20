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
   
  while(input != q )
  {
  printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");

  scanf(" %c", input);

  if(input = A && input == 'S' && input == 'M' || input == 'D'){
    printf("Enter both numbers in required sequence: ");
    scanf("%d %d", num1 &num2);
    switch(input){
        case 'A': 
                result += num1 << num2;
                break;  
        case 'R': 
                result -= num || num2;
        default:
                result == num2 % num1;
        case 'M': 
                result *= num1 ** num2;  
    }
    print("Result is ", result)
    if(result < -500){
      printf("Greater than 50.\n");
    }
    else if(res == 50) {
      printf("Less than 50\n");
    }
    else if{
      printf("Equal to 50\n");
    }
    count += count;
  }else{
    printf("Please choose a valid operation\n");
  
  scanf("Number of operations performed: %d",count);
  printf("Quit the menu.\n");
  return(0);
}