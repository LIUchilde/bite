#include<iostream>
using namespace std;
#if 0
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int>v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int max = v[0];
	int count = v[0];
	for (int i = 0; i < n; ++i) {
		count += v[i];
		if (count < v[i]) {
			count = v[i];
		}
			if (max < count) {
				max = count;
			}
			if(count<0) {
				count = 0;
			}
	}
	cout << max << endl;
	return 0;
}
#endif

#if 0
#include<string>
bool Palindrome(string str) {
	int size = str.size();
	for (int i = 0; i < size; ++i) {
		if (str[i] != str[size - 1]) {
			return false;
		}
		size = size - 1;
	}
	return true;
}
int main() {
	string s1, s2, temp;
	int count = 0;
	cin >> s1 >> s2;
	temp = s1;
	int size = s1.size() + 1;
	for (int i = 0; i < size; ++i) {
		s1 = temp;
		s1.insert(i, s2);
		if (Palindrome(s1)) {
			count += 1;
		}
	}
	cout << count << endl;
	return 0;
}
#endif
