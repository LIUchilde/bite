#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main() {
	string s1;
	string s2("hello");
	string s3(s2);
	string s4("world");
	s2 = s4;
	s4.operator+=('s');
	s3.operator+=(" world ");
	s2.operator+=(s4);
	//for (size_t i = 0;i < s2.size();i++) {
	//	cout << s2[i];
	//}
	//cout << endl;
	auto it = s3.begin();
	while (it != s3.end()) {
		cout << *it;
		++it;
	}
	cout << endl;
	for (auto e : s4) {
		cout << e;
	}
	cout << endl;
	system("pause");
	return 0;
}