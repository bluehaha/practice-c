#include <stdio.h>
#include <string.h>

int map(char cha) {
    switch ((int) cha) {
        case (int) 'I':
            return 1;
        case (int) 'V':
            return 5;
        case (int) 'X':
            return 10;
        case (int) 'L':
            return 50;
        case (int) 'C':
            return 100;
        case (int) 'D':
            return 500;
        case (int) 'M':
            return 1000;
    }
}

int romanToInt(char * s) {
    int length = strlen(s);
    int sum = 0;
    int i, curr, next;

    for (i = 0; i < length-1; i++) {
        curr = map(s[i]);
        next = map(s[i+1]);

        if (next > curr) {
            sum -= curr;
        } else {
            sum += curr;
        }
    }

    return sum + map(s[i]);
}


int main() {
    printf("%d\n", romanToInt("III"));
    printf("%d\n", romanToInt("IV"));
    printf("%d\n", romanToInt("MCMXCIV"));
    /* printf("%d\n", map('I')); */
}
