#include <stdio.h>

int getValue(int n, int k) {
    if (k == 0 || n == k) 
        return 1;
    return getValue(n-1, k-1) + getValue(n-1, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", getValue(n, k));
    return 0;
}