#pragma once
typedef struct SeqList
{
	int* array;
	int capacity;
	int size;
}SeqList;
//��ʼ��
void SeqListInit(SeqList* seq);
//����
void SeqListDestroy(SeqList* seq);
//ͷ��
void SeqListpushFront(SeqList* seq,int val);
//β��
void SeqListpushBack(SeqList* seq,int val);
//ͷɾ
void SeqListPopFront(SeqList* seq);
//βɾ
void SeqListPopBack(SeqList* seq);
//�±��
void SeqListInsert(SeqList* seq, int index, int val);
//�±�ɾ
void SeqListErase(SeqList* seq, int index);
//��ӡ
void SeqListprint(SeqList* seq);