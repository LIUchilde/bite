#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"test.h"
template<class T>
void PrintList(bite::list<T>& l) {
	auto it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestList() {
	bite::list<int>l1;
	bite::list<int>l2(10, 5);
	PrintList(l2);
	int array[] = { 1,2,3,4,5,6 };
	bite::list<int>l3(array, array + sizeof(array) / sizeof(array[0]));
	bite::list<int>l4(l3);
	PrintList(l3);
	PrintList(l4);
}
int main() {
	TestList();
	return 0;
}