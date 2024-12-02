#include <stdio.h>

#define MAX 100

void inputArray(int arr[], int *size) {
    printf("Nhap so phan tu cua mang (toi da %d): ", MAX);
    scanf("%d", size);
    if (*size <= 0 || *size > MAX) {
        printf("Kich thuoc kh hop le!\n");
        *size = 0;
        return;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Mang trong.\n");
        return;
    }
    printf("Cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *size) {
    if (*size >= MAX) {
        printf("Mang da day khong them phan tu moi.\n");
        return;
    }
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (0 den %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
    printf("Da them phan tu thanh cong.\n");
}

void editElement(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong khong the sua.\n");
        return;
    }
    int position, value;
    printf("Nhap vi tri can sua (0 den %d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    arr[position] = value;
    printf("Da sua phan tu thanh cong.\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Mang rong, khong the xoa.\n");
        return;
    }
    int position;
    printf("Nhap vi tri can xoa (0 den %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Da xoa phan tu thanh cong.\n");
}

int main() {
    int arr[MAX], size = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                addElement(arr, &size);
                break;
            case 4:
                editElement(arr, size);
                break;
            case 5:
                deleteElement(arr, &size);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);

    return 0;
}

