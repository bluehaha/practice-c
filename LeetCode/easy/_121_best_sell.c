#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1)
        return 0;

    int profit = 0;
    int tmp;
    for (int i = 0; i < pricesSize-1; i++) {
        for (int j = i+1; j < pricesSize; j++) {
            tmp = prices[j] - prices[i];
            profit = profit < tmp ? tmp : profit;
        }
    }
    return profit;
}


int main() {
    int prices1[] = {7,1,5,3,6,4};
    int prices2[] = {1,2,3,4,5};
    int prices3[] = {7,6,4,3,1};

    printf("%d\n", maxProfit(prices1, 6));
    printf("%d\n", maxProfit(prices2, 5));
    printf("%d\n", maxProfit(prices3, 5));
}
