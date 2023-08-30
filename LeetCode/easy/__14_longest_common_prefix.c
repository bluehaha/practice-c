#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * longestCommonPrefix(char ** strs, int strsSize) {
    int minLength = strlen(strs[0]);
    int i, j, tmpLength;
    for (i = 1; i < strsSize; i++) {
        tmpLength = strlen(strs[i]);

        if (minLength > tmpLength) {
            minLength = tmpLength;
        }
    }

    char tmpChar;
    int flag = 0, resultLen = 0;

    for (i = 0; i < minLength; i++) {
        tmpChar = strs[0][i];

        for (j = 1; j < strsSize; j++) {
            if (tmpChar != strs[j][i]) {
                goto br;
            }
        }

        resultLen++;
    }
    br:

    if (resultLen > 0) {
        char *result = (char *) malloc(resultLen+1 * sizeof(char));
        /* strs[0][2] = '\0'; */
        /* printf("%d\n", resultLen); */
        strs[0][resultLen] = 0;
        strcpy(result, strs[0]);
        return result;
    }

    return "";
}

int main() {
    /* char str1[8] = "flower"; */
    /* char str2[8] = "flow"; */
    /* char str3[8] = "flight"; */
    /* char *strs[3] = {str1,str2,str3}; */
    char strs[3][8] = {"flower","flow","flight"};

    /* printf("%s\n", longestCommonPrefix(strs, 3)); */
    printf("%s\n", strs[0]);
}
