#include <iostream>

// Hàm tính giá trị phần tử thứ n của cấp số nhân
int CalculateGeometricSequence(int a, int q, int n) {
	if (n == 1) {
		return a;
	}
	else {
		return q * CalculateGeometricSequence(a, q, n - 1);
	}
}

int main() {
	int a, q, n;

	std::cout << "Nhap gia tri cua a (phan tu dau tien): ";
	std::cin >> a;

	std::cout << "Nhap gia tri cua q (cong boi): ";
	std::cin >> q;

	std::cout << "Nhap gia tri cua n (phan tu thu n): ";
	std::cin >> n;

	int result = CalculateGeometricSequence(a, q, n);

	std::cout << "Gia tri phan tu thu " << n << " cua cap so nhan la: " << result << std::endl;
	system("pause");
	return 0;
}
