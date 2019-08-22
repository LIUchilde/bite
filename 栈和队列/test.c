#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define stack_size 100
typedef int DataType;
typedef struct stack {
	DataType arr[stack_size];
	int top;
}stack;
void stackInit(stack*s) {
	s->top = 0;
}
int IsEmpty(stack* s) {
	return s->top == 0;
}
int Isfull(stack* s) {
	return s->top == stack_size - 1;
}
void push(stack* s, DataType val) {
		s->arr[s->top] = val;
		s->top++;
}
int Pop(stack* s) {
	
	return s->arr[--s->top];
	
}
int top(stack* s) {
	if (s->top == 0) {
		printf("栈空");
		return 0;
	}
	return s->arr[s->top - 1];
}
int main() {
	stack s;
	stackInit(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	printf("%d", s.arr[0]);
	printf("\n");
	printf("%d", s.top);
	printf("\n");
	printf("%d ",top(&s));
	printf("\n");
	while(!IsEmpty(&s)) {
		printf("%d ",Pop(&s));	
	}
	top(&s);
	system("pause");
	return 0;
}


//#define length 10
//#include<assert.h>
//typedef struct Node {
//	int val;
//	struct Node* next;
//}Node;
//typedef struct Queue {
//	Node* front;
//	Node* rear;
//}Queue;
//void QueueInit(Queue* q) {
//	q->front = q->rear = NULL;
//}
//void QueuePush(Queue* q, int val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->val = val;
//	node->next = NULL;
//	if (q->front == NULL) {
//		q->front = node;
//	}
//	else {
//		q->rear->next = node;
//	}
//	q->rear = node;
//}
//int QueuePop(Queue* q) {
//	assert(q->front != NULL);
//	Node* second = q->front->next;
//	int val = q->front->val;
//	free(q->front);
//	q->front = second;
//	if (q->front == NULL) {
//		q->rear = NULL;
//	}
//	return val;
//}
//void IsEmpty(Queue* q) {
//	if (q->front==NULL) {
//		printf("队空");
//	}
//	else {
//		printf("队不为空");
//	}
//}
//void Queueprint(Queue* q) {
//	Node* cur = q->front;
//	while (cur) {
//		printf("%d ", cur->val);
//		cur = cur->next;
//	}
//}
//void QueueDestroy(Queue* q) {
//	while (q->front) {
//		Node* next = q->front;
//		free(q->front);
//		q->front = next;
//	}
//}
//int main() {
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	Queueprint(&q);
//	printf("\n");
//	QueuePop(&q);
//	Queueprint(&q);
//	printf("\n");
//	IsEmpty(&q);
//	printf("\n");
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	IsEmpty(&q);
//	QueueDestroy(&q);
//	system("pause");
//	return 0;
//}

