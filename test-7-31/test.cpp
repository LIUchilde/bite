#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include"test.h"
////无参构造函数
//Date::Date() {
//}
////带参构造函数
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//int main() {
//	Date d1;//调用无参构造函数
//	Date d2(1990, 1, 1);//调用含参构造函数
//}

//#include"test.h"
////如果用户显式定义了构造函数，编译器将不再生成
////Date::Date(int year, int month, int day) {
////	_year = year;
////	_month = month;
////	_day = day;
////}
//int main() {
//	//没有定义构造函数，对象也可以生成成功，因此此处调用的是编译器生成的默认构造函数
//	Date d;
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
//void Date::print() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d1(1990, 1, 1);
//	Date d2(d1);
//	d1.print();
//	d2.print();
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//Date& Date::operator=(const Date& d) {
//	if (this != &d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	return *this;
//}
//void Date::print() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d1(1990, 1, 1);
//	Date d2(2000, 1, 1);
//	d1.print();
//	d2.print();
//	d1 = d2;
//	d1.print();
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Date* Date::operator&() {
//	return this;
//}
//const Date* Date::operator&()const {
//	return this;
//}