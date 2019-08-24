#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include"test.h"
//void ListInit(Node* head) {
//	 head = NULL;
//}
//void ListDestroy(Node* head) {
//	if (head == NULL) {
//		return;
//	}
//	while (head) {
//		Node*next = head->next;
//		free(head);
//		head = next;
//	}
//}
//Node* ListPushFront(Node* head, DataType val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = val;
//	node->next = head;
//	head = node;
//	return node;
//}
//Node* ListPushBack(Node* head, DataType val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = val;
//	Node* cur = head;
//	while (cur->next) {
//		cur = cur->next;
//	}
//	cur->next = node;
//	node->next = NULL;
//	return head;
//}
//Node* Listinsert(Node* head,int index, DataType val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = val;
//	Node* cur = head;
//	for (int i = 0;i < index-1;i++) {
//		cur = cur->next;
//	}
//	node->next = cur->next;
//	cur->next = node;
//	return head;
//}
//Node* ListPopFront(Node* head) {
//	assert(head != NULL);
//	Node* next = head->next;
//	free(head);
//	head = next;
//	return head;
//}
//Node* ListPopBack(Node* head) {
//	Node* cur = head;
//	while (cur->next->next) {
//		cur = cur->next;
//	}
//	cur->next = NULL;
//	return head;
//}
//Node* ListErase(Node* head,int index) {
//	if (index == 0) {
//		return ListPopFront(head);
//	}
//	Node* cur = head;
//	for (int i = 0;i < index - 1;i++) {
//		cur = cur->next;
//	}
//	Node* next = cur->next;
//	cur->next = next->next;
//	free(next);
//	return head;
//}
//Node* ListRemove(Node* head, DataType val) {
//	if (head == NULL) {
//		return NULL;
//	}
//	Node* node = (Node*)malloc(sizeof(Node));
//	Node* rhead = NULL;
//	Node* cur = head;
//	while (cur) {
//		if (cur->data == val) {
//			if (rhead == NULL) {
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else {
//				rhead->next = cur->next;
//				free(cur);
//				cur = rhead->next;
//			}
//		}
//		else {
//			rhead = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//void ListClear(Node* head) {
//	if (head == NULL) {
//		return;
//	}
//	while (head) {
//		Node* next = head->next;
//		free(head);
//		head = next;
//	}
//	head = NULL;
//}
//void ListIsEmpty(Node* head) {
//	if (head == NULL) {
//		printf("链表为空");
//	}
//	else {
//		printf("链表不为空");
//	}
//}
//void Listprint(Node* head) {
//	for (Node* cur = head;cur != NULL;cur = cur->next) {
//		printf("%d-->", cur->data);
//	}
//	printf("NULL\n");
//}