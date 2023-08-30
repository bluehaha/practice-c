#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../help.h"

char* longestPalindrome(char * s) {
    int strLength = strlen(s),
        maxLength = 0,
        startIndex = 0,
        endIndex = 0;
    int step, tempMaxLength;

    for (int i = 0; i < strLength; i++) {
        step = 1;
        while (i - step >= 0 && i +step < strLength && s[i-step] == s[i+step]) {
            step++;
        }

        tempMaxLength = 1 + (step - 1) * 2;
        if (tempMaxLength > maxLength) {
            maxLength = tempMaxLength;
            startIndex = i - step + 1;
            endIndex = i + step - 1;
        }

        step = 1;
        while (i - step + 1 >= 0 && i + step < strLength && s[i-step+1] == s[i+step]) {
            step++;
        }

        tempMaxLength = (step-1) * 2;
        if (tempMaxLength > maxLength) {
            maxLength = tempMaxLength;
            startIndex = i - step + 2;
            endIndex = i + step - 1;
        }
    }

    char * result = (char *) malloc(sizeof(char) * (maxLength + 1));
    for (int i = startIndex; i <= endIndex; i++) {
        result[i - startIndex] = s[i];
    }
    result[maxLength] = '\0';

    return result;
}

int main() {
    printf("%s\n", longestPalindrome("babad"));
    printf("%s\n", longestPalindrome("cbbd"));

    return 0;
}
