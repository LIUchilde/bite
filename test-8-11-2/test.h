#pragma once
typedef struct Node {
	int val;
	struct Node* next;
}Node;
Node* ListPushFront(Node* head, int val);
Node* ListPushBack(Node* head, int val);
Node* ListPopFront(Node* head);
Node* ListPopBack(Node* head);
Node* ListInsert(Node* head, int index, int val);
Node* ListErase(Node* head, int val);
Node* reserve(Node* head);
Node* FindMidNode(Node* head);//找到中间结点

Node* Listprint(Node* head);

