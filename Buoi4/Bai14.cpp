#include <iostream>
using namespace std;

int U(int n) {
	if (n < 6) return n; // U(n) = n cho n < 6
	return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
}

int main() {
	int n;
	cout << "Nhap n (n >= 1): ";
	cin >> n;
	if (n < 1) {
		cout << "n phai lon hon hoac bang 1." << endl;
		return 1;
	}
	cout << "U(" << n << ") = " << U(n) << endl;
	system("pause");
	return 0;
}
