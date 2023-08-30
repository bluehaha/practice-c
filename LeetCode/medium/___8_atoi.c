#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char * s) {
    int i = 0,
        strLength = strlen(s),
        isPositive = 1;
    long result = 0;
    long intMax = 2147483647;
    long intMin = -2147483648;

    while (s[i] == ' ' && i < strLength) {
        i++;
    }

    if (s[i] == '-') {
        isPositive = 0;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    for (; i < strLength; i++) {
        if (s[i] < '0' || s[i] > '9') {
            break;
        }

        result = result * 10 + (s[i] - '0');

        if (isPositive && result > intMax) {
            return intMax;
        }

        if (!isPositive && result > intMax+1) {
            return intMin;
        }
    }

    if (!isPositive) {
        result = -result;
    }
    return result;
}

int main() {
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("-91283472332"));

    return 0;
}
