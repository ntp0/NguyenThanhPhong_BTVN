#include <iostream>
using namespace std;

int x(int n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x(i);
	}
	return n * x(0) + (n - 1) * x(1) + sum;
}

int main() {
	int n;
	cout << "Nhap n (n >= 0): ";
	cin >> n;
	if (n < 0) {
		cout << "n phai lon hon hoac bang 0." << endl;
		return 1;
	}
	cout << "x(" << n << ") = " << x(n) << endl;
	system("pause");
	return 0;
}
