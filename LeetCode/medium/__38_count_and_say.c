#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * countAndSay(int n) {
    if (n == 1)
        return "1";

    char* preString = countAndSay(n - 1);
    int len = strlen(preString);
    char *string = (char *)malloc(sizeof(char) * (len * 2 + 1));
    memset(string, 0, sizeof(char) * (len * 2 + 1));

    int ptr = 0, count = 0;
    for (int i = 0; i < len; i++) {
        count++;
        if (preString[i] != preString[i+1]
            || i == len - 1
        ) {
            string[ptr++] = count + '0';
            string[ptr++] = preString[i];
            count = 0;
        }
    }

    return string;
}

int main() {
    printf("%s\n", countAndSay(1));
    printf("%s\n", countAndSay(2));
    printf("%s\n", countAndSay(3));
    printf("%s\n", countAndSay(4));
    printf("%s\n", countAndSay(5));
}
