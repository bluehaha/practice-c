#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfThree(int n){
    if (n < 1)
        return false;

    int remainder;
    while (n != 1) {
        remainder = n % 3;
        n = n / 3;

        if (remainder != 0) {
            return false;
        }
    }

    return n == 1;
}

int main() {
    int n = 0;
    bool result = isPowerOfThree(n);
    printf("%d\n", result);
    return 0;
}
