#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char * s) {
    int hash[26] = {0};
    int i, length = strlen(s);

    for (i = 0; i < length; i++) {
        hash[s[i] - 'a']++;
    }

    for (i = 0; i < length; i++) {
        if (hash[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    char string[] = "leetcode";
    int result = firstUniqChar(string);
    printf("%d\n", result);
    return 0;
}
