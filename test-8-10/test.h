#pragma once
typedef struct SeqList
{
	int* array;
	int capacity;
	int size;
}SeqList;
//初始化
void SeqListInit(SeqList* seq);
//销毁
void SeqListDestroy(SeqList* seq);
//头插
void SeqListpushFront(SeqList* seq,int val);
//尾插
void SeqListpushBack(SeqList* seq,int val);
//头删
void SeqListPopFront(SeqList* seq);
//尾删
void SeqListPopBack(SeqList* seq);
//下标插
void SeqListInsert(SeqList* seq, int index, int val);
//下标删
void SeqListErase(SeqList* seq, int index);
//打印
void SeqListprint(SeqList* seq);