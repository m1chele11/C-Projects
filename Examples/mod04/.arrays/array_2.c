// Demo pass by reference
#include <stdio.h>

void f1(int x);         // function takes integer
void f2(int x[]);       // function takes array argument
// void f3( const x[]);
void f4(int x[], size_t size);

int a = 10;
int b[] = {1, 2, 3, 4, 5};

int main(void) {
    printf("Main a: %d\n", a);
    f1(a);
    printf("Main a: %d\n", a);

    // printf("Main array: %d\n", b[0]);
    // f2(b);
    // printf("Main array: %d\n", b[0]);

    // printf("Main array: %d\n", b[0]);
    // f3(b);
    // printf("Main array: %d\n", b[0]);
    // f4(b, sizeof(b)/sizeof(b[0]));
}



void f1(int x) {
    printf("F1 a: %d\n", x);
    x++;
    printf("F1 a: %d\n", x);
}

void f2(int x[]) {
    printf("F2 a: %d\n", x[0]);
    x[0]++;
    printf("F2 a: %d\n", x[0]);
}

// void f3(const int x[]) {
//     printf("F3 a: %d\n", x[0]);
//     x[0]++;
//     printf("F3 a: %d\n", x[0]);
// }

void f4(int x[], size_t size) {
    printf("Size of array: %zu\n", size);
    for (size_t i = 0; i < size; i++) {
        printf("Index: %zu Value: %d\n", i, x[i]);
    }
}