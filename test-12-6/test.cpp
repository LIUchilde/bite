#include<iostream>
using namespace std;
#if 0
#include<string>
int strToInt(string str) {
	if (str.size() <= 0) {
		return 0;
	}
	int flage = 1;
	if (str[0] == '-1') {
		flage = -1;
		str[0] = '0';
	}
	else if (str[0] == '+') {
		str[0] = '0';
	}
	long long sum = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] < '0' || str[i]>'9') {
			return 0;
		}
		sum = sum * 10 + str[i] - '0';
	}
	long long ret = flage * sum;
	if (ret>= -2147483648 && ret<= 2147483647) {
		return ret;
	}
	else {
		return 0;
	}
}
int main() {
	string s;
	while (cin >> s) {
		cout << strToInt(s) << endl;
	}
}
#endif

#if 0
#include<string>
int main() {
	string a, b;
	while (cin >> a >> b) {
		string res;
		while (a.size() > b.size()) {
			b = '0' + b;
		}
		while (a.size() < b.size()) {
			a = '0' + a;
		}
		int flage = 0, m = 0;
		for (int i = 0; i < a.size(); ++i) {
			int n = a[i] - '0' + b[i] - '0' + flage;
			m = n % 2;
			res = to_string(m) + res;
			flage = n / 2;
		}
		if (flage) {
			res = '1' + res;
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
class test
{
public:
	test() {
		cout << "test()" << endl;
	}
	~test() {
		cout << "~test()" << endl;
	}
	test(test& t) {
		cout << "test&t" << endl;
	}
	test& operator=(const test& t) {
		cout << "test&" << endl;
		return *this;
	}
};
int main() {
	test a;
	test b(a);
	test c = a;
	c = b;
	return 0;
}
#endif

#if 0
int main() {
#define INT_PTR int*
	typedef int* int_ptr;
	INT_PTR a, b;
	int_ptr c, d;
	cout << *a << endl;
	cout << b << endl;
	cout << *c << endl;
	cout << *d << endl;
	return 0;
}
#endif

int main() {
	return 0;
}