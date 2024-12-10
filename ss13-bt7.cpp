#include <stdio.h>

int taoMaTran(int row, int col, int maTran[100][100]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
    return 0;
}
void inMaTran(int row, int col, int maTran[100][100]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int row, col;
    int maTran[100][100];
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    taoMaTran(row, col, maTran);
    inMaTran(row, col, maTran);
    
	return 0;
}

