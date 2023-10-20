//学号：8008121268
//姓名：贺阳明
#include <stdio.h>
#include <stdlib.h>

int getsum(int left, int right, int *arr) {
    if (left == right) {
        if (!(arr[left] % 2))
            return 1;
        return 0;
    }
    return getsum(left, (left + right) / 2, arr) + getsum((left + right) / 2 + 1, right, arr);
}

int main() {
    int num;
    scanf("%d", &num);
    int *arr = (int*)malloc(sizeof(int) * num);
    for (int i = 0;i < num ;i ++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", getsum(0, num-1, arr));
    printf("学号:8008121268\n");
    printf("姓名:贺阳明\n");
    return 0;
}