#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle) {
	int main_len = strlen(haystack);
    int sub_len = strlen(needle);
    int i = 0, j;

    for (i = 0; i < main_len - sub_len + 1; i++) {
        for (j = 0; j < sub_len; j++) {
            if (haystack[i+j] != needle[j]) {
                break;
            }
        }

        if (j == sub_len) {
            return i;
        }
    }

    return -1;
}

int main() {
    printf("%d\n", strStr("a", "a"));
    printf("%d\n", strStr("arb", "b"));
    printf("%d\n", strStr("sadbutsad", "sad"));
    printf("%d\n", strStr("leetcode", "leeto"));
    printf("%d\n", strStr("abcdef", "f"));
}
