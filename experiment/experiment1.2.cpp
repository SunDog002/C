//学号：8008121268
//姓名：贺阳明
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//初始化棋盘
int** init(int length) {
    printf("输入初始填充坐标:");
    int x, y;
    scanf("%d %d", &x, &y);
    int **map = (int **)malloc(sizeof(int *) * length);
    for (int i = 0; i < length; i++) {
        map[i] = (int *)malloc(sizeof(int) * length);
    }
    map[x][y] = 1;
    return map;
}

int value(int **map, int sX, int sY, int eX, int eY) {
    int value = 0;
    for (int i = sX; i <= eX ; i++) {
        for (int j = sY; j <= eY ; j++) {
            value += map[i][j];
        }
    }
    return value;
}

void function(int **map, int sX, int sY, int eX, int eY, int mX, int mY, int *sign) {
    map[mX][mY] = value(map, sX, sY, mX, mY) > 0 ? map[mX][mY] : *sign;
    map[mX][mY + 1] = value(map, sX, mY + 1, mX, eY) > 0 ? map[mX][mY + 1] : *sign;
    map[mX + 1][mY] = value(map, mX + 1, sY, eX, mY) > 0 ? map[mX + 1][mY] : *sign;
    map[mX + 1][mY + 1] = value(map, mX + 1, mY + 1, eX, eY) > 0 ? map[mX + 1][mY + 1] : *sign;
    (*sign)++;
    if (mX != sX && mY != sY) {
        function(map, sX, sY, mX, mY, (sX + mX) / 2, (sY + mY) / 2, sign);
        function(map, sX, mY + 1, mX, eY, (sX + mX) / 2, (mY + 1 + eY) / 2, sign);
        function(map, mX + 1, sY, eX, mY, (mX + 1 + eX) / 2, (sY + mY) / 2, sign);
        function(map, mX + 1, mY + 1, eX, eY, (mX + 1 + eX) / 2, (mY + 1 + eY) / 2, sign);
    }
}

int main() {
    int k, sign = 2;
    printf("输入棋盘长度(2^k):");
    scanf("%d", &k);
    int **map = init(pow(2, k));
    function(map, 0, 0, pow(2, k) - 1, pow(2, k) - 1, (pow(2, k) - 1) / 2, (pow(2, k) - 1) / 2, &sign);
    for (int i = 0;i < pow(2, k);i++) {
        for (int j = 0;j < pow(2, k); j++) 
            printf("%3d ", map[i][j]);
        printf("\n");
    }
    printf("学号:8008121268\n");
    printf("姓名:贺阳明\n");
    return 0;
}