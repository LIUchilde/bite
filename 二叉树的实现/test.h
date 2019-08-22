#pragma once

typedef char TypeData;
typedef struct BinaryTreeNode {
	TypeData val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}Node;
#define stack_size 100
typedef int DataType;
typedef struct stack {
	DataType arr[stack_size];
	int top;
}stack;
void stackInit(stack* s);
int IsEmpty(stack* s);
void push(stack* s,DataType val);
int pop(stack* s);
int Top(stack* s);
Node* creatBinaryTree(TypeData *a);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
void preOrderNor(Node* root);
void inOrderNor(Node* root);
void postOrderNor(Node* root);

