#include <stdio.h>
#include <stdlib.h>

int n;
int *coins;
int *value;

int getValue(int amount) {
    int min = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        if (amount == coins[i]) {
            value[amount] = 1;
            return 1;
        } else if (amount > coins[i]) {
            if (value[amount] > 0)
                return value[amount];
            int var = getValue(amount - coins[i]) + 1;
            if (var == 0)
                continue;
            min = min < var ? min : var;
        }
    }
    value[amount] = min == 0x7fffffff ? -1 : min;
    return value[amount];
}

int main() {
    int amount;
    scanf("%d %d", &n, &amount);
    coins = (int *)calloc(n, sizeof(int));
    value = (int *)calloc(amount, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("%d\n", getValue(amount));
    return 0;
}