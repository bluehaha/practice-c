#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char * s) {
    int i;
    int ptr = 0;
    int length = strlen(s);

    for (i = 0; i < length; i++) {
        char cha = s[i];
        if (cha >= 'A' && cha <= 'Z') {
            cha += 32;
        }

        if ((cha >= 'a' && cha <= 'z')
            || (cha >= '0' && cha <= '9')
        ) {
            s[ptr] = cha;
            ptr++;
        }
    }

    int half = ptr/2;
    for (i = 0; i < half; i++) {
        if (s[i] != s[ptr-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char string[] = " ";

    printf("%d\n", isPalindrome(string));
}
