#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node {
	int val;
	struct Node* next;
}Node;
typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;
int length = 0;
//���г�ʼ��
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
}
//��β�����
void QueuePush(Queue* q, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	if (q->front == NULL) {
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
	length++;
}
//��ͷ������
void QueuePop(Queue* q) {
	assert(q->front != NULL);
	Node* next = q->front->next;
	if (q->front == q->rear) {
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
//��ȡ��ͷԪ��
int QueueFront(Queue* q) {
	assert(q->front != NULL);
	return q->front->val;
}
//��ȡ��βԪ��
int Queuerear(Queue* q) {
	assert(q->front != NULL);
	return q->rear->val;
}
//��������ӡ����
void QueueTraverse(Queue* q) {
	Node* node = q->front;
	while (node!= q->rear) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("%d ", q->rear->val);
}
//�ж϶�����Ԫ�ظ���
int sizeQueue(Queue* q) {
	return length;
}
//�ж϶����Ƿ�Ϊ��
void isEmpty(Queue* q) {
	if (q->front==NULL) {
		printf("����Ϊ��");
	}
	else {
		printf("���в�Ϊ��");
	}
	return;
}
//���ٶ���
void DestroyQueue(Queue*q) {
	Node* cur = q->front;
	Node* next = cur->next;
	assert(q->front);
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	return;
}
int main() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d ", QueueFront(&q));printf("\n");
	printf("%d ", Queuerear(&q));printf("\n");
	printf("%d ", sizeQueue(&q));printf("\n");
	QueuePop(&q);
	QueueTraverse(&q);
	isEmpty(&q);printf("\n");
	DestroyQueue(&q);printf("\n");
	system("pause");printf("\n");
	return 0;
}





