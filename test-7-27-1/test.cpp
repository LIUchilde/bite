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
//	//���ó���
//	line.setLength(1.0);
//	cout << line.getLength() << endl;
//	//��ʹ�ó�Ա�������ó���
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
//	//��ʹ�ó�Ա�������ó���
//	b.length=1.0;
//	cout << b.length << endl;
//	//��ʹ�ó�Ա�������ÿ��
//	//b.width = 2.0;  Error :��Ϊwidth��˽�еģ�
//	//ʹ�ó�Ա�������ÿ��
//	b.setwidth(2.0);
//	cout << b.getwidth() << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
////��Ա�������壬�������캯��
//void Line::setLine(double line) {
//	length = line;
//}
//double Line::getLine() {
//	return length;
//}
//Line::Line() {
//	cout << "Object is being created" << endl;
//}
////������
//int main() {
//	Line line;
////ʹ�ó�Ա�������ó���
//	line.setLine(1.0);
//	cout << line.getLine() << endl;
//	system("pause");
//	return 0;
//}

////Ĭ�ϵĹ��캯��û�в������������Ҫ�����캯��Ҳ���Դ������������ڴ��������Ǿͻ�����󸳳�ʼֵ����������
//#include"test.h"
////��Ա�������壬�������캯��
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
//	//��ȡĬ�����õĳ���
//	cout << "length of line " << line.getLine() << endl;
//	//ʹ�ó�Ա�������ó���
//	line.setLine(2.0);
//	cout << "length of line " << line.getLine() << endl;
//	system("pause");
//	return 0;
//}

//�������캯��
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

//��������
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





