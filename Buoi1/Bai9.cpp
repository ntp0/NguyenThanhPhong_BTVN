#include <stdio.h>
#include <stdlib.h>

int main() {
	double a, b;

	printf("Nhap vao so thuc a: ");
	scanf("%lf", &a);
	printf("Nhap vao so thuc b: ");
	scanf("%lf", &b);

	double *pa = &a;
	double *pb = &b;

	printf("Gia tri cua con tro pa: %lf, dia chi: %p\n", *pa, (void*)pa);
	printf("Gia tri cua con tro pb: %lf, dia chi: %p\n", *pb, (void*)pb);

	double sum = *pa + *pb;
	double difference = *pa - *pb;
	double product = *pa * *pb;
	double quotient = *pa / *pb;

	printf("Tong: %lf, dia chi: %p\n", sum, (void*)&sum);
	printf("Hieu: %lf, dia chi: %p\n", difference, (void*)&difference);
	printf("Tich: %lf, dia chi: %p\n", product, (void*)&product);
	printf("Thuong: %lf, dia chi: %p\n", quotient, (void*)&quotient);
	system("pause");
	return 0;
}

