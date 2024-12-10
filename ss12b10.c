#include <stdio.h>

#define MAX 100

// Nhap gia tri cho mang
void nhapMang(int arr[], int* n) {
    printf("Nhap so phan tu can nhap (toi da %d): ", MAX);
    scanf("%d", n);
    if (*n > MAX) {
        printf("So phan tu vuot qua gioi han!\n");
        *n = 0;
        return;
    }
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// In gia tri cac phan tu cua mang
void inMang(int arr[], int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Them mot phan tu vao vi tri chi dinh
void themPhanTu(int arr[], int* n, int viTri, int giaTri) {
    if (*n >= MAX) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    (*n)++;
}

// Sua mot phan tu o vi tri chi dinh
void suaPhanTu(int arr[], int n, int viTri, int giaTri) {
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[viTri] = giaTri;
}

// Xoa mot phan tu o vi tri chi dinh
void xoaPhanTu(int arr[], int* n, int viTri) {
    if (viTri < 0 || viTri >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Sap xep mang theo thu tu tang dan
void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Sap xep mang theo thu tu giam dan
void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Tim kiem tuyen tinh
int timKiemTuyenTinh(int arr[], int n, int giaTri) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            return i;
        }
    }
    return -1;
}

// Tim kiem nhi phan
int timKiemNhiPhan(int arr[], int n, int giaTri) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == giaTri) {
            return mid;
        } else if (arr[mid] < giaTri) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX], n = 0, luaChon, viTri, giaTri;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri can them: ");
                scanf("%d", &giaTri);
                themPhanTu(arr, &n, viTri, giaTri);
                break;
            case 4:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri moi: ");
                scanf("%d", &giaTri);
                suaPhanTu(arr, n, viTri, giaTri);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                xoaPhanTu(arr, &n, viTri);
                break;
            case 6:
                printf("Chon kieu sap xep (1: Tang dan, 2: Giam dan): ");
                int kieuSapXep;
                scanf("%d", &kieuSapXep);
                if (kieuSapXep == 1) {
                    sapXepTangDan(arr, n);
                } else if (kieuSapXep == 2) {
                    sapXepGiamDan(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                printf("Chon phuong phap tim kiem (1: Tuyen tinh, 2: Nhi phan): ");
                int kieuTimKiem;
                scanf("%d", &kieuTimKiem);
                if (kieuTimKiem == 1) {
                    int viTriTimThay = timKiemTuyenTinh(arr, n, giaTri);
                    if (viTriTimThay != -1) {
                        printf("Tim thay gia tri %d tai vi tri %d.\n", giaTri, viTriTimThay);
                    } else {
                        printf("Khong tim thay gia tri %d.\n", giaTri);
                    }
                } else if (kieuTimKiem == 2) {
                    int viTriTimThay = timKiemNhiPhan(arr, n, giaTri);
                    if (viTriTimThay != -1) {
                        printf("Tim thay gia tri %d tai vi tri %d.\n", giaTri, viTriTimThay);
                    } else {
                        printf("Khong tim thay gia tri %d.\n", giaTri);
                    }
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

