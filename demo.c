#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demo(int * a) {
    printf("%p\n", a);
}

int main() {
    int a = 1;
    printf("%d\n", a);
    a = a ^ 1;
    printf("%d\n", a);
    a = a ^ 1;
    printf("%d\n", a);
    a = a ^ 1;
    printf("%d\n", a);
}
