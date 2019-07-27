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
//队列初始化
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
}
//队尾入队列
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
//对头出队列
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
//获取对头元素
int QueueFront(Queue* q) {
	assert(q->front != NULL);
	return q->front->val;
}
//获取队尾元素
int Queuerear(Queue* q) {
	assert(q->front != NULL);
	return q->rear->val;
}
//遍历并打印队列
void QueueTraverse(Queue* q) {
	Node* node = q->front;
	while (node!= q->rear) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("%d ", q->rear->val);
}
//判断队列内元素个数
int sizeQueue(Queue* q) {
	return length;
}
//判断队列是否为空
void isEmpty(Queue* q) {
	if (q->front==NULL) {
		printf("队列为空");
	}
	else {
		printf("队列不为空");
	}
	return;
}
//销毁队列
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





