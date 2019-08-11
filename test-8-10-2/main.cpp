#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<stdlib.h>
int main() {
	SeqList seqList;
	seqList.SeqListPushFront(1);
	seqList.SeqListPushFront(2);
	seqList.SeqListPushFront(3);
	seqList.SeqListPushFront(4);
	seqList.SeqListprint();
	seqList.SeqListPushBack(10);
	seqList.SeqListPushBack(20);
	seqList.SeqListPushBack(30);
	seqList.SeqListPushBack(40);
	seqList.SeqListprint();
	seqList.SeqListPopFront();
	seqList.SeqListprint();
	seqList.SeqListPopBack();
	seqList.SeqListprint();
	seqList.SeqlistInsert(0, 0);
	seqList.SeqListprint();
	seqList.SeqListErase(8);
	seqList.SeqListprint();
	system("pause");
	return 0;
}