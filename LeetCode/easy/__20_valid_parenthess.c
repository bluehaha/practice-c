#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char * s) {
    int len = strlen(s);
    char queue[len];
    int point = 0;

    for (int i = 0; i < len; i++) {
        /* printf("%c\n", s[i]); */
        switch ((int) s[i]) {
            case (int) '(':
            case (int) '[':
            case (int) '{':
                queue[point] = s[i];
                point++;
                break;
            case (int) ')':
                if (point == 0 || queue[--point] != '(') {
                    return false;
                }
                break;
            case (int) ']':
                if (point == 0 || queue[--point] != '[') {
                    return false;
                }
                break;
            case (int) '}':
                if (point == 0 || queue[--point] != '{') {
                    return false;
                }
                break;
        }
    }

    return true && point == 0;
}

int main() {
    printf("%d\n", isValid("()"));
    printf("%d\n", isValid("()[]{}"));
    printf("%d\n", isValid("(]"));
    printf("%d\n", isValid("([)]"));
    printf("%d\n", isValid("("));
    printf("%d\n", isValid("]"));
}
