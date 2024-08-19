#include <iostream>

int A(int n) {
	if (n == 1) {
		return 1;
	}
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += A(i);
	}
	return n * sum;
}

int main() {
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	std::cout << "A(" << n << ") = " << A(n) << std::endl;
	system("pause");
	return 0;
}
