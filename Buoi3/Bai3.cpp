#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Hàm tạo ma trận ngẫu nhiên
void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = min + rand() % (max - min + 1);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính tổng từng dòng
void tongTungDong(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int tong = 0;
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		printf("Tong dong %d: %d\n", i, tong);
	}
}

// Hàm xuất phần tử lớn nhất trên từng cột
void maxTrenTungCot(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Max cot %d: %d\n", j, max);
	}
}

// Hàm xuất các phần tử trên biên
void phanTuBien(int a[MAX][MAX], int m, int n) {
	// Biên trên
	for (int j = 0; j < n; j++) {
		printf("%d ", a[0][j]);
	}
	// Biên phải
	for (int i = 1; i < m; i++) {
		printf("%d ", a[i][n - 1]);
	}
	// Biên dưới
	if (m > 1) {
		for (int j = n - 2; j >= 0; j--) {
			printf("%d ", a[m - 1][j]);
		}
	}
	// Biên trái
	if (n > 1) {
		for (int i = m - 2; i > 0; i--) {
			printf("%d ", a[i][0]);
		}
	}
	printf("\n");
}

// Hàm xuất các phần tử cực đại
void phanTuCucDai(int a[MAX][MAX], int m, int n) {
	int isMax;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			isMax = 1;
			if (i > 0 && a[i][j] < a[i - 1][j]) isMax = 0;
			if (i < m - 1 && a[i][j] < a[i + 1][j]) isMax = 0;
			if (j > 0 && a[i][j] < a[i][j - 1]) isMax = 0;
			if (j < n - 1 && a[i][j] < a[i][j + 1]) isMax = 0;
			if (isMax) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm xuất các phần tử hoàng hậu
void phanTuHoangHau(int a[MAX][MAX], int m, int n) {
	int isQueen = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			isQueen = 1;
			for (int k = 0; k < m; k++) {
				if (k != i && a[k][j] >= a[i][j]) {
					isQueen = 0;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (k != j && a[i][k] >= a[i][j]) {
					isQueen = 0;
					break;
				}
			}
			if (isQueen) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm xuất các phần tử điểm yên ngựa
void phanTuDiemYenNgua(int a[MAX][MAX], int m, int n) {
	int isSaddle = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			isSaddle = 1;
			for (int k = 0; k < m; k++) {
				if (a[k][j] > a[i][j]) {
					isSaddle = 0;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (a[i][k] < a[i][j]) {
					isSaddle = 0;
					break;
				}
			}
			if (isSaddle) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm xuất dòng chỉ chứa số chẵn
void dongChuaSoChan(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int allEven = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = 0;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d: ", i);
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// Hàm sắp xếp từng dòng theo thứ tự tăng dần
void sapXepTungDong(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

// Hàm xuất các cột chỉ chứa số lẻ
void cotChuaSoLe(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int allOdd = 1;
		for (int i = 0; i < m; i++) {
			if (a[i][j] % 2 == 0) {
				allOdd = 0;
				break;
			}
		}
		if (allOdd) {
			printf("Cot %d: ", j);
			for (int i = 0; i < m; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// Hàm tìm phần tử lớn nhất trên biên của ma trận
int maxTrenBien(int a[MAX][MAX], int m, int n) {
	int max = a[0][0];
	for (int j = 0; j < n; j++) {
		if (a[0][j] > max) max = a[0][j];
		if (a[m - 1][j] > max) max = a[m - 1][j];
	}
	for (int i = 1; i < m - 1; i++) {
		if (a[i][0] > max) max = a[i][0];
		if (a[i][n - 1] > max) max = a[i][n - 1];
	}
	return max;
}

// Hàm đếm số phần tử có chữ số 2 xuất hiện trong các chữ số của nó
int demSo2(int a[MAX][MAX], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = a[i][j];
			while (num > 0) {
				if (num % 10 == 2) {
					count++;
					break;
				}
				num /= 10;
			}
		}
	}
	return count;
}

// Hàm xuất các phần tử cực tiểu của ma trận
void phanTuCucTieu(int a[MAX][MAX], int m, int n) {
	int min = INT_MAX;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == min) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm sắp xếp các dòng có chỉ số lẻ tăng dần và các dòng có chỉ số chẵn giảm dần
void sapXepDongChanLe(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if (a[i][j] < a[i][k]) {
						int temp = a[i][j];
						a[i][j] = a[i][k];
						a[i][k] = temp;
					}
				}
			}
		}
		else {
			for (int j = 0; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if (a[i][j] > a[i][k]) {
						int temp = a[i][j];
						a[i][j] = a[i][k];
						a[i][k] = temp;
					}
				}
			}
		}
	}
}

// Hàm sắp xếp các cột có chỉ số lẻ giảm dần và các cột có chỉ số chẵn tăng dần
void sapXepCotChanLe(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < m - 1; i++) {
				for (int k = i + 1; k < m; k++) {
					if (a[i][j] > a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
			}
		}
		else {
			for (int i = 0; i < m - 1; i++) {
				for (int k = i + 1; k < m; k++) {
					if (a[i][j] < a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
			}
		}
	}
}

// Hàm kiểm tra ma trận có giảm dần theo cả dòng và cột
int kiemTraZicZac(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] <= a[i][j + 1]) return 0;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m - 1; i++) {
			if (a[i][j] <= a[i + 1][j]) return 0;
		}
	}
	return 1;
}

// Hàm liệt kê các dòng chứa toàn số chẵn
void lietKeDongChan(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int allEven = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = 0;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d\n", i);
		}
	}
}

// Hàm liệt kê các dòng chứa giá trị giảm dần
void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int isDescending = 1;
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] <= a[i][j + 1]) {
				isDescending = 0;
				break;
			}
		}
		if (isDescending) {
			printf("Dong %d\n", i);
		}
	}
}

// Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
int giaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
	int count[MAX * MAX] = { 0 };
	int maxCount = 0;
	int maxValue = a[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			count[a[i][j]]++;
			if (count[a[i][j]] > maxCount) {
				maxCount = count[a[i][j]];
				maxValue = a[i][j];
			}
		}
	}
	return maxValue;
}

// Hàm tìm các chữ số xuất hiện nhiều nhất trong ma trận
void giaTriXuatHienNhieuNhatChuSo(int a[MAX][MAX], int m, int n) {
	int digitCount[10] = { 0 };
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num = a[i][j];
			while (num > 0) {
				digitCount[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxDigitCount = 0;
	for (int i = 0; i < 10; i++) {
		if (digitCount[i] > maxDigitCount) {
			maxDigitCount = digitCount[i];
		}
	}
	printf("Chua so xuat hien nhieu nhat:\n");
	for (int i = 0; i < 10; i++) {
		if (digitCount[i] == maxDigitCount) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Hàm liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
	int minSum = INT_MAX;
	int sum[MAX] = { 0 };
	for (int j = 0; j < n; j++) {
		sum[j] = 0;
		for (int i = 0; i < m; i++) {
			sum[j] += a[i][j];
		}
		if (sum[j] < minSum) {
			minSum = sum[j];
		}
	}
	printf("Cac cot co tong nho nhat:\n");
	for (int j = 0; j < n; j++) {
		if (sum[j] == minSum) {
			printf("Cot %d\n", j);
		}
	}
}

// Hàm hoán vị hai cột
void hoanViCot(int a[MAX][MAX], int m, int c1, int c2) {
	for (int i = 0; i < m; i++) {
		int temp = a[i][c1];
		a[i][c1] = a[i][c2];
		a[i][c2] = temp;
	}
}

// Hàm hoán vị hai dòng
void hoanViDong(int a[MAX][MAX], int n, int d1, int d2) {
	for (int j = 0; j < n; j++) {
		int temp = a[d1][j];
		a[d1][j] = a[d2][j];
		a[d2][j] = temp;
	}
}

int main() {
	int m, n;
	printf("Nhap so dong va so cot: ");
	scanf("%d %d", &m, &n);

	int a[MAX][MAX];
	taoMaTran(a, m, n, 0, 99);

	printf("Ma tran:\n");
	xuatMaTran(a, m, n);

	// 1. Xuất các cột chỉ chứa số lẻ
	cotChuaSoLe(a, m, n);

	// 2. Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
	printf("Phan tu lon nhat tren bien: %d\n", maxTrenBien(a, m, n));

	// 3. Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó
	printf("So phan tu co chu so 2: %d\n", demSo2(a, m, n));

	// 4. Xuất các phần tử cực tiểu của ma trận
	printf("Cac phan tu cuc tieu: ");
	phanTuCucTieu(a, m, n);

	// 5. Sắp xếp ma trận sao cho các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
	sapXepDongChanLe(a, m, n);
	printf("Ma tran sau khi sap xep dong chan le:\n");
	xuatMaTran(a, m, n);

	// 6. Sắp xếp ma trận sao cho các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
	sapXepCotChanLe(a, m, n);
	printf("Ma tran sau khi sap xep cot chan le:\n");
	xuatMaTran(a, m, n);

	// 7. Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
	if (kiemTraZicZac(a, m, n)) {
		printf("Ma tran giam dan theo ziczac\n");
	}
	else {
		printf("Ma tran khong giam dan theo ziczac\n");
	}

	// 8. Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
	lietKeDongChan(a, m, n);

	// 9. Liệt kê các dòng chứa giá trị giảm dần
	lietKeDongGiamDan(a, m, n);

	// 10. Tìm giá trị xuất hiện nhiều nhất trong ma trận
	printf("Gia tri xuat hien nhieu nhat: %d\n", giaTriXuatHienNhieuNhat(a, m, n));

	// 11. Tìm các chữ số xuất hiện nhiều nhất trong ma trận
	giaTriXuatHienNhieuNhatChuSo(a, m, n);

	// 12. Liệt kê các cột có tổng nhỏ nhất trong ma trận
	lietKeCotTongNhoNhat(a, m, n);

	// 13. Hoán vị hai cột i và j
	int c1, c2;
	printf("Nhap hai cot can hoan vi: ");
	scanf("%d %d", &c1, &c2);
	hoanViCot(a, m, c1, c2);
	printf("Ma tran sau khi hoan vi cot:\n");
	xuatMaTran(a, m, n);

	// 14. Hoán vị hai dòng k và l
	int d1, d2;
	printf("Nhap hai dong can hoan vi: ");
	scanf("%d %d", &d1, &d2);
	hoanViDong(a, n, d1, d2);
	printf("Ma tran sau khi hoan vi dong:\n");
	xuatMaTran(a, m, n);
	system("pause");
	return 0;
}
