#include <iostream>
#include <cmath>  // Để sử dụng pow() cho tính q^(n-1)

using namespace std;

// Hàm tính phần tử thứ n của cấp số nhân theo phương pháp đệ quy
int geometric_sequence_recursive(int a, int q, int n) {
	if (n == 1) return a;
	return q * geometric_sequence_recursive(a, q, n - 1);
}

// Hàm tính phần tử thứ n của cấp số nhân theo phương pháp khử đệ quy
int geometric_sequence_iterative(int a, int q, int n) {
	return a * pow(q, n - 1);
}

// Hàm main để chạy chương trình
int main() {
	int a, q, n, method;

	cout << "Nhap gia tri a (hang dau): ";
	cin >> a;
	cout << "Nhap gia tri q (cong boi): ";
	cin >> q;
	cout << "Nhap n (vi tri phan tu): ";
	cin >> n;

	cout << "Chon phuong phap tinh:\n";
	cout << "1. De quy\n";
	cout << "2. Khu de quy\n";
	cout << "Nhap lua chon cua ban (1 hoac 2): ";
	cin >> method;

	if (method == 1) {
		// Tính phần tử thứ n của cấp số nhân theo phương pháp đệ quy
		int value_recursive = geometric_sequence_recursive(a, q, n);
		cout << "Phan tu thu " << n << " theo phuong phap de quy: " << value_recursive << endl;
	}
	else if (method == 2) {
		// Tính phần tử thứ n của cấp số nhân theo phương pháp khử đệ quy
		int value_iterative = geometric_sequence_iterative(a, q, n);
		cout << "Phan tu thu " << n << " theo phuong phap khu de quy: " << value_iterative << endl;
	}
	else {
		cout << "Lua chon khong hop le!" << endl;
	}
	system("pause");
	return 0;
}
