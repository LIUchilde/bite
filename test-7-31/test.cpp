#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include"test.h"
////�޲ι��캯��
//Date::Date() {
//}
////���ι��캯��
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//int main() {
//	Date d1;//�����޲ι��캯��
//	Date d2(1990, 1, 1);//���ú��ι��캯��
//}

//#include"test.h"
////����û���ʽ�����˹��캯��������������������
////Date::Date(int year, int month, int day) {
////	_year = year;
////	_month = month;
////	_day = day;
////}
//int main() {
//	//û�ж��幹�캯��������Ҳ�������ɳɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
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