#include <iostream>

// Hàm tính số Fibonacci bằng đệ quy
int Fibonacci(int k) {
	if (k <= 2)
		return 1;
	return Fibonacci(k - 1) + Fibonacci(k - 2);
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn n bằng đệ quy
int FindMaxFibonacciRecursive(int n, int i = 1) {
	int fib = Fibonacci(i);
	if (fib >= n)
		return Fibonacci(i - 1);
	return FindMaxFibonacciRecursive(n, i + 1);
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn n bằng khử đệ quy
int FindMaxFibonacciNonRecursive(int n) {
	if (n <= 1)
		return 0;

	int a = 1, b = 1;
	while (true) {
		int c = a + b;
		if (c >= n)
			return b;
		a = b;
		b = c;
	}
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

	// Tìm số Fibonacci lớn nhất nhỏ hơn n
	std::cout << "So Fibonacci lon nhat nho hon " << n << " (de quy) la: " << FindMaxFibonacciRecursive(n) << std::endl;
	std::cout << "So Fibonacci lon nhat nho hon " << n << " (khu de quy) la: " << FindMaxFibonacciNonRecursive(n) << std::endl;

	// In dãy số Fibonacci thuộc đoạn [m, n]
	PrintFibonacciInRange(m, n);
	system("pause");
	return 0;
}
