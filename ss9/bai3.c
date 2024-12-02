#include <stdio.h>

int main() {
    int arr[100], size, index;
    printf("Nhap so phan tu cua mang toi da 100: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri can xoa (0 den %d): ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Vtri khong hop le\n");
        return 1;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; 

    printf("Mang sau khi xóa:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

