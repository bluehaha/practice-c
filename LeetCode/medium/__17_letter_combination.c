#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../help.h"

char *(MAPPING[]) = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void assignChar(char *digits, int digitLen, int digitIndex, char **result, int returnSize) {
    if (digitIndex >= digitLen) {
        return;
    }

    char *mappingString = MAPPING[digits[digitIndex]-'2'];
    int length = strlen(mappingString);

    for (int i = 0; i < length; i++) {
        char cha = mappingString[i];
        int block = returnSize/length;
        for (int j = 0; j < block; j++) {
            result[i * block + j][digitIndex] = cha;
        }
        assignChar(
            digits,
            digitLen,
            digitIndex+1,
            result + i * block,
            block
        );
    }
}

char ** letterCombinations(char * digits, int* returnSize) {
    int digitLen = strlen(digits);
    if (digitLen == 0) {
        char **result = NULL;
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;

    for (int i = 0; i < digitLen; i++) {
        if (digits[i] == '7' || digits[i] == '9')
            *returnSize = *returnSize * 4;
        else
            *returnSize = *returnSize * 3;
    }

    char **result = (char **) malloc(sizeof(char*) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = (char *) malloc(sizeof(char) * (digitLen+1));
        memset(result[i], 0, sizeof(char) * (digitLen+1));
    }

    assignChar(digits, digitLen, 0, result, *returnSize);

    return result;
}

int main() {
    char digits[] = "";
    int returnSize;
    char** result = letterCombinations(digits, &returnSize);

    printf("returnSize: %d\n", returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
