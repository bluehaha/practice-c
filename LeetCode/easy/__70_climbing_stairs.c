#include <stdio.h>

int climbStairs(int n) {
    static int cache[46] = {0};

    if (n <= 2) {
        return n;
    }

    if (cache[n] != 0) {
        return cache[n];
    }

    return cache[n] = climbStairs(n-1) + climbStairs(n-2);
}


int main() {
    printf("%d\n", climbStairs(0));
    printf("%d\n", climbStairs(1));
    printf("%d\n", climbStairs(2));
    printf("%d\n", climbStairs(3));
    printf("%d\n", climbStairs(4));
}
