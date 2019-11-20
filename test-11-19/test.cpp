#include<iostream>
using namespace std;
#if 0
#include<string>
int main() {
	string str, res, cur;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i) {
		while (str[i] <= '9' && str[i] >= '0') {
			res += str[i++];
		}
		if (res.size() > cur.size()) {
			cur = res;
		}
		res.clear();
	}
	cout << cur << endl;
	return 0;
}
#endif

#if 0
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (v[i] == v[j]) {
				count++;
			}
		}
			if (count > n / 2) {
				cout << v[i] << endl;
			}
			count = 0;
		}
	return 0;
}
#endif

#if 0
#include<string>
#include<algorithm>
int main() {
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flage = false;
	if (m < 0) {
		flage = true;
	}
	while (m) {
		s += table[m % n];
		m /= n;
	}
	if (flage) {
		s += '-';
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

int main() {

	return 0;
}
