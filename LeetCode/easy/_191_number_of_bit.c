#include <stdio.h>
#include <stdlib.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        count = count + (n & 1);
        n = n >> 1;
    }
    return count;
}

int main() {
    uint32_t a = 11;
    printf("%u\n", hammingWeight(a));
    return 0;
}
