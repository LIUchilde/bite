#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include"test.h"
//double Box::getvolum() {
//	return length * breadth * heigth;
//}
//void Box::setLength(double len) {
//	length = len;
//}
//void Box::setBreadth(double bre) {
//	breadth = bre;
//}
//void Box::setHeigth(double hei) {
//	heigth = hei;
//}
//int main() {
//	Box b;
//	b.setLength(1.0);
//	b.setBreadth(2.0);
//	b.setHeigth(3.0);
//	cout<<b.getvolum()<<endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
//void Line::setLength(double len) {
//	length = len;
//}
//double Line::getLength() {
//	return length;
//}
//int main() {
//	Line line;
//	//设置长度
//	line.setLength(1.0);
//	cout << line.getLength() << endl;
//	//不使用成员函数设置长度
//	line.length = 2.0;
//	cout << line.length << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
//double Box::getwidth() {
//	return width;
//}
//void Box::setwidth(double wid) {
//	width = wid;
//}
//int main() {
//	Box b;
//	//不使用成员函数设置长度
//	b.length=1.0;
//	cout << b.length << endl;
//	//不使用成员函数设置宽度
//	//b.width = 2.0;  Error :因为width是私有的；
//	//使用成员函数设置宽度
//	b.setwidth(2.0);
//	cout << b.getwidth() << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
////成员函数定义，包括构造函数
//void Line::setLine(double line) {
//	length = line;
//}
//double Line::getLine() {
//	return length;
//}
//Line::Line() {
//	cout << "Object is being created" << endl;
//}
////主函数
//int main() {
//	Line line;
////使用成员函数设置长度
//	line.setLine(1.0);
//	cout << line.getLine() << endl;
//	system("pause");
//	return 0;
//}

////默认的构造函数没有参数，但如果需要，构造函数也可以带参数。这样在创建对象是就会给对象赋初始值，如下例：
//#include"test.h"
////成员函数定义，包括构造函数
//Line::Line(double len) {
//	length = len;
//	cout << "object is being created,len=" << len << endl;
//}
//void Line::setLine(double len) {
//	length = len;
//}
//double Line::getLine() {
//	return length;
//}
//int main() {
//	Line line(1.0);
//	//获取默认设置的长度
//	cout << "length of line " << line.getLine() << endl;
//	//使用成员函数设置长度
//	line.setLine(2.0);
//	cout << "length of line " << line.getLine() << endl;
//	system("pause");
//	return 0;
//}

//拷贝构造函数
//#include"test.h"
//Cexample::Cexample(int a) {
//	b = a;
//}
//void Cexample::show() {
//	cout << b << endl;
//}
//int main() {
//	Cexample A(100);
//	Cexample B(A);
//	B.show();
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Cexample::Cexample(int a) {
//	b = a;
//}
//Cexample::Cexample(const Cexample& c) {
//	b = c.b;
//}
//void Cexample::show() {
//	cout << b << endl;
//}
//int main() {
//	Cexample A(100);
//	Cexample B(A);
//	B.show();
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//Date::Date(const Date& d) {
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//void Date::show() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d1(1990, 1, 1);
//	Date d2(d1);
//	d2.show();
//	system("pause");
//	return 0;
//}

//析构函数
//#include"test.h"
//Line::Line() {
//	cout << "object is being created" << endl;
//}
//Line::~Line() {
//	cout << "object is being delected" << endl;
//}
//void Line::setLine(double len) {
//	length = len;
//}
//double Line::getLine() {
//	return length;
//}
//int main() {
//	Line line;
//	line.setLine(1.0);
//
//	cout << line.getLine() << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
//#include<assert.h>
//#include<malloc.h>
//typedef int DataType;
//SeqList::SeqList(int capacity=10) {
//	_array = (DataType*)malloc(capacity * sizeof(DataType));
//	assert(_array);
//	_capacity = capacity;
//	_size = 0;
//}
//SeqList::~SeqList() {
//	if (_array) {
//		free(_array);
//		_array = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//void SeqList::TestSeqList() {
//
//}
//int main() {
//	SeqList s;
//	s.TestSeqList();
//	system("pause");
//	return 0;
//}





