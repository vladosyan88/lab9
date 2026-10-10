#include <stdio.h>
#define LIMIT 5
int main() {
    int a[LIMIT][LIMIT], b[LIMIT][LIMIT];
    int rows, cols;
    
    printf("Enter rows and cols (1..5)\n");
    if (scanf("%d%d", &rows, &cols) != 2) {
        printf("Input error\n");
        return 1;
    }
    
    if (rows < 1 || rows > LIMIT || cols < 1 || cols > LIMIT) {
        printf("Size error\n");
        return 1;
    }
    
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            if (scanf("%d", &a[row] [col]) != 1){
                printf("Input error\n");
                return 1;
            }
            if (a[row][col] < -1000 || a[row][col] > 1000) {
                printf("Value error\n");
                return 1;
            }
        }
    }
    printf("Matrix:\n");
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            printf("%6d", a[row][col]);
        }
        printf("\n");
    }
    printf("Column sums:\n");
    for (int col = 0; col < cols; col++){
        long long colSum = 0;
        for (int row = 0; row < rows; row++){
            colSum += a[row][col];
        }
        printf("Col %d sum = %lld\n", col, colSum);
    }
    long long minSum = 0;
    int minRow = 0;
    for (int col = 0; col < cols; col++){
        minSum += a[0][col];
    }
    for (int row = 1; row < rows; row++){
        long long rowSum = 0;
        for (int col = 0; col < cols; col++){
            rowSum += a[row][col];
        }
        if (rowSum < minSum){
            minSum = rowSum;
            minRow = row;
        }
    }
    printf("Min row index = %d, sum = %lld\n", minRow, minSum);
    return 0;
}

