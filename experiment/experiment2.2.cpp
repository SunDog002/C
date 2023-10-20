#include <stdio.h>
#include <stdlib.h>

int n;
int *coins;

int getValue(int amount) {
    int min = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        if (amount == coins[i]) {
            return 1;
        } else if (amount > coins[i]) {
            int var = getValue(amount - coins[i]) + 1;
            if (var == 0)
                continue;
            min = min < var ? min : var;
        }
    }
    return min == 0x7fffffff ? -1 : min;
}

int main() {
    int amount;
    scanf("%d %d", &n, &amount);
    coins = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("%d\n", getValue(amount));
    return 0;
}