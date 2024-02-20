// Purpose
// Author: Kurt Seiffert

#include <stdio.h> 

int main(void) {
    printf("Enter two integers, and I will tell you\n");
    printf("the relationships they satisfy.\n");

    int num1;
    int num2;

    scanf("%d %d", &num1, &num2);   // read in two integers

    if (num1 == num2) {
        printf("%d is equal to %d\n", num1, num2);
    } // end equality

    if (num1 != num2) {
        printf("%d is not equal to %d\n", num1, num2);
    } // end not equal

    if (num1 < num2) {
        printf("%d is less than %d\n", num1, num2);
    } // end less than

    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } // end greater than

    if (num1 <= num2) {
        printf("%d is less than or equal to %d\n", num1, num2);
    } // end less than or equal

    if (num1 >= num2) {
        printf("%d is greater than or equal to %d\n", num1, num2);
    } // end greater than or equal


} // end main()




