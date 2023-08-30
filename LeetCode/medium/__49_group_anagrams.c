#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int statistics1[26];
int statistics2[26];

int is_same(char * str1, char * str2) {
    if(strlen(str1) != strlen(str2))
        return 0;

    memset(statistics1, 0, sizeof(int) * 26);
    memset(statistics2, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(str1); i++) {
        statistics1[str1[i] - 'a']++;
        statistics2[str2[i] - 'a']++;
    }

    if (memcmp(statistics1, statistics2, sizeof(int) * 26) == 0)
        return 1;

    return 0;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char *** result = (char ***) malloc(sizeof(char **) * strsSize);
    *returnSize = 0;
    *returnColumnSizes = (int *) malloc(sizeof(int) * strsSize);
    memset(*returnColumnSizes, 0, sizeof(int) * strsSize);

    int * used = (int *) malloc(sizeof(int) * strsSize);
    memset(used, 0, sizeof(int) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        if (used[i] == 1)
            continue;

        result[*returnSize] = (char **) malloc(sizeof(char *) * strsSize);

        result[*returnSize][(*returnColumnSizes)[*returnSize]++] = strs[i];
        for (int j = i+1; j < strsSize; j++) {
            if (used[j] == 1 || is_same(strs[i], strs[j]) == 0)
                continue;

            used[j] = 1;
            result[*returnSize][(*returnColumnSizes)[*returnSize]++] = strs[j];
        }

        (*returnSize)++;
    }

    return result;
}

int main() {
    char *strs[] = {""};
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    char ***result = groupAnagrams(strs, 1, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }
}
