#pragma once
class Date {
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day);
	Date(const Date& d);
	bool Isleapyear();
	int GetMonthDays(int month);
	Date& operator=(const Date& d);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(const Date& d);
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
