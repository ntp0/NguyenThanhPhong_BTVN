#include <iostream>
using namespace std;

// Khai báo các hàm tính toán trước
int x_n_recursive(int n);
int y_n_recursive(int n);
void x_n_iterative(int n, int &x_n, int &y_n);

// Hàm tính số hạng thứ n của dãy x theo phương pháp đệ quy
int x_n_recursive(int n) {
	if (n == 0) return 1;
	int x_prev = x_n_recursive(n - 1);
	int y_prev = y_n_recursive(n - 1);
	return x_prev + y_prev;
}

// Hàm tính số hạng thứ n của dãy y theo phương pháp đệ quy
int y_n_recursive(int n) {
	if (n == 0) return 0;
	int x_prev = x_n_recursive(n - 1);
	int y_prev = y_n_recursive(n - 1);
	return 3 * x_prev + 2 * y_prev;
}

// Hàm tính số hạng thứ n của dãy x và y theo phương pháp khử đệ quy
void x_n_iterative(int n, int &x_n, int &y_n) {
	int x_prev = 1;  // x_0
	int y_prev = 0;  // y_0

	if (n == 0) {
		x_n = x_prev;
		y_n = y_prev;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		int x_current = x_prev + y_prev;
		int y_current = 3 * x_prev + 2 * y_prev;
		x_prev = x_current;
		y_prev = y_current;
	}

	x_n = x_prev;
	y_n = y_prev;
}

// Hàm main để chạy chương trình
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;

	// Tính số hạng thứ n của dãy x và y theo phương pháp đệ quy
	int x_recursive = x_n_recursive(n);
	int y_recursive = y_n_recursive(n);
	cout << "Theo phuong phap de quy: x_" << n << " = " << x_recursive
		<< ", y_" << n << " = " << y_recursive << endl;

	// Tính số hạng thứ n của dãy x và y theo phương pháp khử đệ quy
	int x_iterative, y_iterative;
	x_n_iterative(n, x_iterative, y_iterative);
	cout << "Theo phuong phap khur de quy: x_" << n << " = " << x_iterative
		<< ", y_" << n << " = " << y_iterative << endl;
	system("pause");
	return 0;
}
