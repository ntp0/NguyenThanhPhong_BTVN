#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int Y_memo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	if (memo[n] != -1) return memo[n];
	memo[n] = Y_memo(n - 1) + 2 * Y_memo(n - 2) + 3 * Y_memo(n - 3);
	return memo[n];
}

int main() {
	int n;
	cout << "Nhap n (n >= 1): ";
	cin >> n;
	if (n < 1) {
		cout << "n phai lon hon hoac bang 1." << endl;
		return 1;
	}

	// Khởi tạo mảng memo
	memo.assign(n + 1, -1);

	cout << "Y(" << n << ") = " << Y_memo(n) << endl;
	system("pause");
	return 0;
}
