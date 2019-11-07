#include<iostream>
using namespace std;
#if 0
#include<string>
int main() {
	string s1;
	string s2;
	while (getline(cin, s1)) {
		int i = s1.size() - 1;
		while (i >= 0) {
			if (s1[i] == ' ') {
				int j = i + 1;
				while (s1[j] != ' ' && j < s1.size()) {
					s2 += s1[j];
					j++;
				}
				s2 += ' ';
			}
			i--;
			if (i == 0) {
				int temp = i;
				while (s1[temp] != ' ') {
					s2 += s1[temp];
					temp++;
				}
			}
		}
		cout << s2 << endl;
		s2 = " ";
	}
	return 0;
}
#endif
#if 0
#include<vector>
int main() {
	int n;
	while (cin >> n) {
		vector<int>v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int count = 1;
		for (int i = 1; i < n - 1; i++) {
			if (v[i - 1]<v[i] && v[i]>v[i + 1] || v[i - 1] > v[i] && v[i] < v[i + 1]) {
				count++;
				if (i != n - 3)
					i++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
#endif
#if 0
#include<string>
int main() {
	string s1;
	string s2;
	string s3;
	getline(cin, s1);
	getline(cin, s2);
	int count[256] = { 0 };
	for (int i = 0; i < s2.size(); i++) {
		count[s2[i]]++;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (count[s1[i]] == 0) {
			s3 += s1[i];
		}
	}
	cout << s3 << endl;
	return 0;
}
#endif

#if 0
#include<string>
#include<algorithm>
int main() {
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	auto start = str.begin();
	while (start != str.end()) {
		auto end = start;
		while (end != str.end() && *end != ' ') {
			end++;
		}
		reverse(start, end);
		if (end != str.end()) {
			start = end + 1;
		}
		else {
			start = end;
		}
	}
	cout << str;
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string str;
	getline(cin, str);
	int size = str.size();
	int start = 0;
	int max = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (str[i]>='0'&&str[i]<='9') {
				count++;
		if (count > max) {
			max = count;
			start = i;
		}
	}
		else {
			count = 0;
		}
	}
	for (int i = start - max+1; i <= start; i++) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}
#endif

#include<string>
#include<vector>
int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int maxline = 0;
	int start = 0;
	int count = 1;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				int m = i, n = j;
				while (m + 1 < s1.size() && n + 1 < s2.size() && s1[m++] == s2[n++]) {
					count++;
				}
				if (count > maxline) {
					maxline = count;
					start = i;
				}
				count = 1;
			}
		}
	}
	cout << s1.substr(s1[start], maxline) << endl;
	return 0;
}



