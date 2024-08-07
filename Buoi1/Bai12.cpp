#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc phân số
typedef struct {
	int tu;
	int mau;
} PhanSo;

// Hàm nhập phân số
void nhapPhanSo(PhanSo *ps) {
	printf("Nhap tu so: ");
	scanf("%d", &ps->tu);
	do {
		printf("Nhap mau so (mau so != 0): ");
		scanf("%d", &ps->mau);
		if (ps->mau == 0) {
			printf("Mau so khong duoc bang 0. Vui long nhap lai.\n");
		}
	} while (ps->mau == 0);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
	printf("%d/%d ", ps.tu, ps.mau);
}

// Hàm nhập mảng phân số
void nhapMangPhanSo(PhanSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan so thu %d:\n", i + 1);
		nhapPhanSo(&arr[i]);
	}
}

// Hàm xuất mảng phân số
void xuatMangPhanSo(PhanSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		xuatPhanSo(arr[i]);
	}
	printf("\n");
}

// Hàm rút gọn phân số
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void rutGonPhanSo(PhanSo *ps) {
	int ucln = gcd(abs(ps->tu), abs(ps->mau));
	ps->tu /= ucln;
	ps->mau /= ucln;
}

// Hàm tìm phân số lớn nhất/nhỏ nhất
PhanSo timPhanSoLonNhat(PhanSo *arr, int n) {
	PhanSo max = arr[0];
	for (int i = 1; i < n; i++) {
		if ((double)arr[i].tu / arr[i].mau >(double)max.tu / max.mau) {
			max = arr[i];
		}
	}
	return max;
}

PhanSo timPhanSoNhoNhat(PhanSo *arr, int n) {
	PhanSo min = arr[0];
	for (int i = 1; i < n; i++) {
		if ((double)arr[i].tu / arr[i].mau < (double)min.tu / min.mau) {
			min = arr[i];
		}
	}
	return min;
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanSoTaiViTri(PhanSo *arr, int *n, int k) {
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
void themPhanSoTaiViTri(PhanSo *arr, int *n, PhanSo x, int k) {
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

int main() {
	int n;
	printf("Nhap vao so luong phan so: ");
	scanf("%d", &n);

	PhanSo *arr = (PhanSo *)malloc(n * sizeof(PhanSo));
	if (arr == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return -1;
	}

	nhapMangPhanSo(arr, n);
	printf("Mang phan so da nhap: ");
	xuatMangPhanSo(arr, n);

	// a. Tìm phân số lớn nhất/nhỏ nhất
	PhanSo max = timPhanSoLonNhat(arr, n);
	PhanSo min = timPhanSoNhoNhat(arr, n);
	printf("Phan so lon nhat: ");
	xuatPhanSo(max);
	printf("\n");
	printf("Phan so nho nhat: ");
	xuatPhanSo(min);
	printf("\n");

	// b. Xóa phần tử tại vị trí k
	int k;
	printf("Nhap vi tri k can xoa: ");
	scanf("%d", &k);
	xoaPhanSoTaiViTri(arr, &n, k);
	printf("Mang sau khi xoa phan so tai vi tri %d: ", k);
	xuatMangPhanSo(arr, n);

	// c. Thêm phần tử x tại vị trí k
	PhanSo x;
	printf("Nhap phan so can them:\n");
	nhapPhanSo(&x);
	printf("Nhap vi tri k can them: ");
	scanf("%d", &k);
	themPhanSoTaiViTri(arr, &n, x, k);
	printf("Mang sau khi them phan so tai vi tri %d: ", k);
	xuatMangPhanSo(arr, n);

	free(arr);
	system("pause");
	return 0;
}
