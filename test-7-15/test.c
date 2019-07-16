#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node {
	int val;
	struct Node* next;
}Node;
void Listprint(Node* head) {
	for (Node* cur = head;cur != NULL;cur = cur->next) {
		printf("%d-->", cur->val);
	}
		printf("NULL\n");
	}
Node* ListpushFront(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}
Node* ListpushBack(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head != NULL) {
		Node* cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = node;
	}
	else {
		head = node;
	}
	return head;
}
Node* ListpopFront(Node* head) {
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}
Node* ListpopBack(Node* head) {
	Node* cur = head;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
	return head;
}
Node* reverseList(Node* head) {
	Node* rhead = NULL;
	Node* cur = head;
	while (cur != NULL) {
		Node* next = cur->next;
		cur->next = rhead;
		rhead = cur;
		cur = next;
	}
	return rhead;
}
//删除链表中相同的val值
Node* removeElement(Node* head, int val) {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* pre = head;
		Node* cur = head->next;
		while (cur != NULL) {
			if (cur->val == val) {
				pre->next = cur->next;
			}
			else {
				pre = cur;
			}
			cur = cur->next;
		}
		if (head->val == val) {
			return head->next;
		}
		return head;
	}
}
Node* removeElement_2(Node* head, int val) {
	Node* rhead = NULL;
	Node* cur = head;
	Node* last = NULL;
	while (cur != NULL) {
		Node* next = cur->next;
		if (cur->val != val) {
			if (rhead == NULL) {
				rhead = cur;
			}
			else {
				cur->next = NULL;
				last ->next = cur;
			}
			last = cur;
		}
		cur = next;
	}
	return rhead;
}
Node* mergetwoList(Node* l1, Node* l2) {
	Node* rhead = NULL;
	Node* last = NULL;
	Node* c1 = l1;
	Node* c2 = l2;
	if (l1 == NULL)
	{
		return l2;
	}
	else {
		return l2;
	}
	while (l1 != NULL && l2 != NULL) {
		
		if (c1->val <= c2->val) {
			Node* next = c1->next;
			c1->next = NULL;
			if (rhead == NULL) {
				rhead = c1;
			}
			else {
				last->next = c1;
			}
			last = c1;
			c1 = next;
		}
		else {
			Node* next = c2->next;
			c1->next = NULL;
			if (rhead == NULL) {
				rhead = c2;
			}
			else {
				last->next = c2;
			}
			last = c2;
			c2 = next;
		}
	}
	if (c1 != NULL) {
		last->next = c1;
	}
	else {
		last->next = c2;
	}
	return rhead;
}
int main()
{
	Node* head = NULL;
	Listprint(head);
	head = ListpushFront(head, 1);
	Listprint(head);
	head = ListpushFront(head, 2);
	Listprint(head);
	head=ListpushFront(head, 3);
	Listprint(head);
	head = ListpushBack(head, 10);
	head = ListpushBack(head, 20);
	head = ListpushBack(head, 30);
	Listprint(head);
	head = ListpopFront(head);
	head = ListpopFront(head);
	Listprint(head);
	head = ListpopBack(head);
	Listprint(head);
	head = reverseList(head);
	Listprint(head);
	head = ListpushFront(head, 20);
	Listprint(head);
	head = removeElement(head, 20);
	Listprint(head);
	head = ListpushFront(head, 10);
	Listprint(head);
	head = removeElement_2(head, 10);
	Listprint(head);
}

