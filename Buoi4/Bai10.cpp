#include <iostream>
using namespace std;

// Hàm tính số Fibonacci thứ n
unsigned long long fibonacci(int n) {
	if (n <= 1) return n;
	unsigned long long a = 0, b = 1, c;
	for (int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// Hàm xuất các số Fibonacci trong đoạn [m, n]
void printFibonacciInRange(int m, int n) {
	// Bắt đầu từ số Fibonacci thứ 1 và kiểm tra
	int index = 0;
	unsigned long long fibNum = fibonacci(index);

	// Tiếp tục tính các số Fibonacci cho đến khi vượt qua n
	while (fibNum <= n) {
		if (fibNum >= m) {
			cout << fibNum << " ";
		}
		index++;
		fibNum = fibonacci(index);
	}
	cout << endl;
}

// Hàm main để chạy chương trình
int main() {
	int m, n;
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;

	cout << "Cac so Fibonacci trong doan [" << m << ", " << n << "] la: ";
	printFibonacciInRange(m, n);
	system("pause");
	return 0;
}
