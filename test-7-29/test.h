#pragma once
//class Box {
//public:
//	double getvolume();
//	void setLength(double len);
//	void setbraedth(double bre);
//	void setHeigth(double hei);
//	Box operator+(const Box& b);
//private:
//	double _length;
//	double _braedth;
//	double _heigth;
//};

//class Date {
//public:
//	Date(int year,int month,int day);
//	Date(const Date& d);
//	Date& operator=(const Date& d);
//	void TestDate();
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date {
//public:
//	void Display();
//	void Display()const;
//private:
//	int year;
//	int month;
//	int day;
//};

//class Date {
//public:
//	Date(int year, int month, int day);
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Time {
//public:
//	Time(int hour);
//private:
//	int _hour;
//};
//class Date {
//public:
//	Date(int year);
//private:
//	int _year;
//	Time _t;
//};

//class Box {
//public:
//	static int count;
//	double volume();
//	Box(double len, double bra, double hei);
//
//private:
//	double _length;
//	double _braedth;
//	double _heigth;
//};

class Box {
public:
	static int count;
	Box(double len, double braedth, double heigth);
	double volume();
    static int getcount();
private:
	double _length;
	double _braedth;
	double _heigth;
};
