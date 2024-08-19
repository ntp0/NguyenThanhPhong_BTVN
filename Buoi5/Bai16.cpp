#include <iostream>

int Y_cach1(int n) {
	if (n >= 1 && n <= 3) {
		return 3;
	}
	return Y_cach1(n - 1) + 2 * Y_cach1(n - 2) + 3 * Y_cach1(n - 3);
}

int Y_cach2(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	return Y_cach2(n - 1) + 2 * Y_cach2(n - 2) + 3 * Y_cach2(n - 3);
}

int main() {
	int n, choice;
	std::cout << "Nhap n: ";
	std::cin >> n;

	std::cout << "Chon cach tinh \n1: Cach 1 - De quy\n2: Cach 2 -  Khu de quy: \n";
	std::cin >> choice;

	int result;
	if (choice == 1) {
		result = Y_cach1(n);
	}
	else if (choice == 2) {
		result = Y_cach2(n);
	}
	else {
		std::cout << "Lua chon khong hop le!" << std::endl;
		return 1;
	}

	std::cout << "Y(" << n << ") = " << result << std::endl;
	system("pause");
	return 0;
}
