#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void xuatChu(char *str) {
	char *ptr = str;
	while (*ptr != '\0') {
		printf("%c ", *ptr);
		ptr++;
	}
	printf("\n");
}

void lamInHoa(char *str) {
	char *ptr = str;
	while (*ptr != '\0') {
		if (islower(*ptr)) {
			*ptr = toupper(*ptr);
		}
		ptr++;
	}
}

void chuInHoa(char *str) {
	char *ptr = str;
	int inHoaNext = 1;  

	while (*ptr != '\0') {
		if (isspace(*ptr)) {
			inHoaNext = 1;
		}
		else if (inHoaNext && islower(*ptr)) {
			*ptr = toupper(*ptr);
			inHoaNext = 0;
		}
		else {
			inHoaNext = 0;
		}
		ptr++;
	}
}

int main() {
	char st[100];

	printf("Nhap vao chuoi: ");
	fgets(st, sizeof(st), stdin);
	st[strcspn(st, "\n")] = '\0'; 

	// a. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi
	printf("Gia tri tung ky tu cua chuoi:\n");
	xuatChu(st);

	// b. Chuyển các ký tự của chuỗi về dạng chữ hoa
	lamInHoa(st);
	printf("Chuoi sau khi chuyen thanh chu hoa: %s\n", st);

	
	for (char *ptr = st; *ptr != '\0'; ptr++) {
		*ptr = tolower(*ptr);
	}
	chuInHoa(st);
	printf("Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: %s\n", st);
	system("pause");
	return 0;
}
