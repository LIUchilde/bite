#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"test.h"
int main() {
	SeqList<int> seqList;
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
	seqList.SeqListPopFront();
	seqList.SeqListprint();
	seqList.SeqListPopBack();
	seqList.SeqListprint();
	seqList.SeqListInsert(0, 0);
	seqList.SeqListprint();
	seqList.SeqListerase(5);
	seqList.SeqListprint();
	seqList.Find(1);
	seqList.Find(100);
	seqList.delete_val(1);
	seqList.SeqListprint();
	seqList.length();
	seqList.reserve();
	seqList.SeqListprint();
	seqList.reserve();
	seqList.SeqListprint();
	seqList.clear();
	seqList.SeqListprint();
	seqList.length();
	return 0;
}