#include <iostream>
using namespace std;

// Hàm tính số Fibonacci thứ n theo phương pháp đệ quy
unsigned long long fibonacci(int n) {
	if (n <= 1) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm tìm số Fibonacci lớn nhất nhưng nhỏ hơn n theo phương pháp đệ quy
unsigned long long findLargestFibonacciRecursively(int n) {
	if (n <= 1) return 0;

	int index = 0;
	unsigned long long fibNum = fibonacci(index);

	while (fibNum < n) {
		index++;
		fibNum = fibonacci(index);
	}

	return (index > 0) ? fibonacci(index - 1) : 0;
}

// Hàm tìm số Fibonacci lớn nhất nhưng nhỏ hơn n theo phương pháp khử đệ quy
unsigned long long findLargestFibonacciIteratively(int n) {
	if (n <= 1) return 0;

	unsigned long long a = 0, b = 1;
	unsigned long long c = a + b;

	while (c < n) {
		a = b;
		b = c;
		c = a + b;
	}

	return b;
}

// Hàm main để chạy chương trình
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;

	// Tìm số Fibonacci lớn nhất nhưng nhỏ hơn n theo phương pháp đệ quy
	unsigned long long resultRec = findLargestFibonacciRecursively(n);
	cout << "Theo phuong phap de quy, so Fibonacci lon nhat nho hon " << n << " la: "
		<< resultRec << endl;

	// Tìm số Fibonacci lớn nhất nhưng nhỏ hơn n theo phương pháp khử đệ quy
	unsigned long long resultIter = findLargestFibonacciIteratively(n);
	cout << "Theo phuong phap khur de quy, so Fibonacci lon nhat nho hon " << n << " la: "
		<< resultIter << endl;
	system("pause");
	return 0;
}
