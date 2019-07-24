#define  _CRT_SECURE_NO_WARNINGS 1
#include"Test.h"
#include<iostream>
using namespace std;
inline int Test::max()
{
	return a > b ? a : b;
}
int main() {
	Test a(3, 5);
	cout << a.max() << endl;
	system("pause");
	return 0;
}