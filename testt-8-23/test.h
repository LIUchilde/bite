#pragma once
//void printArray(int a[], int size);
//void insertsort(int a[], int size);
//void shellsort(int a[], int size);
//void selectsort(int a[], int size);
//void heapsort(int a[], int size);
//void bubblesort(int a[], int size);
//void quicksort1(int a[], int size);
//void quicksort2(int a[], int size);
//void quicksort3(int a[], int size);
//void Mergesort(int a[], int size);

#define stack_size 100
typedef int DataType;
typedef struct stack {
	DataType arr[stack_size];
	int top;
}stack;
typedef struct Node {
	int val;
	struct Node* next;
}pNode;
typedef struct queue {
	pNode* rear;
	pNode* front;
}Queue;
typedef char TypeData;
typedef struct BinaryTreeNode {
	TypeData val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}Node;
void stackInit(stack* s);
int IsEmpty(stack* s);
void push(stack* s,DataType val);
int pop(stack* s);
int Top(stack* s);
void destroy(stack* s);
void QueueInit(Queue* q);
void Queuedestroy(Queue* q);
void Queuepush(Queue* q, int val);
int Queuepop(Queue* q);
void QueueIsEmpty(Queue* q);
void Queueprint(Queue* q);
Node* creatBinaryTree(TypeData* a);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
void preOrderNor(Node* root);
void inOrderNor(Node* root);
void postOrderNor(Node* root);
int getNodecount(Node* root);
int getHeight(Node* root);
int getleafcount(Node* root);
int getkleafcount(Node* root, int k);
Node* find(Node* root, char v);

