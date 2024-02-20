/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

#include <stdio.h>

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum, i, j;
    char c;
   
    printf("The value of limit is %d \n", limit);
    for(i = 1; i <= limit; ++i){
       		if(i % 2 == 0 ){
           		even_product *= i;
       		}   
       		else{
           		odd_product *= i ;
       		}
    }
        sum = even_product + odd_product;
    	
    
    printf("The Sum = %d \n", sum);

    for(c = 'Z'; c >= 'A'; c-=2){
            printf("%c ", c);
    }
     puts("\n"); 
    return 0;
}
