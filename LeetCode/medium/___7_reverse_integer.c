#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../help.h"

int reverse(int x) {
    int result = 0, tail;
    while (x != 0) {
        tail = x % 10;
        x = x / 10;

        if (result > 214748364 || (result == 214748364 && tail > 7))
            return 0;

        if (result < -214748364 || (result == -214748364 && tail < -8))
            return 0;

        result = result * 10 + tail;
    }

    return result;
}

int main() {
    int x = 2147483647;

    printf("%d\n", 2 * x);
    printf("%ld\n", reverse(x));
}
