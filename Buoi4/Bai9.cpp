#include <iostream>
using namespace std;

// Hàm tính giá trị biểu thức S(n) theo cách De quy và Khu de quy

// Biểu thức 1
double S_recursion(int n, int current) {
	if (current > n) return 0;
	return 1.0 / (current * (current + 1) * (current + 2)) + S_recursion(n, current + 1);
}

double S_iteration(int n) {
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		sum += 1.0 / (i * (i + 1) * (i + 2));
	}
	return sum;
}

// Biểu thức 2
int S_recursion_squared(int n) {
	if (n == 1) return 1;
	return n * n + S_recursion_squared(n - 1);
}

int S_iteration_squared(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * i;
	}
	return sum;
}

// Biểu thức 3
int sum_first_k(int k) {
	return k * (k + 1) / 2;
}

int S_recursion_sum(int n) {
	if (n == 1) return sum_first_k(1);
	return S_recursion_sum(n - 1) + sum_first_k(n);
}

int S_iteration_sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * (i + 1) / 2;
	}
	return sum;
}

// Biểu thức 4
int factorial(int x) {
	if (x <= 1) return 1;
	return x * factorial(x - 1);
}

double S_recursion_factorial(int n, int current) {
	if (current > n) return 0;
	int sign = (current % 2 == 0) ? 1 : -1;
	return sign * ((2 * current - 1) + 2 * current) / static_cast<double>(factorial(2 * current)) + S_recursion_factorial(n, current + 1);
}

double S_iteration_factorial(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		int sign = (i % 2 == 0) ? 1 : -1;
		sum += sign * ((2 * i - 1) + 2 * i) / static_cast<double>(factorial(2 * i));
	}
	return sum;
}

// Hàm main
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;

	// Biểu thức 1
	cout << "S(n) = " << S_recursion(n, 1) << " (De quy)" << endl;
	cout << "S(n) = " << S_iteration(n) << " (Khu de quy)" << endl;

	// Biểu thức 2
	cout << "S(n) = " << S_recursion_squared(n) << " (De quy)" << endl;
	cout << "S(n) = " << S_iteration_squared(n) << " (Khu de quy)" << endl;

	// Biểu thức 3
	cout << "S(n) = " << S_recursion_sum(n) << " (De quy)" << endl;
	cout << "S(n) = " << S_iteration_sum(n) << " (Khu de quy)" << endl;

	// Biểu thức 4
	cout << "S(n) = " << S_recursion_factorial(n, 1) << " (De quy)" << endl;
	cout << "S(n) = " << S_iteration_factorial(n) << " (Khu de quy)" << endl;
	system("pause");
	return 0;
}
