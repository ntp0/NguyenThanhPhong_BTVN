#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= (int)sqrt((double)n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Hàm liệt kê các số nguyên tố nhỏ hơn n
void lietKeSoNguyenTo(int *arr, int n) {
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (isPrime(arr[i]) && arr[i] < n) {
			printf("%d ", arr[i]);
			found = true;
		}
	}
	if (!found) {
		printf("Khong co so nguyen to nao nho hon %d trong mang.\n", n);
	}
	else {
		printf("\n");
	}
}

// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
bool isOddDigit(int n) {
	int firstDigit = abs(n);
	while (firstDigit >= 10) {
		firstDigit /= 10;
	}
	return firstDigit % 2 != 0;
}

int tongChuSoDauLe(int *arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (isOddDigit(arr[i])) {
			sum += arr[i];
		}
	}
	return sum;
}

// Hàm liệt kê số lần xuất hiện của các phần tử trong mảng
void lietKeSoLanXuatHien(int *arr, int n) {
	int *visited = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) continue;
		int count = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				count++;
				visited[j] = 1;
			}
		}
		printf("Phan tu %d xuat hien %d lan\n", arr[i], count);
	}
	free(visited);
}

// Hàm sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần
void sapXepChanLe(int *arr, int n) {
	int *chan = (int *)malloc(n * sizeof(int));
	int *le = (int *)malloc(n * sizeof(int));
	int chanCount = 0, leCount = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			chan[chanCount++] = arr[i];
		}
		else {
			le[leCount++] = arr[i];
		}
	}

	// Sắp xếp chẵn tăng dần
	for (int i = 0; i < chanCount - 1; i++) {
		for (int j = i + 1; j < chanCount; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	// Sắp xếp lẻ giảm dần
	for (int i = 0; i < leCount - 1; i++) {
		for (int j = i + 1; j < leCount; j++) {
			if (le[i] < le[j]) {
				int temp = le[i];
				le[i] = le[j];
				le[j] = temp;
			}
		}
	}

	// Ghép lại thành mảng kết quả
	int index = 0;
	for (int i = 0; i < chanCount; i++) {
		arr[index++] = chan[i];
	}
	for (int i = 0; i < leCount; i++) {
		arr[index++] = le[i];
	}

	free(chan);
	free(le);
}

// Hàm tìm dãy con giảm dài nhất trong mảng
void dayConGiamDaiNhat(int *arr, int n) {
	int maxLength = 1;
	int length = 1;
	int startIndex = 0;
	int maxStartIndex = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			length++;
			if (length > maxLength) {
				maxLength = length;
				maxStartIndex = startIndex;
			}
		}
		else {
			length = 1;
			startIndex = i;
		}
	}

	printf("Day con giam dai nhat: ");
	for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Hàm tìm số nhỏ thứ 2 trong mảng
int soNhoThuHai(int *arr, int n) {
	if (n < 2) {
		printf("Mang phai co it nhat 2 phan tu.\n");
		return -1;
	}

	int first = arr[0], second = INT_MAX;
	for (int i = 1; i < n; i++) {
		if (arr[i] < first) {
			second = first;
			first = arr[i];
		}
		else if (arr[i] < second && arr[i] != first) {
			second = arr[i];
		}
	}

	if (second == INT_MAX) {
		printf("Khong co so nho thu 2.\n");
		return -1;
	}

	return second;
}


// Hàm sắp xếp mảng theo thuật toán Bubble Sort (dùng cho số chẵn)
void bubbleSort(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Hàm sắp xếp mảng sao cho các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
void sapXepChanTangDan(int *arr, int n) {
	int *chan = (int *)malloc(n * sizeof(int));
	int chanCount = 0;

	// Lưu các phần tử chẵn vào mảng tạm
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			chan[chanCount++] = arr[i];
		}
	}

	// Sắp xếp mảng chứa các phần tử chẵn
	bubbleSort(chan, chanCount);

	// Thay thế các phần tử chẵn trong mảng chính bằng các phần tử đã sắp xếp
	int chanIndex = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = chan[chanIndex++];
		}
	}

	free(chan);
}

// Hàm sắp xếp mảng sao cho số lẻ ở đầu, số chẵn ở cuối
void sapXepLeTruocChanSau(int *arr, int n) {
	int *le = (int *)malloc(n * sizeof(int));
	int *chan = (int *)malloc(n * sizeof(int));
	int leCount = 0, chanCount = 0;

	// Phân loại số lẻ và số chẵn vào các mảng con
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			chan[chanCount++] = arr[i];
		}
		else {
			le[leCount++] = arr[i];
		}
	}

	// Ghép mảng số lẻ vào đầu mảng chính
	for (int i = 0; i < leCount; i++) {
		arr[i] = le[i];
	}

	// Ghép mảng số chẵn vào phần còn lại của mảng chính
	for (int i = 0; i < chanCount; i++) {
		arr[leCount + i] = chan[i];
	}

	free(le);
	free(chan);
}

// Hàm xuất mảng
void xuatMang(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int n;

	// Nhập kích thước mảng
	printf("Nhap vao so luong phan tu cua mang: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return -1;
	}

	// Nhập mảng
	printf("Nhap cac phan tu cho mang:\n");
	for (int i = 0; i < n; i++) {
		printf("Phan tu thu %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	// 1. Liệt kê các số nguyên tố nhỏ hơn n
	printf("Cac so nguyen to nho hon %d: ", n);
	lietKeSoNguyenTo(arr, n);

	// 2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ
	int sumOddFirstDigit = tongChuSoDauLe(arr, n);
	printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOddFirstDigit);

	// 3. Liệt kê số lần xuất hiện của các phần tử trong mảng
	printf("So lan xuat hien cua cac phan tu trong mang:\n");
	lietKeSoLanXuatHien(arr, n);

	// 4. Sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần
	sapXepChanLe(arr, n);
	printf("Mang sau khi sap xep so chan tang dan, so le giam dan: ");
	xuatMang(arr, n);

	// 5. Tìm dãy con giảm dài nhất trong mảng
	printf("Day con giam dai nhat trong mang: ");
	dayConGiamDaiNhat(arr, n);

	// 6. Tìm số nhỏ thứ 2 trong mảng
	int secondSmallest = soNhoThuHai(arr, n);
	if (secondSmallest != -1) {
		printf("So nho thu 2 trong mang: %d\n", secondSmallest);
	}

	// 8. Sắp xếp mảng sao cho các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
	printf("Mang sau khi sap xep so chan tang dan, so le giu nguyen vi tri: ");
	sapXepChanTangDan(arr, n);
	xuatMang(arr, n);

	// 9. Sắp xếp mảng: số lẻ ở đầu mảng, số chẵn ở cuối mảng
	printf("Mang sau khi sap xep so le o dau, so chan o cuoi: ");
	sapXepLeTruocChanSau(arr, n);
	xuatMang(arr, n);
	free(arr);
	system("pause");
	return 0;
}
