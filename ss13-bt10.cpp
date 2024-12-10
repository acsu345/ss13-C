#include <stdio.h>

void addAllItem(int arr[], int *size) {
    printf("Nhap so phan tu muon nhap: ");
    scanf("%d", size);
    if (*size > 100 || *size < 0) {
        printf("So luong phan tu khong hop le!\n");
        *size = 0;
        return;
    }
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void showItem(int arr[], int size) {
    printf("Mang hien tai: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addItem(int arr[], int *size) {
  
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them: ", *size);
    scanf("%d", &position);
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

void changeItem(int arr[], int size) {
    int index, newValue;
    printf("Nhap vi tri can sua : ", size - 1);
    scanf("%d", &index);
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    arr[index] = newValue;
}

void deleteItem(int arr[], int *size) {
    int deleteIndex;
    printf("Nhap vi tri can xoa (tu 0 den %d): ", *size - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = deleteIndex; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void sapXepGiamDan(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepTangDan(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int size) {
    int item, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &item);

    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            printf("Phan tu %d co vi tri %d\n", item, i);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu %d\n", item);
    }
}

void binarySearch(int arr[], int size) {
    int item;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &item);

    int start = 0, end = size - 1, mid, found = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == item) {
            printf("Phan tu %d co vi tri %d\n", item, mid);
            found = 1;
            break;
        } else if (arr[mid] < item) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu %d\n", item);
    }
}

int main() {
    int arr[100];
    int size = 0;
    int choice;

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
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAllItem(arr, &size);
                break;
            case 2:
                showItem(arr, size);
                break;
            case 3:
                addItem(arr, &size);
                break;
            case 4:
                changeItem(arr, size);
                break;
            case 5:
                deleteItem(arr, &size);
                break;
            case 6:
                printf("   a. Giam dan\n");
                printf("   b. Tang dan\n");
                printf("Chon sap xep (a/b): ");
                char sortChoice;
                scanf(" %c", &sortChoice);
                int a,b; 
                if (sortChoice == a) {
                    sapXepGiamDan(arr, size);
                } else if (sortChoice == b) {
                    sapXepTangDan(arr, size);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 7:
                printf("   a. Tim kiem tuyen tinh\n");
                printf("   b. Tim kiem nhi phan\n");
                printf("Chon tim kiem (a/b): ");
                char searchChoice;
                scanf(" %c", &searchChoice);
                if (searchChoice == a) {
                    linearSearch(arr, size);
                } else if (searchChoice == b) {
                    sapXepTangDan(arr, size);
                    binarySearch(arr, size);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

