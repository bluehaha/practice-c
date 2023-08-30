#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isAnagram(char * s, char * t) {
    int head1[26] = {0};
    int head2[26] = {0};
    int i;

    for (i = 0; i < strlen(s); i++) {
        head1[s[i]-'a']++;
    }
    for (i = 0; i < strlen(t); i++) {
        head2[t[i]-'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (head1[i] != head2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char *s = "anagram";
    char *t = "nagaram";

    bool result = isAnagram(s, t);

    printf("%d\n", result);
}
