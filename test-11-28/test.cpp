#include<iostream>
using namespace std;

#if 0
int main() {
	int a = 10;
	int& ra = a;
	a = 10;
	cout << &a << endl;
	//int&& rra = a;   编译失败：a是左值
	int&& rra = 10;
	const int c = 20;
	//const int&& rrc = c;    编译错误  c是左值
	int b1 = 1, b2 = 2;
	//b1 + b2 = 10;
	//&(b1 + b2);
	int&& rrb = b1 + b2;//b1+b2表达式结果为右值
	++b1 = 20;//++b1的表达式结果为左值
	return 0;
}
#endif

#if 0
int main() {
	int b = 10;
	int&& rb = move(b);//将一个左值转化为右值
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int max = 0;
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = s1.size(); j > i; --j) {
				if (s2.find(s1.substr(i, j - i)) != -1 && max < j - i) {
					max = j - i;
				}
			}
		}
		cout << max << endl;
	}
}
#endif

#if 0
#include<vector>
#include<string>
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		int max = 0;
		vector<vector<int>>v(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				if (max < v[i][j]) {
					max = v[i][j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>
#include<algorithm>
int main() {
	int m, n;
	while (cin >> m >> n) {
		string s,table = "0123456789ABCDEF";
		bool flage = false;
		if (m < 0) {
			m = 0 - m;
			flage = true;
		}
		while (m) {
			s += table[m % n];
			m = m / n;
		}
		if (flage) {
			s += '-';
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}
#endif

int main() {

	return 0;
}
