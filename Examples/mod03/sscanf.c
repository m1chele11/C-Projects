// sample demonstrating the use fo sscanf() with getf()
#include <stdio.h>



int main(void) {
    char userInput[256];

    int a = 0, b = 0, c = 0;
    char code;
    int ct = 0;
    
    puts("Payroll format: CODE INT1 INT2 INT3");
    printf("Enter a payroll info: ");
    gets( userInput );
    ct = sscanf(userInput, "%c %d %d %d", &code, &a, &b, &c);
    printf("ARGS: %d, A:%d B:%d C:%d\n", ct, a, b, c);
}
