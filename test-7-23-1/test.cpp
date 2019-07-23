#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//void testfunc() {
//	int a = 10;
//	int& ra = a;
//	cout << &a << endl;
//	cout << &ra << endl;
//}
//int main() {
//	testfunc();
//	system("pause");
//	return 0;
//}
//void TestFunc() {
//	int a = 10;
//	int& ra = a;
//	ra = 100;
//	cout << a << endl;
//	cout << ra << endl;
//}
//int main() {
//	TestFunc();
//	system("pause");
//	return 0;
//}
//void testfunc() {
//	int a = 10;
//	int& ra = a;
//	int& rra = a;
//	cout << a << " " << ra << " " << rra << endl;//10 10 10
//	cout << &a << " " << &ra << " " << &rra << endl;//00AFFB04 00AFFB04 00AFFB04
//}
//int main() {
//	testfunc();
//	system("pause");
//	return 0;
//}
//void TestFunc() {
//	const int a = 10;
//	const int& ra = a;
//	const int& b = 10;
//	double d = 3.14;
//	const int& rd = d;
//	cout << a << " " << ra << " " << b << " " << d <<" "<<rd<< endl;
//	//10 10 10 3.14 3
//}
//int main() {
//	TestFunc();
//	system("pause");
//	return 0;
//}
//void swap(int& left, int& right) {
//	int t = left;
//	left = right;
//	right = t;
//}
//void TestFunc() {
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	cout << a << " " << b << endl;//20 10
//}
//int main() {
//	TestFunc();
//	system("pause");
//	return 0;
//}
//int& Add(int a, int b) {
//	int c = a + b;
//	return c;
//}
//int main() {
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}
//#include<time.h>
//struct A {
//	int a[10000];
//};
//void TestFunc1(A a) {
//
//}
//void TestFunc2(A& a) {
//
//}
//void TestRefAndvalue() {
//	A a;
//	//以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0;i < 10000;i++) {
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//	//以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0;i < 10000;i++) {
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//	//分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(int*)-time" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time" << end2 - begin2 << endl;
//}
//int main() {
//	for (int i = 0;i < 10;i++) {
//		TestRefAndvalue();
//	}
//	system("pause");
//	return 0;
//}
//#include<time.h>
//struct A {
//	int a[10000];
//};
//A a;
//A TestFunc1() {
//	return a;
//}
//A& TestFunc2() {
//	return a;
//}
//void TestReturnByRefOrvalue() {
//	//以值作为函数的返回类型
//	size_t begin1 = clock();
//	for (size_t i = 0;i < 10000;i++) {
//		TestFunc1();
//	}
//	size_t end1 = clock();
//	//以引用作为函数的返回类型
//	size_t begin2 = clock();
//	for (size_t i = 0;i < 10000;i++) {
//		TestFunc2();
//	}
//	size_t end2 = clock();
//	cout << "TestFunc1 time" << end1 - begin1 << endl;
//	cout << "TestFunc2 time" << end2 - begin2 << endl;
//}
//int main() {
//	for (int i = 0;i < 10;i++) {
//		TestReturnByRefOrvalue();
//	}
//	system("pause");
//	return 0;
//}

