#include <iostream>

int x(int n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (n - i) * x(i);
	}
	return sum;
}

int main() {
	int n;
	std::cout << "Nhap n: ";
	std::cin >> n;
	std::cout << "x(" << n << ") = " << x(n) << std::endl;
	system("pause");
	return 0;
}
