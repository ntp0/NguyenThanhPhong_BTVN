#include <iostream>

// Hàm tính số hạng thứ n của dãy x_n và y_n
void CalculateSequence(int n, int& xn, int& yn) {
	if (n == 0) {
		xn = 1;
		yn = 0;
	}
	else {
		int x_prev = 1; // x0
		int y_prev = 0; // y0

		for (int i = 1; i <= n; i++) {
			int x_curr = x_prev + y_prev;
			int y_curr = 3 * x_prev + 2 * y_prev;
			x_prev = x_curr;
			y_prev = y_curr;
		}

		xn = x_prev;
		yn = y_prev;
	}
}

int main() {
	int n;
	std::cout << "Nhap so nguyen duong n: ";
	std::cin >> n;

	int xn, yn;
	CalculateSequence(n, xn, yn);

	std::cout << "So hang thu " << n << " cua day x_n la: " << xn << std::endl;
	std::cout << "So hang thu " << n << " cua day y_n la: " << yn << std::endl;
	system("pause");
	return 0;
}
