#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
int main() {
	string s1;
	string s2("hello");
	string s3(10, '&');
	string s4(s2);
	//string类支持c++标准的输入输出
	cin >> s1;
	cout << s1 << endl;
	//遍历字符串的方式
	for (auto e : s2)
		cout << e << " ";
	cout << endl;
	for (size_t i = 0;i < s3.size();i++) {
		cout << s3[i] << " ";
	}
	cout << endl;
	//采用迭代器遍历---很少使用
	//迭代器：当成一种指针
	//string：[begin,end)---begin代表首字符的位置  end代表最后一个有效字符下一个位置
	//string::iterator it = s4.begin();
	auto it = s4.begin();
	while (it != s4.end()) {
		cout << *it;
		it++;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
//capacity相关
int main() {
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "notempty" << endl;
	}
	return 0;
}
#endif

// void resize(size_t n,char ch):将string类中有效字符改变为n个，多出来的位置用ch填充
//resize功能：改变string类中有效字符的个数
//将有效字符个数增多到n个，多出的位置需要使用ch进行填充（可能需要扩容）
//将有效字符个数减少到n个：只修改有效字符的个数，不会缩小空间
#if 0
int main() {
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//扩增s中有效字符的个数
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(20, '&');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//减少s中有效字符的个数
	s.resize(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
#endif

#if 0
//扩容：
//void reserve(size_t n):改变底层容量的大小，不会修改有效元素个数
//1.扩大容量：n<=旧空间大小  不会扩容 n>旧空间大小  扩容
//2.缩小：n>15不会缩小 n<=15缩小容量
int main() {
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(80);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(6);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
#endif

#if 0
int main() {
	string s1;
	s1.resize(10, '&');
	s1[0] = '$';
	string s2;
	s2.reserve(10);
	s2[0] = '%';
	return 0;
}
#endif

#if 0
int main() {
	string s("hello");
	cout << s << endl;
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main() {
	string s1;
	s1 += 'I';
	string s2(" love ");
	s1 += s2;
	s1 += "you ";
	string s3("very");
	s1.append(s3);
	s1.append(6, '.');
	cout << s1 << endl;
	return 0;
}
#endif

#if 0
int main() {
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0;i < 100;i++) {
		s.push_back('c');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
	return 0;
}
#endif

#if 0
int main() {
	string s1("IYou");
	cout << s1 << endl;
	s1.insert(1, " Love ");
	cout << s1 << endl;
	string s2("very");
	s1.insert(10, s2);
	cout << s1 << endl;
	s1.erase(s1.begin() + s1.find('e'), s1.end());
	cout << s1 << endl;
	return 0;
}
#endif

#if 0
int main() {
	string s("111.txt");
	string ret=s.substr(s.rfind('.')+1);
	cout << ret << endl;
	string strnet("https://www.baidu.com/s?asdfghj//hjk");
	size_t pos=strnet.find(':') + 3;
	if (pos != string::npos) {
		cout << "is in" << endl;
	}
	else {
		cout << "is not in" << endl;
	}
	string Ret=strnet.substr(pos,strnet.find('/',pos) - pos);
	cout << Ret << endl;
	return 0;
}
#endif

int main() {
	string s;
	getline(cin, s);
	cout << s.substr(s.rfind(' ') + 1).size() << endl;
	return 0;
}