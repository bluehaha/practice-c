#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    m--;
    n--;
    int sum = m+n;
    long result = 1;

    if (n > m) {
        int tmp = m;
        m = n;
        n = tmp;
    }

    int bottom = 1;
    for (int i = m+1; i <= sum; i++) {
        result *= i;

        while (bottom <= n && result % bottom == 0) {
            result /= bottom;
            bottom++;
        }
    }

    return result;
}

int main() {
    printf("%d\n", uniquePaths(3, 7));
    printf("%d\n", uniquePaths(51, 9));

    return 0;
}
