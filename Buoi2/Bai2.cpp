#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int phanNguyen;
	int tu;
	int mau;
} HonSo;

// Hàm nhập hỗn số
void nhapHonSo(HonSo *hs) {
	printf("Nhap phan nguyen: ");
	scanf("%d", &hs->phanNguyen);
	printf("Nhap tu so: ");
	scanf("%d", &hs->tu);
	printf("Nhap mau so (khac 0): ");
	scanf("%d", &hs->mau);
	while (hs->mau == 0) {
		printf("Mau so phai khac 0. Nhap lai mau so: ");
		scanf("%d", &hs->mau);
	}
}

// Hàm xuất hỗn số
void xuatHonSo(HonSo hs) {
	printf("%d %d/%d", hs.phanNguyen, hs.tu, hs.mau);
}

// Hàm so sánh hai hỗn số
int soSanhHonSo(HonSo hs1, HonSo hs2) {
	float giaTriHS1 = hs1.phanNguyen + (float)hs1.tu / hs1.mau;
	float giaTriHS2 = hs2.phanNguyen + (float)hs2.tu / hs2.mau;
	if (giaTriHS1 > giaTriHS2) return 1;
	if (giaTriHS1 < giaTriHS2) return -1;
	return 0;
}

// Hàm chuyển hỗn số thành phân số
HonSo chuyenHonSoToPhanSo(HonSo hs) {
	HonSo phanSo;
	phanSo.phanNguyen = hs.phanNguyen * hs.mau + hs.tu;
	phanSo.tu = 1;
	phanSo.mau = hs.mau;
	return phanSo;
}

// Hàm chuyển phân số thành hỗn số
HonSo chuyenPhanSoToHonSo(HonSo phanSo) {
	HonSo hs;
	hs.phanNguyen = phanSo.tu / phanSo.mau;
	hs.tu = phanSo.tu % phanSo.mau;
	hs.mau = phanSo.mau;
	return hs;
}

// Hàm tính tổng của hai hỗn số
HonSo tongHonSo(HonSo hs1, HonSo hs2) {
	HonSo ps1 = chuyenHonSoToPhanSo(hs1);
	HonSo ps2 = chuyenHonSoToPhanSo(hs2);
	HonSo tong;
	tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	tong.mau = ps1.mau * ps2.mau;
	return chuyenPhanSoToHonSo(tong);
}

// Hàm tính hiệu của hai hỗn số
HonSo hieuHonSo(HonSo hs1, HonSo hs2) {
	HonSo ps1 = chuyenHonSoToPhanSo(hs1);
	HonSo ps2 = chuyenHonSoToPhanSo(hs2);
	HonSo hieu;
	hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	hieu.mau = ps1.mau * ps2.mau;
	return chuyenPhanSoToHonSo(hieu);
}

// Hàm tính tích của hai hỗn số
HonSo tichHonSo(HonSo hs1, HonSo hs2) {
	HonSo ps1 = chuyenHonSoToPhanSo(hs1);
	HonSo ps2 = chuyenHonSoToPhanSo(hs2);
	HonSo tich;
	tich.tu = ps1.tu * ps2.tu;
	tich.mau = ps1.mau * ps2.mau;
	return chuyenPhanSoToHonSo(tich);
}

// Hàm tính thương của hai hỗn số
HonSo thuongHonSo(HonSo hs1, HonSo hs2) {
	HonSo ps1 = chuyenHonSoToPhanSo(hs1);
	HonSo ps2 = chuyenHonSoToPhanSo(hs2);
	HonSo thuong;
	thuong.tu = ps1.tu * ps2.mau;
	thuong.mau = ps1.mau * ps2.tu;
	return chuyenPhanSoToHonSo(thuong);
}

// Hàm sắp xếp mảng hỗn số tăng dần
void sapXepHonSoTangDan(HonSo *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhHonSo(arr[i], arr[j]) > 0) {
				HonSo temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp mảng hỗn số giảm dần
void sapXepHonSoGiamDan(HonSo *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhHonSo(arr[i], arr[j]) < 0) {
				HonSo temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm tìm hỗn số x trong mảng theo giải thuật Linear Search
int timHonSoLinear(HonSo *arr, int n, HonSo x) {
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(arr[i], x) == 0) {
			return i;
		}
	}
	return -1; // Không tìm thấy
}

// Hàm sắp xếp mảng sao cho phần nguyên chẵn lên đầu, phần nguyên lẻ ở cuối
void sapXepPhanNguyenChanLe(HonSo *arr, int n) {
	HonSo *chan = (HonSo *)malloc(n * sizeof(HonSo));
	HonSo *le = (HonSo *)malloc(n * sizeof(HonSo));
	int chanCount = 0, leCount = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i].phanNguyen % 2 == 0) {
			chan[chanCount++] = arr[i];
		}
		else {
			le[leCount++] = arr[i];
		}
	}

	for (int i = 0; i < chanCount; i++) {
		arr[i] = chan[i];
	}
	for (int i = 0; i < leCount; i++) {
		arr[chanCount + i] = le[i];
	}

	free(chan);
	free(le);
}

// Hàm tìm hỗn số x theo giải thuật Binary Search trong mảng đã được sắp xếp
int timHonSoBinary(HonSo *arr, int n, HonSo x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (soSanhHonSo(arr[mid], x) == 0) {
			return mid;
		}
		if (soSanhHonSo(arr[mid], x) < 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1; // Không tìm thấy
}

// Hàm chia mảng b thành 2 mảng s1 và s2
void chiaMang(HonSo *b, int n, HonSo **s1, int *s1Size, HonSo **s2, int *s2Size) {
	*s1 = (HonSo *)malloc(n * sizeof(HonSo));
	*s2 = (HonSo *)malloc(n * sizeof(HonSo));
	*s1Size = 0;
	*s2Size = 0;

	for (int i = 0; i < n; i++) {
		if (b[i].phanNguyen != 0) {
			(*s1)[(*s1Size)++] = b[i];
		}
		else {
			(*s2)[(*s2Size)++] = b[i];
		}
	}
}

// Hàm xóa phần tử thứ k trong mảng
void xoaPhanTu(HonSo *arr, int *n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri xoa khong hop le.\n");
		return;
	}

	for (int i = k; i < *n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*n)--;
}

// Hàm thêm hỗn số x vào mảng tại vị trí k
void themPhanTu(HonSo *arr, int *n, HonSo x, int k) {
	if (k < 0 || k > *n) {
		printf("Vi tri them khong hop le.\n");
		return;
	}

	for (int i = *n; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*n)++;
}

// Hàm tạo mảng c chứa các phân số từ mảng b
void taoMangPhanSo(HonSo *b, int n, HonSo **c, int *cSize) {
	*c = (HonSo *)malloc(n * sizeof(HonSo));
	*cSize = 0;

	for (int i = 0; i < n; i++) {
		if (b[i].mau != 0) {
			(*c)[(*cSize)++] = chuyenHonSoToPhanSo(b[i]);
		}
	}
}

// Hàm tính tổng các phần tử của mảng b
HonSo tongMang(HonSo *b, int n) {
	HonSo tong = { 0, 0, 1 };

	for (int i = 0; i < n; i++) {
		tong = tongHonSo(tong, b[i]);
	}

	return tong;
}

// Hàm tìm phần tử lớn nhất trong mảng b
HonSo timMax(HonSo *b, int n) {
	HonSo max = b[0];

	for (int i = 1; i < n; i++) {
		if (soSanhHonSo(b[i], max) > 0) {
			max = b[i];
		}
	}

	return max;
}

// Hàm tìm phần tử nhỏ nhất trong mảng b
HonSo timMin(HonSo *b, int n) {
	HonSo min = b[0];

	for (int i = 1; i < n; i++) {
		if (soSanhHonSo(b[i], min) < 0) {
			min = b[i];
		}
	}

	return min;
}

// Hàm xuất vị trí phần tử có phần nguyên chẵn
void xuatViTriPhanNguyenChan(HonSo *b, int n) {
	printf("Vi tri cac phan tu co phan nguyen chan:\n");
	for (int i = 0; i < n; i++) {
		if (b[i].phanNguyen % 2 == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Hàm xuất vị trí của phần tử lớn nhất và nhỏ nhất
void xuatViTriMaxMin(HonSo *b, int n) {
	HonSo max = timMax(b, n);
	HonSo min = timMin(b, n);

	printf("Vi tri phan tu lon nhat: ");
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(b[i], max) == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Vi tri phan tu nho nhat: ");
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(b[i], min) == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main() {
	int n;

	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);

	HonSo *b = (HonSo *)malloc(n * sizeof(HonSo));
	if (b == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return -1;
	}

	// Nhập mảng b
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d:\n", i + 1);
		nhapHonSo(&b[i]);
	}

	// 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
	HonSo x;
	printf("Nhap phan tu can tim:\n");
	nhapHonSo(&x);
	int viTri = timHonSoLinear(b, n, x);
	if (viTri != -1) {
		printf("Phan tu tim duoc o vi tri: %d\n", viTri);
	}
	else {
		printf("Phan tu khong ton tai trong mang.\n");
	}

	// 2. Sắp xếp mảng sao cho các phần tử có phần nguyên chẵn lên đầu, phần nguyên lẻ ở cuối mảng
	sapXepPhanNguyenChanLe(b, n);
	printf("Mang sau khi sap xep phan nguyen chan len dau, phan nguyen le o cuoi:\n");
	for (int i = 0; i < n; i++) {
		xuatHonSo(b[i]);
		printf("\n");
	}

	// 3. Tìm hỗn số x theo giải thuật Binary Search trong mảng đã được sắp xếp tăng dần
	viTri = timHonSoBinary(b, n, x);
	if (viTri != -1) {
		printf("Phan tu tim duoc o vi tri: %d\n", viTri);
	}
	else {
		printf("Phan tu khong ton tai trong mang.\n");
	}

	// 4. Chia mảng b thành 2 mảng s1 và s2
	HonSo *s1, *s2;
	int s1Size, s2Size;
	chiaMang(b, n, &s1, &s1Size, &s2, &s2Size);
	printf("Mang s1 (phan nguyen):\n");
	for (int i = 0; i < s1Size; i++) {
		xuatHonSo(s1[i]);
		printf("\n");
	}
	printf("Mang s2 (phan so):\n");
	for (int i = 0; i < s2Size; i++) {
		xuatHonSo(s2[i]);
		printf("\n");
	}
	free(s1);
	free(s2);

	// 5. Xóa phần tử thứ k trong mảng b
	int k;
	printf("Nhap vi tri phan tu can xoa: ");
	scanf("%d", &k);
	xoaPhanTu(b, &n, k);
	printf("Mang sau khi xoa phan tu:\n");
	for (int i = 0; i < n; i++) {
		xuatHonSo(b[i]);
		printf("\n");
	}

	// 6. Thêm hỗn số x vào mảng b tại vị trí k
	printf("Nhap phan tu can them:\n");
	nhapHonSo(&x);
	printf("Nhap vi tri can them phan tu: ");
	scanf("%d", &k);
	themPhanTu(b, &n, x, k);
	printf("Mang sau khi them phan tu:\n");
	for (int i = 0; i < n; i++) {
		xuatHonSo(b[i]);
		printf("\n");
	}

	// 7. Tạo mảng c chứa các phân số từ các phần tử hỗn số của mảng b
	HonSo *c;
	int cSize;
	taoMangPhanSo(b, n, &c, &cSize);
	printf("Mang c (phan so):\n");
	for (int i = 0; i < cSize; i++) {
		xuatHonSo(c[i]);
		printf("\n");
	}
	free(c);

	// 8. Tính tổng các phần tử của mảng b
	HonSo tong = tongMang(b, n);
	printf("Tong cac phan tu trong mang b:\n");
	xuatHonSo(tong);
	printf("\n");

	// 9. Tìm phần tử lớn nhất và nhỏ nhất của b
	HonSo max = timMax(b, n);
	HonSo min = timMin(b, n);
	printf("Phan tu lon nhat:\n");
	xuatHonSo(max);
	printf("\n");
	printf("Phan tu nho nhat:\n");
	xuatHonSo(min);
	printf("\n");

	// 10. Xuất vị trí phần tử có phần nguyên chẵn của b
	xuatViTriPhanNguyenChan(b, n);

	// 11. Xuất vị trí của phần tử lớn nhất và nhỏ nhất của b
	xuatViTriMaxMin(b, n);

	free(b);
	system("pause");
	return 0;
}
