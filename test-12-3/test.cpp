#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) {
			swap(s1, s2);
		}
		string str;
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = i; j < s1.size(); ++j) {
				string temp = s1.substr(i, j - i + 1);
				if (int(s2.find(temp)) < 0) {
					break;
				}
				else if (str.size() < temp.size()) {
					str = temp;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}
#endif

#if 0
int main() {
	string s1 = "abcde";
	string temp = s1.substr(0, 3);
	cout << temp << endl;
	cout << s1.find(temp) << endl;
	return 0;
}
#endif

#if 0
int main() {
	int num;
	while (cin >> num) {
		int sum = 0;
		while (num > 1) {
			int m = num / 3;
			int n = num % 3;
			sum += m;
			num = m + n;
			if (num == 2) {
				++sum;
				break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
#endif

#if 0
int getMost(vector<vector<int>>board) {
	int i, j;
	for (i = 0; i < 6; ++i) {
		board[0][i] += board[0][i - 1];
	}
	for (i = 0; i < 6; ++i) {
		board[i][0] += board[i - 1][0];
	}
	for (i = 1; i < 6; ++i) {
		for (j = 1; j < 6; ++j) {
			if (board[i - 1][j] > board[i][j - 1]) {
				board[i][j] += board[i - 1][j];
			}
			else {
				board[i][j] += board[i][j - 1];
			}
		}
	}
	return board[5][5];
}
#endif

#if 0
int getTotalCount(int n) {
	int count = 0;
	if (n < 3) {
		count = 1;
	}
	else {
		count = getTotalCount(n - 1) + getTotalCount(n - 2);
	}
	return count;
}
int main() {
	int n;
	while (cin >> n) {
		cout << getTotalCount(n) << endl;
	}
	return 0;
}
#endif

#if 0
int main() {
	char* ptr;
	char string[] = "abcdefg";
	ptr = string;
	cout << ptr << endl;
	ptr += 5;
	cout << *ptr << endl;
	return 0;
}
#endif

#if 0
int main() {
	int a[] = { 1,2,3,4 };
	int* p[] = { a,a + 1,a + 2 };
	cout << p << endl;
	int** q = p;
	cout << q << endl;
	cout << *(p[0] + 1) << endl;
	cout << **(q + 2) << endl;
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
		else if (n % 2 == 1) {
			cout << 2 << endl;
		}
		else if (n % 4 == 0) {
			cout << 3 << endl;
		}
		else {
			cout << 4 << endl;
		}
	}
	return 0;
}
#endif

int main() {

	return 0;
}