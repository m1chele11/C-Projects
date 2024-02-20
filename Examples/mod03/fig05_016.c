// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

// function prototypes
void useLocal(void); 
void useStaticLocal(void);
void useGlobal(void); 

int x = 1;  //global variable

int main(void) {
    int x = 5;	// local variable to main

    printf("local x in outer scope of main is %d\n", x);

    { // start new scope
	int x = 7; // local variable to new scope

	printf("local x in inner scope of main is %d\n", x);
    } // end new scope

    printf("local x in outer scope of main is %d\n", x);
    useLocal();  // useLocal has automatic local x
    useStaticLocal();  // useStaticLocal as static local x
    useGlobal(); // uses lgobal x
    useLocal();  // useLocal reinitializes automatic local x
    useStaticLocal(); // static local x retains prior value 
    useGlobal(); // global x also retains its value

    printf("\nlocal x in main is %d\n", x);

} // end main()

// useLocal initializes local variable x during each call
void useLocal(void) {
    int x = 25;  // initialized each time useLocal is called

    printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
    ++x;
    printf("local x in useLocal is % d before exiting useLocal\n", x);
} // end useLocal

// useStaticLocal initializes static local variable x only the first time
// the function is called; value of x is saved between calls to this function
void useStaticLocal(void) {
    
    // initialized once
    static int x = 50;

    printf("\nlocal static x is %d on entering useStaticLocal\n", x);
    ++x;
    printf("local static x is %d on exiting useStaticLocal\n", x);
}

// function useGlobal kmodifies global variable x during each call
void useGlobal(void) {
	
	printf("\nglobal x is %d on entering useGlobal\n", x);
	x *= 10;
	printf("global x is %d on exiting useGlobal\n", x);
}




