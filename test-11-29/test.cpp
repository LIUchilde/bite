#include<iostream>
using namespace std;
#if 0
int getCount(int n) {
	if (n < 3) {
		return 1;
	}
	else {
		return getCount(n - 1) + getCount(n - 2);
	}
}
int main() {
	int n;
	while (cin >> n) {
		cout << getCount(n) << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s = "abcde";
	const char* str = s.c_str();
	cout << str << endl;
	s[0] = 'A';
	cout << str << endl;
	return 0;
}
#endif

#if 0
int main() {
	int m = 10;
	int n = 20;
	const int *ptr1 = &m;//ָ��ָ������ݲ��ɸı�
	int* const ptr2 = &m;//ָ�벻����ָ�������ط�
	ptr1 = &n;//��ȷ
	//ptr2 = &n;//����ptr2����ָ�������ĵط�
	//*ptr1 = 3;//����ptr1���ܸı�ָ������
	*ptr2 = 4;//��ȷ
	return 0;
}
#endif

#if 0
#include<string>
int main() {
	string s = "abcde";
	cout << s.c_str() << endl;
	return 0;
}
#endif

#if 0
#include<string>
bool math(const char* patten, const char* str) {
	if (*patten == '\0' && *str == '\0') {
		return true;
	}
	if (*patten == '\0' || *str == '\0') {
		return false;
	}
	if (*patten == '?') {
		return math(patten + 1, str + 1);
	}
	else if (*patten == '*') {
		return math(patten + 1, str) || math(patten + 1, str + 1) || math(patten + 1, str);
	}
	else if (*patten == *str) {
		return math(patten + 1, str + 1);
	}
	return false;
}
int main() {
	string patten, str;
	while (cin >> patten >> str) {
		bool ret = math(patten.c_str(), str.c_str());
	}
	return 0;
}
#endif

#include<algorithm>
#include<string>
int main() {
	string s = "abcde";
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}