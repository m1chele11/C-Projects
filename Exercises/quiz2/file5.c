/*Debugging quiz - File No: 5 */
/* This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible logical errors and rectify them 


#include<stdio.h>
#include<stdbool.h>

int main(void){
    int num,i;
    bool factor_found = false;
    printf("Enter Number:\n");
    scanf("%d",&num);
    if(num == 0 || num == 1){
        printf("%d is not prime or composite\n ",num);
    }
    for (i = 2; i<num; i++){
        if (num%i == 0){
            factor_found = true;
            break;
	}
    }
    if (!factor_found){
        printf("%d is a composite number\n",num);
    }
    else{
        printf("%d is a prime number\n", num);
    }
}
