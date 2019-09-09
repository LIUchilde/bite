#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<iostream>
using namespace std;
int main() {
	String s1;
	String s2("hello");
	String s3(s2);
	String s4("world");
	s2=s4;
	s2.operator+=('s');
	s3.operator+=(" world ");
	s4.operator+=(s3);
	return 0;
}