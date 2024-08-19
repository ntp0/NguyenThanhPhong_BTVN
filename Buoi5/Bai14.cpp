#include <iostream>

int U(int n) {
	if (n < 6) {
		return n;
	}
	return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
}

int main() {
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	std::cout << "U(" << n << ") = " << U(n) << std::endl;
	system("pause");
	return 0;
}
