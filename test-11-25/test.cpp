#include<iostream>
using namespace std;
#if 0
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		for (int i = 2; i < n; ++i) {
			int sum = 0;
			for (int j = 1; j <= i / 2 + 1; ++j) {
				if (i % j == 0) {
					sum += j;
				}
			}
			if (sum == i) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
int main() {
	int n;
	while (cin >> n) {
		if (n <= 2) {
			cout << -1 << endl;
		}
		else {
			if (n % 2 == 1) {
				cout << 2 << endl;
			}
			else if (n % 4 == 0) {
				cout << 3 << endl;
			}
			else {
				cout << 4 << endl;
			}
		}
	}
	return 0;
}
#endif

#if 0
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		while (n) {
			if ((n & 1) == 1) {
				count++;
			}
			n >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}
#endif


#if 0
int main() {
	char a[] = "asdfg\0dfgh";
	cout << sizeof(a) << endl;
	cout << strlen(a) << endl;
	return 0;
}
#endif

int main() {
	int y, m, d;
	const int a[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	while (cin >> y >> m >> d) {
		int n = a[m - 1] + d;
		if (((y % 4 == 0 && y % 100 == 0) || y % 400 == 0)&&m>2) {
			n++;
		}
		cout << n << endl;
	}
	return 0;
}