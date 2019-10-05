#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
int main() {
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);
	cin >> s1;
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	//��Χfor����
	for (auto e : s2) {
		cout << e;
	}
	cout << endl;
	cout << s2.size()<<endl;
	cout << s2.capacity() << endl;
	//�±����
	for (size_t i = 0;i < s3.size();i++) {
		cout << s3[i];
	}
	cout << endl;
	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	//����������
	//string::iterator it = s4.begin();c++98
	auto it = s4.begin();//c++11
	while (it != s4.end()) {
		cout << *it;
		it++;
	}
	cout << endl;
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	s4.clear();
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//resize:��ԭ���ַ���������n��
//resize���ã��ı�string����Ч�ַ��ĸ���
//����Ч�ַ����ൽn���������λ����Ҫʹ��ch������䣬������Ҫ����
//����Ч�ַ����ٵ�n����ֻ�޸���Ч�ַ��ĸ�����������С�ռ�
int main() {
	string s1("hello");
	for (auto e : s1) {
		cout << e;
	}
	cout << endl;
	cout << s1.size()<<endl;
	cout << s1.capacity()<<endl;
	s1.resize(10, '!');
	for (auto e : s1) {
		cout << e;
	}
	cout << endl;
	cout << s1.size() << endl;
	cout << s1.capacity()<<endl;
	s1.resize(80, '!');
	cout << s1.size() << endl;
	cout << s1.capacity()<<endl;
	s1.resize(1);
	for (auto e : s1) {
		cout << e;
	}
	cout << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//reserve:�ı�ײ������Ĵ�С����ЧԪ�ظ��������
//����������n<=�ɿռ��С����������  n>�ɿռ��С������
//��С������n>15 ������С  n<=15 ��С����
int main() {
	string s1("hello");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(10);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(60);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(30);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(6);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main() {
	string s1("hello");
	cout << s1 << endl;
	reverse(s1.begin(), s1.end());
	cout << s1 << endl;
	string s2("world");
	s1 += ' ';
	s1 += s2;
	s1 += "!!";
	cout << s1 << endl;
	s1.append("very", 3);
	cout << s1 << endl;
	s1.append(s2, 2, 2);
	cout << s1 << endl;
	s1.push_back('.');
	cout << s1 << endl;
	system("pause");
	return 0;
}
#endif 

#if 0
int main() {
	string s1("hello ");
	s1.insert(6, "world");
	cout << s1 << endl;
	s1.erase(s1.begin()+s1.find(' '),s1.end());
	cout << s1 << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main() {
	string s1("asdfghj.jk.txt");
	cout<<s1.substr(s1.rfind('.')+1)<<endl;
	system("pause");
	return 0;
}
#endif

#if 0
int Test(string s) {
	int i = s.rfind(' ');
	if (i == -1) {
		return s.size();
	}
	if (i = s.size() - 1) {
		s.erase(i, 1);
		return Test(s);
	}
	return s.size() - 1 - i;
}
int main() {
	cout << Test("hello world") << endl;
	return 0;
}
#endif

#if 0
string reverseString(string s) {
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end) {
		swap(s[begin], s[end]);
		begin++;
		end--;
	}
	return s;
}
int main() {
	return 0;
}
#endif

#if 0
int firstUniqChar(string s) {
	int count[256] = { 0 };
	for (size_t i = 0;i < s.size();i++) {
		count[s[i]]++;
	}
	for (size_t i = 0;i < s.size();i++) {
		if (1 == count[s[i]]) {
			return i;
		}
	}
	return -1;
}
int main() {
	cout << firstUniqChar("asdfgaghjjh") << endl;
	return 0;
}
#endif






class string {
public:
	string(const char* str = " ") {
		if (str == nullptr) {
			str = " ";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//��ͳ��
	//string(const string& s)
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}
	//string& operator=(const string& s) {
	//	if (this != &s) {
	//		char*str = new char[strlen(s._str) + 1];
	//		strcpy(str, s._str);
	//		delete[]_str;
	//		_str = str;
	//	}
	//	return *this;
	//}
	//����--�ִ���
	string(const string& s)
		:_str(nullptr)
	{
		string strTemp(s._str);
		swap(_str, strTemp._str);
	}
	string& operator=(string s) {
		swap(_str, s._str);
		return *this;
	}
	~string() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main() {
	std::string s1;
	std::string s2("hello");
	//ϵͳ�ṩ��Ĭ�Ͽ������캯���� �����ǳ����
	std::string s3(s2);
	//ϵͳ�ṩ��Ĭ�ϸ�ֵ��������أ�1.ǳ���� 2.��Դй¶
	std::string s4("world");
	s4 = s3;
	return 0;
}

