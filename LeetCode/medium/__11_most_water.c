#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxArea(int* height, int heightSize) {
    int i, j, tmp,
        highest = 0,
        max = 0;

    for (i = 0; i < heightSize; i++) {
        if (height[i] < highest) {
            continue;
        }
        highest = height[i];

        for (j = i+1; j < heightSize; j++) {
            tmp = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if (tmp > max) {
                max = tmp;
            }
        }
    }

    return max;
}

int main() {
    int nums[] = {1, 1};
    int result = maxArea(nums, 2);
    printf("%d\n", result);

    return 0;
}
