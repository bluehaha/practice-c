#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
   if (n == 0)
       return 1;

   if (n > 0) {
       n = -n;
   } else {
       x = 1/x;
   }

    long currentPow = 0, tmpCurrentPow;
    double result = 1, tmpResult;

    while (currentPow > n) {
        tmpCurrentPow = -1;
        tmpResult = x;

        while (tmpCurrentPow*2+currentPow > n) {
            tmpResult = tmpResult * tmpResult;
            tmpCurrentPow *= 2;
        }

        currentPow += tmpCurrentPow;
        result *= tmpResult;
    }

    return result;
}

int main() {
    double x = 2.1;
    int n = 3;
    double result = myPow(x, n);
    printf("%f\n", result);
}
