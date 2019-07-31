#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"test.h"
//������������
ostream& operator<<(ostream& _cout, const Date& d) {
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
//���캯��
Date::Date(int year, int month, int day)
	:_year(year)
	, _month(month)
	, _day(day)
{
	//�������ڵĺϷ����ж�
	if (!(year > 0) && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDays(_month))) {
		_year = 1990;
		_month = 1;
		_day = 1;
	}
}
//�������캯��
Date::Date(const Date& d)
	:_year(d._year)
	, _month(d._month)
	, _day(d._day)
{}
//�ж��Ƿ�����
bool Date::Isleapyear() {
	if (((_year % 4 == 0) && (_year % 100 != 0)) || _year % 400 == 0) {
		return true;
	}
	return false;
}
//��ȡÿ������
int Date::GetMonthDays(int month) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Isleapyear() && 2 == month)
	{
		days[month] += 1;
	}
	return days[month];
}
//��ֵ���������
Date& Date::operator=(const Date& d) {
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//һ�����ڼ���һ������
Date Date::operator+(int day) {
	if (day < 0) {//������Ϊ������Ϊ��
		return *(this - (0 - day));
	}
	Date temp(*this);
	temp._day += day;
	int daysInMonth = temp.GetMonthDays(temp._month);
	while (temp._day > daysInMonth) {
		temp._day -= daysInMonth;
		temp._month += 1;
		if (temp._month > 12) {
			temp._year += 1;
			temp._month = 1;
		}
	}
	return temp;
}
//һ�����ڼ���һ������
Date Date::operator-(int day) {
	if (day < 0) {
		return (*this + (0 - day));//������Ϊ������Ϊ��
	}
	Date temp(*this);
	temp._day -= day;
	while (temp._day < 0) {
		temp._month--;
		if (temp._month < 0) {
			temp._year -= 1;
			temp._month = 12;
		}
		temp._day += temp.GetMonthDays(temp._month);
	}
	return temp;
}
//�����������������
int Date::operator-(const Date& d) {
	Date maxdate(*this);
	Date mindate(d);
	if (maxdate < mindate) {
		maxdate = mindate;
		mindate = *this;
	}
	int count = 0;
	while (maxdate > mindate) {
		mindate = mindate + 1;
		count+=1;
	}
	return count;
}
//ǰ��++
Date Date::operator++() {
	*this = *this + 1;
	return *this;
}
//����++
Date Date ::operator++(int) {
	Date temp(*this);
	*this = *this + 1;
	return temp;
}
//ǰ��--
Date Date::operator--() {
	*this = *this - 1;
	return *this;
}
//����--
Date Date::operator--(int) {
	Date temp(*this);
	*this = *this - 1;
	return temp;
}
//�ж����������
bool Date::operator==(Date& d) {
	if ((_year == d._year) && (_month == d._month) && (_day == d._day)) {
		return true;
	}
	return false;
}
//�ж������ڲ����
bool Date::operator!=(Date& d) {
	return!(*this == d);
}
//�жϴ�С
bool Date::operator>(Date& d) {
	if ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month > d._month) && (_day > d._day))) {
		return true;
	}
	return false;
}
//�жϴ�С
bool Date::operator<(Date& d) {
	return !(*this > d || *this == d);
}
int main() {
	Date d1(2019, 7, 30);
	cout << d1 << endl;
	cout << ++d1 << endl;
	cout << --d1 << endl;
	cout << d1 << endl;
	cout << d1++ << endl;
	cout << d1-- << endl;
	cout << d1 << endl;
	Date d2(2019, 7, 31);
	cout << d2 + 100 << endl;
	cout << d2 - 100 << endl;
	cout << d2 - d1 << endl;
	system("pause");
	return 0;
}