#include <iostream>

int A(int n) {
	if (n == 1) return 1;
	if (n % 2 == 0) {
		return n + A(n / 2);
	}
	return n*n + A(n + 1) + 1;
}

int main() {
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	std::cout << "A(" << n << ") = " << A(n) << std::endl;
	system("pause");
	return 0;
}
