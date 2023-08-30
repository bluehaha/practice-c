#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = (int*) malloc((digitsSize+1) * sizeof(int));

    bool doesAddOne = true;
    for (int i = digitsSize-1; i >=0; i--) {
        if (doesAddOne) {
            if (digits[i] == 9) {
                result[i+1] = 0;
            } else {
                result[i+1] = digits[i] + 1;
                doesAddOne = false;
            }
        } else {
            result[i+1] = digits[i];
        }
    }

    if (doesAddOne) {
        result[0] = 1;
        *returnSize = digitsSize +1;
        return result;
    }
    *returnSize = digitsSize;
    return result+1;
}

int main() {
    int a[] = {9};
    int resultSize;
    int *result = plusOne(a, sizeof(a)/sizeof(int), &resultSize);

    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
}
