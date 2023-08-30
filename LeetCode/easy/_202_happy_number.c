#include <stdio.h>
#include <stdbool.h>

int squareSum(int n) {
    int sum = 0, tmp;
    while (n >= 10) {
        tmp = n % 10;
        n = n / 10;
        sum += tmp*tmp;
    }
    sum += n*n;
    return sum;
}

bool isHappy(int n) {
    int record[100] = {0};
    int sum = 0;

    while (true) {
        sum = squareSum(n);
        if (sum == 1)
            return true;

        if (sum < 100) {
            if (record[sum]) {
                break;
            }
            record[sum] = 1;
        }

        n = sum;
    }

    return false;
}

int main() {
    int n = 2;
    printf("%d\n", isHappy(n));
    return 0;
}
