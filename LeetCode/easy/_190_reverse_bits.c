#include <stdio.h>
#include <stdlib.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t a[32] = {0};
    int i = 0;
    while (n >= 2) {
        a[i] = n % 2;
        n = n / 2;
        i++;
    }
    a[i] = n;

    n = a[0];
    for (i = 1; i < 32; i++) {
        n = n * 2 + a[i];
    }
    return n;
}

void printBit(uint32_t n) {
}

int main() {
    uint32_t a = 43261596;
    printf("%u\n", reverseBits(a));
    return 0;
}
