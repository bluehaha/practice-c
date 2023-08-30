#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int i;
    char tmp;

    for (i = 0; i < sSize/2; i++) {
        tmp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = tmp;
    }
}

int main() {
    char s[] = "123456789abcdefg";
    int sSize = strlen(s);
    reverseString(s, sSize);
    printf("%d %s\n", sSize, s);
    return 0;
}
