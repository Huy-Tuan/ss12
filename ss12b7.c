#include <stdio.h>

void nhapMaTran(int soHang, int soCot, int maTran[100][100]) {
    printf("Nhap cac gia tri cho ma tran (%d x %d):\n", soHang, soCot);
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}

void inMaTran(int soHang, int soCot, int maTran[100][100]) {
    printf("Ma tran da nhap:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;
    int maTran[100][100];

    printf("Nhap so hang: ");
    scanf("%d", &soHang);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);

    if (soHang > 100 || soCot > 100) {
        printf("Kich thuoc qua lon. Vui long nhap lai.\n");
        return 1;
    }

    nhapMaTran(soHang, soCot, maTran);
    inMaTran(soHang, soCot, maTran);

    return 0;
}

