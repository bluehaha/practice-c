#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fizzBuzzString = "FizzBuzz";
char *fizz = "Fizz";
char *buzz = "Buzz";

char ** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    int i;
    char **result = (char**) malloc(n * sizeof(char*));

    for (i = 0; i < n; i++) {
        int number = i + 1;
        if (number % 15 == 0) {
            result[i] = fizzBuzzString;
        } else if (number % 3 == 0) {
            result[i] = fizz;
        } else if (number % 5 == 0) {
            result[i] = buzz;
        } else {
            result[i] = (char*) malloc(5 * sizeof(char));
            sprintf(result[i], "%d", number);
        }
    }
    return result;
}

int main() {
    int n = 15;
    int returnSize = 0;
    char** result = fizzBuzz(n, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
