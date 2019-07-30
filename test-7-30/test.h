#pragma once
//class Box {
//public:
//	void setwidth(double wid);
//	friend void printwidth(Box box);
//private:
//	double width;
//};
//class Date {
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, const Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year, int month, int day);
//};

//class Box {
//private:
//	double width;
//public:
//	void setwidth(double wid);
//	friend void printwidth(Box box);
//	friend class Bigbox;
//};
//class Bigbox {
//public:
//	void print(double width, Box& box);
//};

//class Date;
//class Time {
//	friend class Date;
//public:
//	Time(int hour, int minute, int second);
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date {
//public:
//	Date(int year, int month, int day);
//	void print(Time& t);
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A {
//private:
//	static int k;
//	int h=4;
//public:
//	class B {
//	public:
//		void print(const A&a);
//	};
//};
//int A::k = 3;
class Date {
	friend ostream& operator<<(ostream&_cout, const Date& d);
public:
	Date(int year, int month, int day);
	Date(const Date& d);
	bool Isleapyear();
	int GetMonthDays(int month);
	Date& operator=(const Date& d);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(const Date&d);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	bool operator==(Date& d);
	bool operator!=(Date& d);
	bool operator>(Date& d);
	bool operator<(Date& d);
private:
	int _year;
	int _month;
	int _day;
};
