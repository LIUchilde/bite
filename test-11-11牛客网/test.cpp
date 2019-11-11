#include<iostream>
using namespace std;
#if 0
#include<vector>
int main() {
	int w, h;
	cin >> w >> h;
	vector<vector<int>>v(w, vector<int>(h, 0));
	int count = 0;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			if (v[i][j] == 0) {
				count++;
				if (i+2 < w) {
					v[i + 2][j] = -1;
				}
				if (j+2 < h) {
					v[i][j + 2] = -1;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
#include<string>
int StrToInt(string str) {
	if (str.empty()) {
		return 0;
	}
	int sum = 0;
	int flag = 1;
	if (str[0] == '+') {
		str[0] = '0';
	}
	if (str[0] == '-') {
		flag = -1;
		str[0] = '0';
	}
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			sum = sum * 10 + (str[i] - '0');
		}
		else {
			return 0;
		}
	}
	sum = sum * flag;
	return sum;
}
int main() {
	cout << StrToInt("+2147483647") << endl;
	return 0;
}
#endif

#if 0
int main()
{
	char a[10] = { '1','2','3','4','5','6','7','8','9',0 }, * p; int i;
	i = 8;
	p = a + i;
	cout << p << endl;
}
#endif
#if 0
#include<string>
int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int count[256] = { 0 };
	for (size_t i = 0; i < s2.size(); ++i) {
		count[s2[i]]++;
	}
	string s3;
	for (size_t j = 0; j < s1.size(); ++j) {
		if (count[s1[j]] == 0) {
			s3 += s1[j];
		}
	}
	cout << s3 << endl;
	return 0;
}
#endif

#if 0
#include<vector>
#include<algorithm>
int main() {
	int n;
	cin >> n;
	vector<int>v(3*n, 0);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = n; i <= 3 * n - 2; i+=2) {
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}
#endif

#if 0
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	for (unsigned int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int count = 1;
	for (unsigned int i = 1; i < n - 1; ++i) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1] || v[i]<v[i - 1] && v[i]<v[i + 1]) {
			count++;
		}
		if (i != n - 3) {
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#include<string>
int main() {
	string s1;
	string s2;
	getline(cin, s1);
	int i = s1.size() - 1;
	int j;
	while (i >= 0) {
		if (s1[i] == ' ') {
			j = i + 1;
			while (s1[j] != ' ' && j< s1.size()) {
				s2 += s1[j++];
			}
			s2 += ' ';
		}
		i--;
		if (i == 0) {
			int temp = i;
			while (s1[temp] != ' ') {
				s2 += s1[temp++];
				
			}
		}
	}
	cout << s2 << endl;
	return 0;
}


