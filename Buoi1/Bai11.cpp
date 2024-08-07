#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm nhập mảng
void inputArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

// Hàm xuất mảng
void outputArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Hàm tìm các số cực tiểu trong mảng
void findLocalMinima(int *arr, int n) {
	if (n < 2) {
		printf("Mang khong co so cuc tieu.\n");
		return;
	}
	int found = 0;
	for (int i = 1; i < n - 1; i++) {
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
			printf("So cuc tieu: %d tai dia chi: %p\n", arr[i], (void*)&arr[i]);
			found = 1;
		}
	}
	if (!found) {
		printf("Mang khong co so cuc tieu.\n");
	}
}

// Hàm xóa phần tử tại vị trí k
void deleteAtPosition(int *arr, int *n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*n)--;
}

// Hàm thêm phần tử x tại vị trí k
void insertAtPosition(int *arr, int *n, int x, int k) {
	if (k < 0 || k > *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = *n; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*n)++;
}

// Hàm chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void moveEvenToFrontOddToEnd(int *arr, int n) {
	int *temp = (int *)malloc(n * sizeof(int));
	int index = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			temp[index++] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			temp[index++] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		arr[i] = temp[i];
	}

	free(temp);
}

// Hàm kiểm tra mảng có chứa chẵn lẻ xen kẽ không
int isAlternatingEvenOdd(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	printf("Nhap vao so luong phan tu cua mang: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return -1;
	}

	inputArray(arr, n);
	printf("Mang da nhap: ");
	outputArray(arr, n);

	// a. Xuất các số cực tiểu trong mảng
	printf("Cac so cuc tieu trong mang:\n");
	findLocalMinima(arr, n);

	// b. Xóa phần tử tại vị trí k
	int k;
	printf("Nhap vi tri k can xoa: ");
	scanf("%d", &k);
	deleteAtPosition(arr, &n, k);
	printf("Mang sau khi xoa phan tu tai vi tri %d: ", k);
	outputArray(arr, n);

	// c. Thêm phần tử x tại vị trí k
	int x;
	printf("Nhap gia tri x can them: ");
	scanf("%d", &x);
	printf("Nhap vi tri k can them: ");
	scanf("%d", &k);
	insertAtPosition(arr, &n, x, k);
	printf("Mang sau khi them phan tu %d tai vi tri %d: ", x, k);
	outputArray(arr, n);

	// d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
	moveEvenToFrontOddToEnd(arr, n);
	printf("Mang sau khi chuyen so chan len dau va so le xuong cuoi: ");
	outputArray(arr, n);

	// e. Kiểm tra mảng có chứa chẵn lẻ xen kẽ không
	if (isAlternatingEvenOdd(arr, n)) {
		printf("Mang chua cac so chan le xen ke.\n");
	}
	else {
		printf("Mang khong chua cac so chan le xen ke.\n");
	}

	free(arr);
	system("pause");
	return 0;
}
