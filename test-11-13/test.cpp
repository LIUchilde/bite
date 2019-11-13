#include<iostream>
#include<vector>
using namespace std;
#if 0
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	for (size_t i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int count = 1;
	for (size_t i = 1; i < n - 1; i++) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1] || v[i] < v[i - 1] && v[i] < v[i + 1]) {
			count++;
			if (i != n - 3) {
				i++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s1;
	string s2;
	getline(cin, s1);
	int i = s1.size() - 1;
	while (i >= 0) {
		if (s1[i] == ' ') {
			int j = i + 1;
			while (s1[j] != ' ' && j < s1.size()) {
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
#endif

#if 0
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	for (size_t i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int m = v[0];
	int k = v[0];
	for (size_t i = 1; i < n; ++i) {
		k += v[i];
		if (k < v[i]) {
			k = v[i];
		}
		if (k > m) {
			m = k;
		}
	}
	cout << m << endl;
	return 0;
}
#endif


#include<string>
int main() {
	string str, res, cur;
	getline(cin, str);
	for (size_t i = 0; i <= str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			res += str[i];
		}
		else {
			if (res.size() > cur.size()) {
				cur = res;
			}
			else {
				res.clear();
			}
		}
	}
	cout << cur << endl;
	return 0;
}



#if 0
#include<string>
int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		// 数字+=到cur
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// 找出更长的字符串，则更新字符串
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res;
	return 0;
}
#endif

