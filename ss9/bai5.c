#include <stdio.h>
#include <stdbool.h>
#define MAX 100

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int arr[MAX], size = 0, choice, value, pos, count;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
                break;
            case 2:
                printf("Cac phan tu dang quan ly: ");
                for (int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            case 3: {
                int sum = 0;
                printf("Cac phan tu chan: ");
                for (int i = 0; i < size; i++)
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        sum += arr[i];
                    }
                printf("\nTong cac phan tu chan: %d\n", sum);
                break;
            }
            case 4: {
                if (size == 0) {
                    printf("Mang rong\n");
                    break;
                }
                int max = arr[0], min = arr[0];
                for (int i = 1; i < size; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Lon nhat: %d, Nho nhat: %d\n", max, min);
                break;
            }
            case 5: {
                int sum = 0;
                printf("Cac phan tu nguyen to: ");
                for (int i = 0; i < size; i++)
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        sum += arr[i];
                    }
                printf("\nTong cac so nguyen to: %d\n", sum);
                break;
            }
            case 6:
                printf("Nhap so can thong ke: ");
                scanf("%d", &value);
                count = 0;
                for (int i = 0; i < size; i++)
                    if (arr[i] == value) count++;
                printf("So lan xuat hien: %d\n", count);
                break;
            case 7:
                if (size >= MAX) {
                    printf("Mang day, khong the them\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri (0 den %d): ", size);
                scanf("%d", &pos);
                if (pos < 0 || pos > size) {
                    printf("Vi tri khong hop le\n");
                    break;
                }
                for (int i = size; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = value;
                size++;
                printf("Them thanh cong\n");
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

