#include <stdio.h>

int main() {
    int arr[100], size, index, newValue;
    printf("Nhap kich thuoc cua mang toi da 100: ");
    scanf("%d", &size);

    if (size < 0 || size > 100) {
        printf("Kich thuoc kh hop le!\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vtri can sua (0 den %d): ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[index] = newValue;

    printf("Mang sau khi sua:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

