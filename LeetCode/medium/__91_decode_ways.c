#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(char * s, int * map) {
    if (s[0] == 0)
        return 1;
    if (s[0] == '0')
        return 0;

    int length = strlen(s);
    if (map[length])
        return map[length];

    int count = helper(s+1, map);

    if ((s[0] == '1' && s[1] != 0)
        || (s[0] == '2' && s[1] <= '6' && s[1] >= '0')
    )
        count += helper(s+2, map);

    return map[length] = count;
}

int numDecodings(char * s){
    int * map = malloc(sizeof(int) * 101);
    memset(map, 0, sizeof(int) * 101);
    return helper(s, map);
}

int main() {
    /* printf("%d\n", numDecodings("1")); */
    /* printf("%d\n", numDecodings("12")); */
    /* printf("%d\n", numDecodings("226")); */
    /* printf("%d\n", numDecodings("06")); */
    /* printf("%d\n", numDecodings("106")); */
    /* printf("%d\n", numDecodings("1166")); */
    /* printf("%d\n", numDecodings("116600")); */
    /* printf("%d\n", numDecodings("2611055971756562")); */
    printf("%d\n", numDecodings("111111111111111111111111111111111111111111111"));
}
