#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int titleToNumber(char * columnTitle) {
    int len = strlen(columnTitle);
    int num = 0;

    for (int i = len-1; i >= 0; i--) {
        num = num + (columnTitle[i] - 64) * pow(26, len-i-1);
    }

    return num;
}

int main() {
    char *columnTitle1 = "A", *columnTitle2 = "B", *columnTitle3 = "AB";

    printf("%d\n", titleToNumber(columnTitle1));
    printf("%d\n", titleToNumber(columnTitle2));
    printf("%d\n", titleToNumber(columnTitle3));

    return 0;
}
