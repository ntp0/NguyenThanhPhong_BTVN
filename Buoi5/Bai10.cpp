#include <iostream>

// Hàm tính số Fibonacci không đệ quy
int Fibonacci(int k) {
	if (k <= 2)
		return 1;
	int a = 1, b = 1, c;
	for (int i = 3; i <= k; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// Hàm in các số Fibonacci thuộc đoạn [m, n]
void PrintFibonacciInRange(int m, int n) {
	int fib = 0;
	int i = 1;
	std::cout << "Cac so Fibonacci thuoc doan [" << m << ", " << n << "] la: ";

	while (fib <= n) {
		fib = Fibonacci(i);
		if (fib >= m && fib <= n) {
			std::cout << fib << " ";
		}
		i++;
	}
	std::cout << std::endl;
}

int main() {
	int m, n;
	std::cout << "Nhap gia tri m: ";
	std::cin >> m;
	std::cout << "Nhap gia tri n: ";
	std::cin >> n;

	PrintFibonacciInRange(m, n);
	system("pause");
	return 0;
}
