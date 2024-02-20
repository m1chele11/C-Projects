// Purpose to demonstrate processing standard in for various functions
// Author: Kurt Seiffert

#include <stdio.h> 

void funcA(void);
void funcB(void);
void funcC(void);
void funcD(void);

int main(void) {

    puts("Beginning input");

    char nextChar;
    while ((nextChar = getchar()) != EOF) {
        switch(nextChar) {
            case 'A': // A types take one integer
                funcA();
                break;
            case 'B': // B types take two integers
                funcB();
                break;
            case 'C':  // C types take integer and float
                funcC();
                break;
            case 'D': // D types take integer and char
                funcD();
                break;
            case 'Q':  // user indicates to quit
                goto end_while;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default: 
                printf("%c is not a recognized type.\n", nextChar);
        } // end switch

    } // end while
    end_while: ;
    puts("End main.");
} // end main()

void funcA(void) {
    int x;
    scanf("%d", &x);
    printf("One integer found: %d\n", x);
}

void funcB(void) {
    int x,y;
    scanf("%d %d", &x, &y);
    printf("Two integers found %d and %d\n", x, y);
}

void funcC(void) {
    int x;
    float y;
    scanf("%d %f", &x, &y);
    printf("Integer %d and float %f found.\n", x, y);
}

void funcD(void) {
    int x;
    char c;
    scanf("%d %c", &x, &c);
    printf("Integer %d and character %c found.\n", x, c);
}



