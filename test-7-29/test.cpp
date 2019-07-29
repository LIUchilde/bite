#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include"test.h"
//double Box:: getvolume() {
//	return _length * _braedth * _heigth;
//}
//void Box::setLength(double len) {
//	_length = len;
//}
//void Box::setbraedth(double bre) {
//	_braedth = bre;
//}
//void Box::setHeigth(double hei) {
//	_heigth = hei;
//}
//Box Box::operator+(const Box& b) {
//	Box box;
//	box._length = this->_length + b._length;
//	box._braedth = this->_braedth + b._braedth;
//	box._heigth = this->_heigth + b._heigth;
//	return box;
//}
//int main() {
//	Box box1;
//	Box box2;
//	Box box3;
//	double volume = 0.0;
//	box1.setLength(1.0);
//	box1.setbraedth(2.0);
//	box1.setHeigth(3.0);
//	box2.setLength(4.0);
//	box2.setbraedth(5.0);
//	box2.setHeigth(6.0);
//	box3 = box1 + box2;
//	cout << "volume of box1=" << box1.getvolume() << endl;
//	cout << "volume of box2=" << box2.getvolume() << endl;
//	cout << "volume of box3=" << box3.getvolume() << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Date::Date(int year,int month,int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//Date::Date(const Date& d) {
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//Date& Date::operator=(const Date& d) {
//	if (this != &d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	return *this;
//}
//void Date::TestDate() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d1(1998, 10, 25);
//	Date d2(1998, 10, 26);
//	cout << "d1:"<< endl;
//	d1.TestDate();
//	cout << "d2:" << endl;
//	d2. TestDate();
//	d1 = d2;
//	cout << "d1:" << endl;
//	d1. TestDate();
//	system("pause");
//	return 0;
//}

//#include"test.h"
//void Date::Display() {
//	cout << year << "-" << month << "-" << day << endl;
//}
//void Date::Display()const {
//	cout << year << "-" << month << "-" << day << endl;
//}
//int main() {
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	 d2.Display();
//	 system("pause");
//	 return 0;
//}

//构造函数初始化列表
//#include"test.h"
//Date::Date(int year, int month, int day) 
//	:_year(year)
//		, _month(month)
//		, _day(day)
//{}
//int main() {
//	Date(1990, 1, 1);
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Time::Time(int hour)
//	:_hour(hour)
//{
//	cout << "Time()" << endl;
//}
//Date::Date(int year)
//	{}
//int main() {
//	Date d(1);
//	system("pause");
//	return 0;
//}
	
//#include"test.h"
//Box::Box(double len, double bra, double hei)
//	:_length(len)
//	, _braedth(bra)
//	, _heigth(hei)
//{
//	count++;
//}
//double Box::volume() {
//	return _length * _braedth * _heigth;
//}
//int Box::count = 0;
//int main() {
//	Box b1(1, 2, 3);
//	Box b2(4, 5, 6);
//	cout << b1.volume() << endl;
//	cout << b2.volume() << endl;
//	cout << Box::count << endl;
//}

#include"test.h"
double Box::volume() {
	return _length * _braedth * _heigth;
}
Box::Box(double len, double bra, double hei)
	:_length(len)
	, _braedth(bra)
	, _heigth(hei)
{
	count++;
}
int Box::getcount() {
	return count;
}
int Box::count = 0;
int main() {
	cout << Box::getcount() << endl;
	Box b1(1, 2, 3);
	Box b2(4, 5, 6);
	cout << b1.volume() << endl;
	cout << b2.volume() << endl;
	cout << Box::getcount() << endl;
	system("pause");
	return 0;
}










