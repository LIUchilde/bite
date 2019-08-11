#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include<assert.h>
#define INIT_CAPACITY 100
static void ensurecapacity(SeqList* seq) {
	if (seq->size < seq->capacity) {
		return;
	}
	else {
		int newcapacity = 2 * seq->capacity;
		int* newarray = (int*)malloc(newcapacity * sizeof(int));
		for (int i = 0;i < seq->size;i++) {
			newarray[i] =seq->array[i];
		}
		free(seq->array);
		seq->array = newarray;
	}
}
//��ʼ��
void SeqListInit(SeqList* seq) {
	seq->array = (int*)malloc(sizeof(int) * INIT_CAPACITY);
	seq->capacity = INIT_CAPACITY;
	seq->size = 0;
}
//����
void SeqListDestroy(SeqList* seq) {
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
//ͷ��
void SeqListpushFront(SeqList* seq, int val) {
	for (int i = seq->size - 1;i >= 0;i--) {
		seq->array[i + 1] = seq->array[i];
	}
	 seq->array[0]=val;
	seq->size++;
}
//β��
void SeqListpushBack(SeqList* seq, int val) {
	 seq->array[seq->size]=val;
	seq->size++;
}
//ͷɾ
void SeqListPopFront(SeqList* seq) {
	assert(seq->size > 0);
	for (int i = 0;i < seq->size - 1;i++) {
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//βɾ
void SeqListPopBack(SeqList* seq) {
	assert(seq->size > 0);
	seq->size--;
}
//�±��
void SeqListInsert(SeqList* seq, int index, int val) {
	if (index < 0 || index>seq->size) {
		printf("�±겻�Ϸ�");
		return;
	}
	ensurecapacity(seq);
	for (int i = seq->size;i > index;i--) {
		seq->array[i] = seq->array[i-1];
	}
	seq->array[index] = val;
	seq->size++;
}
//�±�ɾ
void SeqListErase(SeqList* seq, int index) {
	assert(seq->size > 0);
	for (int i = index;i < seq->size - 1;i++) {
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//��ӡ
void SeqListprint(SeqList* seq) {
	for (int i = 0;i < seq->size;i++) {
		printf("%d ",seq->array[i]);
	}
	printf("\n");
}

