#include <iostream>

int X(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return X(n - 1) + (n - 1) * X(n - 2);
}

int main() {
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	std::cout << "X(" << n << ") = " << X(n) << std::endl;
	system("pause");
	return 0;
}
