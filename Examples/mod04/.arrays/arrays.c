// Testing printing out array locations.
#include <stdio.h>
#define ARRAY_LIMIT 5

int main(void) {
    int iArray[] = { 1, 2, 3, 4, 5 };
    
    char myString[] = "Hello, everyone\n";
    int iArray2[ARRAY_LIMIT];

    printf("Contents of iArray\n");
    for (size_t i = 0; i < 5; i++) {
        // iArray[i] *= 10;
        printf("Cell: %zu  Value: %4d @  %12p\n", i, iArray[i], &iArray[i]);
    }

    // printf("Contents of myString\n");
    // for (size_t i = 0; i < sizeof(myString); i++) {
    //     printf("Cell: %zu  Char: %c  Value: %4d @  %12p\n", i, myString[i], myString[i], &myString[i]);
    // }

    // printf("Contents of iArray2\n");
    // for (size_t i = 0; i < sizeof(iArray2); i++) {
    //     printf("Cell: %zu  Value: %4d @  %12p\n", i, iArray2[i], &iArray2[i]);
    // }

    
}



/*
    int i = 0;
    while (myString[i])
        i++;
    printf("%d\n", i);

    printf("Cell: %3zu  Value: %4d Char: %c @  %12p\n", i, myString[i], myString[i], &myString[i]);
    printf("Array by name: %15p\n", myString);
    printf("Array by name: %15p\n", &myString);
    printf("Array by name: %15p\n", &myString[0]);




*/