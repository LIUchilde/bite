#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"test.h"
Node* ListPushFront(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}
Node* ListPushBack(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	Node* cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = node;
	node->next = NULL;
	return head;
}
Node* ListPopFront(Node* head) {
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}
Node* ListPopBack(Node* head) {
	assert(head != NULL);
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	else {
		Node* cur = head;
		while (cur->next->next) {
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
		return head;
	}
}
Node* ListInsert(Node* head, int index, int val) {
	Node* cur = head;
	for (int i = 1;i < index-1 ;i++) {
		cur = cur->next;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = cur->next;
	cur->next = node;
	return head;
}
Node* ListErase(Node* head, int val) {
	Node* cur = head;
	while (cur) {
		if (cur->val == val) {
			cur->val = cur->next->val;
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
	return head;
}
Node* reserve(Node* head) {
	Node* next = NULL;
	Node* pre = NULL;
	while (head) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}
Node* FindMidNode(Node* head) {
	Node* pFast = head;
	Node* pSlow = head;
	while (pFast->next != 0 && pFast->next->next != 0) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
Node* Listprint(Node* head) {
	Node* p = head;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	return head;
}
int main() {
	Node* head = NULL;
	head=ListPushFront(head, 4);
	head = ListPushFront(head, 3);
	head = ListPushFront(head, 2);
	head = ListPushFront(head, 1);
	Listprint(head);
	printf("\n");
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	head = ListPushBack(head, 40);
	Listprint(head);
	printf("\n");
	head = ListPopFront(head);
	Listprint(head);
	printf("\n");
	head=ListPopBack(head);
	Listprint(head);
	printf("\n");
	head = ListInsert(head, 5, 5);
	Listprint(head);
	printf("\n");
	head = ListErase(head, 20);
	Listprint(head);
	printf("\n");
	head = reserve(head);
	Listprint(head);
	printf("\n");
	head = FindMidNode(head);
	system("pause");
	return 0;
}
