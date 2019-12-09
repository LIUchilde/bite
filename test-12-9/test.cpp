#include<iostream>
using namespace std;
#if 0
#include<string>
int main() {
	string a, b, str = " ";
	cin >> a >> b;
		while (a.size() < b.size()) {
			a = '0' + a;
		}
		while (a.size() > b.size()) {
			b = '0' + b;
		}
		int flage = 0, m = 0;
		for (int i = 0; i < a.size(); ++i) {
			int n = a[i] - '0' + b[i] - '0' + flage;
			m = n % 2;
			str = to_string(m) + str;
			flage = n / 2;
		}
		if (flage) {
			str = '1' + str;
		}
		cout << str << endl;
	return 0;
}
#endif

#if 0
#include<string>
#include<set>
int main() {
	string str;
	while (cin >> str) {
		set<string>s;
		set<string>::iterator it;
		for (int i = 1; i <= str.size(); ++i) {
			for (int j = 0; j <= str.size() - i; ++j) {
				string temp = str.substr(j, i);
				s.insert(temp);
			}
			it = s.begin();
			while (it != s.end()) {
				cout << *it << " ";
				++it;
			}
			s.clear();
		}
	}
	return 0;
}
#endif

#if 0
#include<vector>
#include<algorithm>
int main() {
	int m, n;
	cin >> m>>n;
	vector<int>v(n * n);
	for (int i = 0; i < n * n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[m - 1] << endl;
	return 0;
}
#endif

int main() {
	char s[5] = { 'A','B','C','D','E' };
	return 0;
}