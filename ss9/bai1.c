#include <stdio.h>

int main() {
    int arr[100]; 
    int size, currentLength, value, addIndex;
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
    currentLength = size;

    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them: ", size);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > size) {
        printf("Vi tri khong hop le !\n");
        return 1;
    }

    if (addIndex >= currentLength) {
        arr[addIndex] = value;
        currentLength = addIndex + 1; 
    } else {
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        
        arr[addIndex] = value;
        currentLength++; 
    }

    printf("Mang sau khi them:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

