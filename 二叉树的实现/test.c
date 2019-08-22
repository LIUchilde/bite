#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"test.h"
//Node* creatBinaryTree(TypeData*a) {
//	static int n = 0;
//	if (a[n] == '#') {
//		n++;
//		return NULL;
//	}
//		Node*cur = (Node*)malloc(sizeof(Node));
//		cur->val = a[n];
//		n++;
//		cur->left = creatBinaryTree(a);
//		cur->right = creatBinaryTree(a);
//		return cur;
//}
Node* creatBinaryTree(TypeData* src) {
	static int n = 0;
	if (src[n] == '#') {
		n++;
		return NULL;
	}
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->val = src[n];
	n++;
	cur->left = creatBinaryTree(src);
	cur->right = creatBinaryTree(src);
	return cur;
}
void preOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	printf("%c ", root->val);
	inOrder(root->right);
}
void postOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->val);
}
void stackInit(stack* s) {
	s->top = 0;
}
int IsEmpty(stack* s) {
	return s->top == 0;
}
void push(stack* s,DataType val) {
	s->arr[s->top] = val;
	s->top++;
}
int pop(stack* s) {
	return s->arr[--s->top];
}
int Top(stack* s) {
	if (s->top == 0) {
		printf("Õ»¿Õ");
		return 0;
	}
	return s->arr[s->top - 1];
}
void preOrderNor(Node* root) {
	stack s;
	stackInit(&s);
	Node* cur = root;
	while (cur != NULL || !IsEmpty(&s)) {
		while (cur != NULL) {
			printf("%c ", cur->val);
			push(&s, cur);
			cur = cur->left;
		}
		Node* top = Top(&s);
		pop(&s);
		cur = top->right;
	}
}
void inOrderNor(Node* root) {
	stack s;
	stackInit(&s);
	Node* cur = root;
	while (cur != NULL || !IsEmpty(&s)) {
		while (cur != NULL) {
			push(&s, cur);
			cur = cur->left;
		}
		Node* top = Top(&s);
		printf("%c ", top->val);
		pop(&s);
		cur = top->right;
	}
}
