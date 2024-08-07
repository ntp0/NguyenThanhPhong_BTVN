#include <stdio.h>
#include <stdlib.h>

// Hàm nhập mảng
void nhapMang(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

// Hàm xuất mảng
void xuatMang(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Hàm tính và xuất kết quả các phép chia của phần tử mảng a cho phần tử mảng b
void chiaMang(int *a, int *b, int n) {
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			printf("Phan tu thu %d: Loi chia cho 0\n", i + 1);
		}
		else {
			printf("Phan tu thu %d: %d / %d = %.2f\n", i + 1, a[i], b[i], (float)a[i] / b[i]);
		}
	}
}

int main() {
	int n;

	printf("Nhap vao kich thuoc cua mang a va b: ");
	scanf("%d", &n);

	int *a = (int *)malloc(n * sizeof(int));
	int *b = (int *)malloc(n * sizeof(int));
	if (a == NULL || b == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return -1;
	}

	// Nhập mảng a
	printf("Nhap cac phan tu cho mang a:\n");
	nhapMang(a, n);

	// Nhập mảng b
	printf("Nhap cac phan tu cho mang b:\n");
	nhapMang(b, n);

	// Xuất mảng a và b
	printf("Mang a da nhap: ");
	xuatMang(a, n);
	printf("Mang b da nhap: ");
	xuatMang(b, n);

	// Tính và xuất kết quả các phép chia của phần tử mảng a cho phần tử mảng b
	printf("Ket qua cac phep chia:\n");
	chiaMang(a, b, n);

	free(a);
	free(b);
	system("pause");
	return 0;
}
