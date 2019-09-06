#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int main() {
	//string s1;
	//string s2("hello");
	//string s3(nullptr);
	//string s4(s2);
	////自己不实现，编译器自动生成的拷贝，为浅拷贝，字节拷贝，将s2对象
	////中的内容原封不动的拷贝到s4中，s2和s4用同一个内存空间
	////浅拷贝后果：同一份资源被释放多次而引起代码崩溃
	////解决方式：采用深拷贝的方式解决，拷贝资源中的内容
	string s1("hello");
	string s2(s1);
	//深拷贝：每个对象都有自己独立的资源，拷贝的是资源中的内容
	//如果类中涉及到资源管理：用户必须显式提供拷贝构造函数以及赋值运算符重载
	string s3("word");
	s1 = s3;
	//系统提供的默认的赋值运算符重载：1.浅拷贝 2.资源泄露
	return 0;
}