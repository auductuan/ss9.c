#include <stdio.h>

#define MAX 100

void inputMatrix(int arr[MAX][MAX], int *rows, int *cols) {
    printf("Nhap so dong: ");
    scanf("%d", rows);
    printf("Nhap so cot: ");
    scanf("%d", cols);
    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[MAX][MAX], int rows, int cols) {
    printf("Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void oddElements(int arr[MAX][MAX], int rows, int cols) {
    int sum = 0;
    printf("Cac phan tu le: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                sum += arr[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", sum);
}

void borderElements(int arr[MAX][MAX], int rows, int cols) {
    int product = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", arr[i][j]);
                product *= arr[i][j];
            }
        }
    }
    printf("\nTich cac phan tu bien: %d\n", product);
}

void diagonalMain(int arr[MAX][MAX], int rows, int cols) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void diagonalSecondary(int arr[MAX][MAX], int rows, int cols) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", arr[i][cols - i - 1]);
    }
    printf("\n");
}

void maxSumRow(int arr[MAX][MAX], int rows, int cols) {
    int maxSum = 0, rowIndex = -1;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
            rowIndex = i;
        }
    }
    printf("Dòng có t?ng giá tr? l?n nh?t là dòng %d v?i t?ng là %d\n", rowIndex + 1, maxSum);
}

int main() {
    int arr[MAX][MAX], rows, cols, choice;
    
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputMatrix(arr, &rows, &cols);
                break;
            case 2:
                printMatrix(arr, rows, cols);
                break;
            case 3:
                oddElements(arr, rows, cols);
                break;
            case 4:
                borderElements(arr, rows, cols);
                break;
            case 5:
                diagonalMain(arr, rows, cols);
                break;
            case 6:
                diagonalSecondary(arr, rows, cols);
                break;
            case 7:
                maxSumRow(arr, rows, cols);
                break;
            case 8:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 8);

    return 0;
}

