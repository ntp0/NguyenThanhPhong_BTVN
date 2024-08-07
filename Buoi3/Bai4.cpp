#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 100

// Hàm tạo ma trận vuông với giá trị ngẫu nhiên
void taoMaTran(int a[MAX][MAX], int n, int minVal, int maxVal) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// Hàm sắp xếp một vector tăng dần hoặc giảm dần
void sapXepVector(vector<int>& vec, bool tangDan) {
	if (tangDan) {
		sort(vec.begin(), vec.end());
	}
	else {
		sort(vec.begin(), vec.end(), std::greater<int>());
	}
}

// Hàm sắp xếp đường chéo phụ tăng dần hoặc giảm dần
void sapXepDuongCheoPhu(int a[MAX][MAX], int n, bool tangDan) {
	vector<int> cheoPhu;
	for (int i = 0; i < n; i++) {
		cheoPhu.push_back(a[i][n - i - 1]);
	}
	sapXepVector(cheoPhu, tangDan);
	for (int i = 0; i < n; i++) {
		a[i][n - i - 1] = cheoPhu[i];
	}
}

// Hàm sắp xếp ma trận sao cho các dòng chẵn giảm dần và các dòng lẻ tăng dần
void sapXepDongChanLe(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		vector<int> dong(a[i], a[i] + n);
		if (i % 2 == 0) {  // Dòng chẵn
			sort(dong.begin(), dong.end(), std::greater<int>());
		}
		else {  // Dòng lẻ
			sort(dong.begin(), dong.end());
		}
		for (int j = 0; j < n; j++) {
			a[i][j] = dong[j];
		}
	}
}

// Hàm sắp xếp ma trận sao cho các cột chẵn tăng dần và các cột lẻ giảm dần
void sapXepCotChanLe(int a[MAX][MAX], int n) {
	for (int j = 0; j < n; j++) {
		vector<int> cot(n);
		for (int i = 0; i < n; i++) {
			cot[i] = a[i][j];
		}
		if (j % 2 == 0) {  // Cột chẵn
			sort(cot.begin(), cot.end());
		}
		else {  // Cột lẻ
			sort(cot.begin(), cot.end(), std::greater<int>());
		}
		for (int i = 0; i < n; i++) {
			a[i][j] = cot[i];
		}
	}
}

// Hàm sắp xếp các đường chéo chính và các đường chéo song song tăng dần
void sapXepDuongCheo(int a[MAX][MAX], int n) {
	vector<int> diag;
	for (int d = 0; d < 2 * n - 1; d++) {
		diag.clear();
		for (int i = 0; i < n; i++) {
			int j = d - i;
			if (j >= 0 && j < n) {
				diag.push_back(a[i][j]);
			}
		}
		sort(diag.begin(), diag.end());
		int k = 0;
		for (int i = 0; i < n; i++) {
			int j = d - i;
			if (j >= 0 && j < n) {
				a[i][j] = diag[k++];
			}
		}
	}
}

// Hàm di chuyển các phần tử chẵn lên đầu và lẻ xuống cuối
void sapXepChanLe(int a[MAX][MAX], int n) {
	vector<int> chan, le;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				chan.push_back(a[i][j]);
			}
			else {
				le.push_back(a[i][j]);
			}
		}
	}
	sort(chan.begin(), chan.end());
	sort(le.begin(), le.end());

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (index < chan.size()) {
				a[i][j] = chan[index++];
			}
			else {
				a[i][j] = le[index++ - chan.size()];
			}
		}
	}
}

// Hàm kiểm tra đối xứng qua đường chéo chính
bool kiemTraDoiXung(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n;
	int a[MAX][MAX];

	cout << "Nhap cap ma tran (n >= 5): ";
	cin >> n;

	if (n < 5) {
		cout << "Cap ma tran phai >= 5" << endl;
		return 1;
	}

	taoMaTran(a, n, 1, 100);
	cout << "Ma tran vua tao:" << endl;
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep duong cheo phu tang dan:" << endl;
	sapXepDuongCheoPhu(a, n, true);
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep duong cheo phu giam dan:" << endl;
	sapXepDuongCheoPhu(a, n, false);
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep dong chan le:" << endl;
	sapXepDongChanLe(a, n);
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep cot chan le:" << endl;
	sapXepCotChanLe(a, n);
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep duong cheo va duong cheo song song:" << endl;
	sapXepDuongCheo(a, n);
	xuatMaTran(a, n);

	cout << "Ma tran sau khi sap xep chan le:" << endl;
	sapXepChanLe(a, n);
	xuatMaTran(a, n);

	if (kiemTraDoiXung(a, n)) {
		cout << "Ma tran doi xung qua duong cheo chinh." << endl;
	}
	else {
		cout << "Ma tran khong doi xung qua duong cheo chinh." << endl;
	}

	return 0;
}
