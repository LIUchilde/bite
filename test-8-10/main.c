#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int main() {
	SeqList seqList;
	SeqListInit(&seqList);
	SeqListpushFront(&seqList, 1);
	SeqListpushFront(&seqList, 2);
	SeqListpushFront(&seqList, 3);
	SeqListpushFront(&seqList, 4);
	SeqListprint(&seqList);
	SeqListpushBack(&seqList, 10);
	SeqListpushBack(&seqList, 20);
	SeqListpushBack(&seqList, 30);
	SeqListpushBack(&seqList, 40);
	SeqListprint(&seqList);
	SeqListInsert(&seqList, 4,0);
	SeqListprint(&seqList);
	SeqListErase(&seqList, 5);
	SeqListprint(&seqList);
	SeqListPopFront(&seqList);
	SeqListprint(&seqList);
	SeqListPopBack(&seqList);
	SeqListprint(&seqList);
	system("pause");
	return 0;
}