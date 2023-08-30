#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int dividend, int divisor){
    if (dividend == 0)
        return 0;

    int revert = 0;

    if (dividend < 0 && divisor > 0) {
        divisor = -divisor;
        revert = 1;
    }

    if (dividend > 0 && divisor < 0) {
        dividend = -dividend;
        revert = 1;
    }

    long i = -1;
    long calculate = 0;
    if (divisor > 0) {
        if (divisor == 1) {
            i = (long) dividend;
        } else {
            while (calculate <= dividend) {
                calculate += divisor;
                i++;
            }
        }
    } else {
        if (divisor == -1) {
            i = -((long) dividend);
        } else {
            while (calculate >= dividend) {
                calculate += divisor;
                i++;
            }
        }
    }

    i = revert == 0 ? i : -i;

    if (i > 2147483647)
        return 2147483647;

    if (i < -2147483648)
        return -2147483648;

    return i;
}

int main() {
    /* printf("%d %d => %d\n", 10, 3, divide(10, 3)); */
    printf("%d %d => %d\n", 7, -3, divide(7, -3));
    printf("%d %d => %d\n", -1, -1, divide(-1, -1));
    printf("%d %d => %d\n", -2, -1, divide(-2, -1));
    printf("%d %d => %d\n", -7, -3, divide(-7, -3));
    printf("%d %d => %d\n", 7, 1, divide(7, 1));
    printf("%d %d => %d\n", -2147483648, -1, divide(-2147483648, -1));

    return 0;
}
