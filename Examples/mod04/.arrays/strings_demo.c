// Demo a couple strings functions
#include <stdio.h>
#include <strings.h>

int main(void) {
    char str[80];

    strcpy(str, "Hello ");
    strcat(str, "World.");
    strcat(str, "Goodbye!\n");
    
    puts(str);
}