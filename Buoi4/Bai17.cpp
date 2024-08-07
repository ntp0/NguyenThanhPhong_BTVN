#include <iostream>
using namespace std;

int X(int n) {
	if (n == 1 || n == 2) return 1;
	return X(n - 1) + (n - 1) * X(n - 2);
}

int main() {
	int n;
	cout << "Nhap n (n >= 1): ";
	cin >> n;
	if (n < 1) {
		cout << "n phai lon hon hoac bang 1." << endl;
		return 1;
	}
	cout << "X(" << n << ") = " << X(n) << endl;
	system("pause");
	return 0;
}
