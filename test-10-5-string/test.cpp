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
	//范围for遍历
	for (auto e : s2) {
		cout << e;
	}
	cout << endl;
	cout << s2.size()<<endl;
	cout << s2.capacity() << endl;
	//下标遍历
	for (size_t i = 0;i < s3.size();i++) {
		cout << s3[i];
	}
	cout << endl;
	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	//迭代器遍历
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
//resize:将原有字符串扩增到n个
//resize作用：改变string中有效字符的个数
//将有效字符增多到n个，多出的位置需要使用ch进行填充，可能需要扩容
//将有效字符减少到n个，只修改有效字符的个数，不会缩小空间
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
//reserve:改变底层容量的大小，有效元素个数不会变
//扩大容量：n<=旧空间大小，不会扩容  n>旧空间大小，扩容
//缩小容量：n>15 不会缩小  n<=15 缩小容量
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
	//传统版
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
	//简介版--现代版
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
	//系统提供的默认拷贝构造函数： 会造成浅拷贝
	std::string s3(s2);
	//系统提供的默认赋值运算符重载：1.浅拷贝 2.资源泄露
	std::string s4("world");
	s4 = s3;
	return 0;
}

