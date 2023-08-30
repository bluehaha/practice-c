#include <stdio.h>

int mySqrt(int x) {
    int half = x / 2;
    int i;
    long pow2;

    if (x <= 1) {
        return x;
    }

    for (i = 1; i <= half; i++) {
        pow2 =  i * i;

        if (pow2 == x) {
            return i;
        }
        if (pow2 > x) {
            return i - 1;
        }
    }
    return i - 1;
}

int main() {
    /* printf("%d\n", mySqrt(0)); */
    /* printf("%d\n", mySqrt(1)); */
    /* printf("%d\n", mySqrt(2)); */
    /* printf("%d\n", mySqrt(4)); */
    /* printf("%d\n", mySqrt(6)); */
    /* printf("%d\n", mySqrt(8)); */
    printf("%d\n", mySqrt(2147483647));
}
