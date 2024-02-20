// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 
   // loop 10 times and calculate output square of x
    
int square(int ); // function prototype or declaration
int pow(int, int); 
int main(void) {
   
   
   // loop 10 times and calculate output square of x
   for (int x = 1; x <= 10; ++x) {
	  printf("%d ", square(x)); 
   }

  puts(""); 


} // end main()


int square(int y) {
  //  y * y;
  int x = y;
  return x * x;
}


