#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
// Tính S(n) = 1/1.2.3 + 1/2.3.4 + ... + 1/n.(n+1).(n+2) bằng đệ quy
double S1_recursive(int n) {
	if (n == 1)
		return 1.0 / (1 * 2 * 3);
	return S1_recursive(n - 1) + 1.0 / (n * (n + 1) * (n + 2));
}

// Tính S(n) = 1/1.2.3 + 1/2.3.4 + ... + 1/n.(n+1).(n+2) bằng khử đệ quy
double S1_non_recursive(int n) {
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		sum += 1.0 / (i * (i + 1) * (i + 2));
	}
	return sum;
}

// Tính S(n) = 1^2 + 2^2 + ... + n^2 bằng đệ quy
int S2_recursive(int n) {
	if (n == 1)
		return 1;
	return S2_recursive(n - 1) + n * n;
}

// Tính S(n) = 1^2 + 2^2 + ... + n^2 bằng khử đệ quy
int S2_non_recursive(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * i;
	}
	return sum;
}

// Tính S(n) = 1 + (1 + 2) + ... + (1 + 2 + ... + n) bằng đệ quy
int S3_recursive(int n) {
	if (n == 1)
		return 1;
	return S3_recursive(n - 1) + n * (n + 1) / 2;
}

// Tính S(n) = 1 + (1 + 2) + ... + (1 + 2 + ... + n) bằng khử đệ quy
int S3_non_recursive(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * (i + 1) / 2;
	}
	return sum;
}

// Tính S(n) = − 1 + 2/2! + 3 + 4/4! − 5 + 6/6! … + (−1)^n (2n − 1) + (2n)/(2n)! bằng đệ quy
double S4_recursive(int n) {
	if (n == 1)
		return -1;
	double term = pow(-1, n) * (2 * n - 1 + 2 * n) / tgamma(2 * n + 1);
	return S4_recursive(n - 1) + term;
}

// Tính S(n) = − 1 + 2/2! + 3 + 4/4! − 5 + 6/6! … + (−1)^n (2n − 1) + (2n)/(2n)! bằng khử đệ quy
double S4_non_recursive(int n) {
	double sum = -1;
	for (int i = 2; i <= n; i++) {
		sum += pow(-1, i) * (2 * i - 1 + 2 * i) / tgamma(2 * i + 1);
	}
	return sum;
}

int main() {
	int n;
	std::cout << "Nhap so nguyen duong n: ";
	std::cin >> n;

	std::cout << "S1(n) de quy = " << S1_recursive(n) << std::endl;
	std::cout << "S1(n) khu de quy = " << S1_non_recursive(n) << std::endl;

	std::cout << "S2(n) de quy = " << S2_recursive(n) << std::endl;
	std::cout << "S2(n) khu de quy = " << S2_non_recursive(n) << std::endl;

	std::cout << "S3(n) de quy = " << S3_recursive(n) << std::endl;
	std::cout << "S3(n) khu de quy = " << S3_non_recursive(n) << std::endl;

	std::cout << "S4(n) de quy = " << S4_recursive(n) << std::endl;
	std::cout << "S4(n) khu de quy = " << S4_non_recursive(n) << std::endl;
	system("pause");
	return 0;
}
