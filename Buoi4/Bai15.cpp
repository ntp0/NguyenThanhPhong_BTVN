#include <iostream>
using namespace std;

int A(int n) {
	if (n == 1) return 1;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += A(i);
	}
	return n * sum;
}

int main() {
	int n;
	cout << "Nhap n (n >= 1): ";
	cin >> n;
	if (n < 1) {
		cout << "n phai lon hon hoac bang 1." << endl;
		return 1;
	}
	cout << "A(" << n << ") = " << A(n) << endl;
	system("pause");
	return 0;
}
