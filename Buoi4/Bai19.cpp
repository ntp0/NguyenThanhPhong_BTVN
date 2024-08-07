#include <iostream>
#include <unordered_map>
using namespace std;

// Khai báo một map để lưu các giá trị đã tính toán (memoization)
unordered_map<int, int> memo;

int A(int n) {
	if (n == 1) return 1; 

	if (memo.find(n) != memo.end()) {
		return memo[n];
	}

	int result;

	if (n % 2 == 0) { 
		int k = n / 2;
		result = k + A(k) + 2;
	}
	else { 
		int k = (n - 1) / 2;
		result = k * k + A(k) * A(k + 1) + 1;
	}

	memo[n] = result;
	return result;
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
