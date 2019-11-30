#include<iostream>
using namespace std;
#if 0
int gcd(int m, int n) {
	while (n) {
		int temp = m%n;
		m = n;
		n = temp;
	}
	return m;
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << gcd(m, n) << endl;
	}
	return 0;
}
#endif

#if 0
int gcd(int m, int n) {
	while (n) {
		int temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << m * n / gcd(m, n);
	}
	return 0;
}
#endif

#if 0
#include<vector>
int gcd(int m,int n) {
	while (n) {
		int temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}
int main() {
	int m,n;
	while (cin >> m >> n) {
		vector<int>v(m);
		for (int i = 0; i < m; ++i) {
			cin >> v[i];
		}
		for (int i = 0; i < m; ++i) {
			if (n >= v[i]) {
				n += v[i];
			}
			else {
				n += gcd(n, v[i]);
			}
		}
		cout << n << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s;
	bool flage = true;
	while (cin >> s) {
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); ++i) {
			count[s[i]]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (count[s[i]] == 1) {
				cout << i << endl;
				flage = false;
				break;
			}
		}
		if (flage) {
			cout << -1 << endl;
		} 
	}
	return 0;
}
#endif

#if 0
#include<vector>
int main() {
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		int num = 2 * n;
		vector<int>vec(num);
		for (int i = 0; i < num; ++i) {
			cin >> vec[i];
		}
		while (k--) {
			vector<int>res;
			res = vec;
			for (int i = 0; i < n; ++i) {
				vec[2 * i] = res[i];
				vec[2 * i + 1] = res[n + i];
			}
		}
		for (int i = 0; i < num - 1; ++i) {
			cout << vec[i] << ' ';
		}
		cout << vec[num - 1] << endl;
	}
	return 0;
}
#endif
