#include<iostream>
using namespace std;
#if 0
int main() {
	int n;
	while (cin >> n) {
		int max = 0;
		int count = 0;
		while (n) {
			if (n & 1) {
				count++;
				if (max < count) {
					max = count;
				}
			}
			else {
				count = 0;
			}
			n = n >> 1;
		}
		cout << max << endl;
	}
	return 0;
}
#endif

#if 0
int main() {
	int a, b;
	while (cin >> a >> b) {
		while (a != b) {
			if (a > b) {
				a = a / 2;
			}
			else {
				b = b / 2;
			}
		}
		cout << a << endl;
	}
	return 0;
}
#endif

#if 0
bool prime(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	while (cin >> n) {
		int x = 0;
		int y = 0;
		for (int i = n/2; i < n; ++i) {
			if (prime(i) && prime(n - i)) {
				x = i;
				y = n - i;
			}
		}
		cout << y <<" "<< x << endl;
	}
	return 0;
}
#endif

#if 0
int add(int A, int B) {
	while ((A & B) != 0) {
		int a = A;
		int b = B;
		A = (a & b) << 1;
		B = a ^ b;
	}
	return A ^ B;
}
int main() {
	int A, B;
	while (cin >> A >> B) {
		cout << add(A, B) << endl;
	}
	return 0;
}
#endif

#if 0
int step(int x, int y) {
	if (x == 0 || y == 0) {
		return 1;
	}
	else {
		return step(x - 1, y) + step(x, y - 1);
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << step(n, m) << endl;
	}
	return 0;
}
#endif

#if 0
#include<algorithm>
#include<vector>
#include<string>
bool isdict(vector<string>str, int n) {
	vector<string>res;
	res = str;
	sort(res.begin(), res.end());
	for (int i = 0; i < n; ++i) {
		if (str[i] != res[i]) {
			return false;
		}
	}
	return true;
}
bool comper(string s1, string s2) {
	return s1.size() < s2.size();
}
bool isline(vector<string>str, int n) {
	vector<string>res;
	res = str;
	sort(res.begin(), res.end());
	for (int i = 0; i < n; ++i) {
		if (str[i] != res[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	vector<string>str;
	string s;
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> s;
			str.push_back(s);
		}
		if (isdict(str, n) && isline(str, n)) {
			cout << "both" << endl;
		}
		else if (isdict(str, n) == 1 && isline(str, n) == 0) {
			cout << "lexicographically" << endl;
		}
		else if (isline(str, n) == 1 && isdict(str, n) == 0) {
			cout << "lengths" << endl;
		}
		else {
			cout << "none" << endl;
		}
	}
	return 0;
}
#endif

#if 0
bool min(int a, int b) {
	return a < b;
}
int main() {
	int N, l, r = 0, f = 0, f0 = 0, f1 = 1;
	while (1) {
		cin >> N;
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f < N) {
			r = N - f;
		}
		else {
			l = f - N;
			break;
		}
	}
	cout << min(l, r) << endl;
	return 0;
}
#endif

#include<string>
#include<stack>
bool chkParenthesis(string A, int n) {
	int i = 0;
	stack<char>s;
	if (A[i] != '(') {
		return false;
	}
	else {
		s.push(A[i++]);
	}
	while (i < n) {
		if (A[i] == '(') {
			s.push(A[i++]);
		}
		if (A[i] != '(' && A[i] != ')') {
			return false;
		}
		if (!s.empty() && A[i] == ')') {
			s.pop();
			i++;
		}
		if (s.empty() && A[i] == ')') {
			return false;
		}
	}
	if (s.empty()) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string A;
	cin >> A;
	int n = A.size();
	cout<<chkParenthesis(A, n)<<endl;
	return 0;
}
