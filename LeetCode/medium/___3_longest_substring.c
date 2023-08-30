#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../help.h"

int findRepeat(char *s, int startIndex, int endIndex) {
    for (int i = startIndex; i < endIndex; i++) {
        if (s[i] == s[endIndex])
            return i;
    }
    return -1;
}

int lengthOfLongestSubstring(char * s) {
    int startIndex = 0,
        endIndex = 0,
        strLength = strlen(s),
        maxLength = strLength == 0 ? 0 : 1,
        repeatIndex = -1;

    for (int i = 1; i < strLength; i++) {
        endIndex++;

        repeatIndex = findRepeat(s, startIndex, endIndex);

        if (repeatIndex == -1) {
            maxLength = maxLength < endIndex - startIndex + 1 ? endIndex - startIndex + 1 : maxLength;
        } else {
            startIndex = repeatIndex + 1;
        }
    }

    return maxLength;
}

int main() {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));

    return 0;
}
