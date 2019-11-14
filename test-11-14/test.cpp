#include<iostream>
using namespace std;
#if 0
int main() {
	int a, b;
	int i;
	while (cin >> a >> b) {
		for (i = a; i <= a * b; ++i) {
			if (i % a == 0 && i % b == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
#endif

#if 0
int gcd(int m, int n) {
	while (m % n) {
		int temp = m;
		m = n;
		n = temp % m;
	}
	return n;
}
int main() {
	int a, b;
	cin >> a>> b;
	cout << (a * b) / gcd(a, b) << endl;
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s;
	getline(cin, s);
	int size = s.size();
	string res, max;
	for (int i = 0; i < size; ++i) {
		while (s[i] <= '9' && s[i] >= '0') {
			res += s[i++];
		}
		if (max.size() < res.size()) {
			max = res;
		}
		res.clear();
	}
	cout << max << endl;
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s;
	getline(cin, s);
	int max = 0;
	int state = 0;
	int count = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			count++;
			if (max < count) {
				max = count;
				state = i;
			}
		}
		else {
			count = 0;
		}
	}
	for (int j = state - max + 1; j <= state; j++) {
		cout << s[j];
	}
	cout << endl;
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
		if (count >= n / 2) {
			cout << v[i];
			break;
		}
		else {
				count = 0;
		}
	}
	return 0;
}
#endif

#if 0
int main() {
	int x, y, z;
	int a, b, c, d;
	cin>> a>>b>> c>> d;
	x = (a + c) / 2;
	y = (b + d) / 2;
	z = (d - b) / 2;
	if (x - y == a && y - z == b && x + y == c && y + z == d) {
		cout << x << " " << y << " " << z << endl;
	}
	else {
		cout << "No";
	}
	return 0;
}
#endif


#include<string>
#include<algorithm>
int main() {
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flage = false;
	if (m < 0) {
		m = 0 - m;
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


