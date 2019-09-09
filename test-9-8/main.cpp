#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<iostream>
using namespace std;
int main() {
	seqList<int>s;
	s.isImpty(s);
	s.seqListpushFront(s, 1);
	s.seqListpushFront(s, 2);
	s.seqListpushFront(s, 3);
	s.seqListpushFront(s, 4);
	s.seqListPrint(s);
	s.seqListpushBack(s, 10);
	s.seqListpushBack(s, 20);
	s.seqListpushBack(s, 30);
	s.seqListpushBack(s, 40);
	s.seqListPrint(s);
	s.seqListPopFront(s);
	s.seqListPrint(s);
	s.seqListPopBack(s);
	s.seqListPrint(s);
	s.isImpty(s);
	s.seqListInsert(s, 0, 0);
	s.seqListPrint(s);
	s.seqListErase(s, 0);
	s.seqListPrint(s);
	s.seqListReverse(s);
	s.seqListPrint(s);
	s.seqListFind(s, 10);
	s.seqListClear(s);
	s.isImpty(s);
	system("pause");
	return 0;
}