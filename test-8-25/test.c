#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include"test.h"
//void DListNodeInit(pNode** head) {
//	pNode* node = (pNode*)malloc(sizeof(pNode));
//	node->next = node->pre = node;
//	*head = node;
//}
//void Clear(pNode* head) {
//	pNode* cur = head->next;
//	while (cur!=head) {
//		pNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	cur->next = cur;
//	cur->pre = cur;
//}
//void Destroy(pNode* head) {
//	Clear(head);
//	free(head);
//}
//void IsEmpty(pNode* head) {
//	if (head->next==head) {
//		printf("该双链表为空");
//		return;
//	}
//	printf("该双链表不为空");
//}
//void PushFront(pNode* head, DataType val) {
//	pNode* node = (pNode*)malloc(sizeof(pNode));
//	node->data = val;
//	node->pre = head;
//	node->next = head->next;
//	head->next->pre = node;
//	head->next = node;
//}
//void PushBack(pNode* head, DataType val) {
//	pNode* node = (pNode*)malloc(sizeof(pNode));
//	node->data = val;
//	node->pre = head->pre;
//	node->next = head;
//	head->pre->next = node;
//	head->pre = node;
//}
//void insert(pNode* head,int pos, DataType val) {
//	pNode* node = (pNode*)malloc(sizeof(pNode));
//	node->data = val;
//	pNode* cur = head->next;
//	for (int i = 0;i < pos - 1;i++) {
//		cur = cur->next;
//	}
//	node->next = cur->next;
//	node->pre = cur;
//	cur->next->pre = node;
//	cur->next = node;
//}
//void PopFront(pNode* head) {
//	pNode* temp = head->next;
//	temp->next->pre = head;
//	head->next = temp->next;
//	free(temp);
//}
//void PopBack(pNode* head) {
//	pNode* temp = head->pre;
//	head->pre = temp->pre;
//	temp->pre->next = head;
//	free(temp);
//}
//void Delete(pNode* head,int pos) {
//	pNode* cur = head->next;
//	for (int i = 0;i < pos - 1;i++) {
//		cur = cur->next;
//	}
//	pNode* temp = cur;
//	temp->pre->next = temp->next;
//	temp->next->pre = temp->pre;
//	free(temp);
//}
//void print(pNode* head) {
//	if (head->next == head) {
//		return;
//	}
//	pNode* cur = head->next;
//	while (cur != head) {
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}

#include<stdio.h>
#include<stdlib.h>
#include"test.h"
//Node* getIntersectionNode(Node* headA, Node* headB) {
//	if (headA == NULL || headB == NULL) {
//		return NULL;
//	}
//	Node* lastA = headA;
//	Node* lastB = headB;
//	int sizeA = 1;
//	int sizeB = 1;
//	while (lastA->next) {
//		lastA = lastA->next;
//		sizeA++;
//	}
//	while (lastB->next) {
//		lastB = lastB->next;
//		sizeB++;
//	}
//	if (lastA != lastB) {
//		return NULL;
//	}
//	Node* curA = headA;
//	Node* curB = headB;
//	int pos = sizeA - sizeB;
//	if (pos > 0) {
//		while (pos--) {
//			curA = curA->next;
//		}
//	}
//	else {
//		while (pos++) {
//			curB = curB->next;
//		}
//	}
//	while (curA != curB) {
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return curA;
//}

//typedef struct ListNode Node;
//struct ListNode* partition(struct ListNode* head, int x) {
//	Node* cur = head;
//	Node* rhead = NULL, * rcur = NULL, * lhead = NULL, * lcur = NULL;
//	while (cur) {
//		if (cur->val < x) {
//			if (rhead == NULL) {
//				Node* node = (Node*)malloc(sizeof(Node));
//				node->val = cur->val;
//				rhead=rcur = node;
//			}
//			else {
//				Node* node = (Node*)malloc(sizeof(Node));
//				node->val = cur->val;
//				rcur->next = node;
//				rcur = node;
//			}
//		}
//		else{
//			if (lhead == NULL) {
//				Node* node = (Node*)malloc(sizeof(Node));
//				node->val = cur->val;
//				lhead=lcur = node;
//			}
//			else {
//				Node* node = (Node*)malloc(sizeof(Node));
//				node->val = cur->val;
//				lcur->next = node;
//				lcur = node;
//			}
//		}
//		cur = cur->next;
//	}
//	if (rhead == NULL) {
//		return lhead;
//	}
//	if (lhead) {
//		lhead->next = NULL;
//	}
//	rcur->next = lhead;
//	return rhead;
//}

//bool hasCycle(struct ListNode* head) {
//	Node* pFast = head;
//	Node* pSlow = head;
//	while (pFast && pFast->next) {
//		pFast = pFast->next->next;
//		pSlow = pSlow->next;
//		if (pFast == pSlow) {
//			return true;
//		}
//	}
//	return false;
//}

//Node* detectCycle(Node* head) {
//	Node* pFast = head;
//	Node* pSlow = head;
//	Node* cur = head;
//	while (pFast && pFast->next) {
//		pFast = pFast->next->next;
//		pSlow = pSlow->next;
//		if (pFast == pSlow) {
//			while (cur != pSlow) {
//				cur = cur->next;
//				pSlow = pSlow->next;
//			}
//			return cur;
//		}
//	}
//	return NULL;
//}


//Node* reverseList(Node* head) {
//	Node* pre = NULL;
//	Node* next = NULL;
//	while (head) {
//		next = head->next;
//		head->next = pre;
//		pre = head;
//		head = next;
//	}
//	return pre;
//}

//Node* removeElements(Node* head, int val) {
//	if (head == NULL) {
//		return NULL;
//	}
//	Node* rhead = NULL;
//	Node* cur = head;
//	while (cur) {
//		if (cur->val == val) {
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
//		rhead = cur;
//		cur = cur->next;
//	}
//	return head;
//}

//Node* reverseBetween(Node* head, int m, int n) {
//	if (head == NULL || m > n) {
//		return NULL;
//	}
//	Node* cur = head;
//	Node* start = cur;
//	Node* end = cur;
//	Node* pre = NULL;
//	Node* next = NULL;
//	for (int i = 1;i < m;i++) {
//		start = cur;
//		cur = cur->next;
//		end = cur;
//	}
//	for (int i = 0;i < n - m;i++) {
//		next = cur->next;
//		cur->next = pre;
//		pre = cur;
//		cur = next;
//	}
//	start->next = pre;
//	end->next = cur;
//	if (m == 1) {
//		return pre;
//	}
//	return head;
//}

//Node* MergeListNode(Node* l1, Node* l2) {
//	Node* head = (Node*)malloc(sizeof(Node));
//	Node* cur = head;
//	while (l1 != NULL && l2 != NULL) {
//		if (l1->val <= l2->val) {
//			cur->next = l1;
//			l1 = l1->next;
//		}
//		else {
//			cur->next = l2;
//			l2 = l2->next;
//		}
//		cur = cur->next;
//	}
//	if (l1 != NULL) {
//		cur->next = l1;
//	}
//	else {
//		cur->next = l2;
//	}
//	return head->next;
//}

//Node* middleNode(Node* head) {
//	Node* pFast = head;
//	Node* pSlow = head;
//	while (pFast && pFast->next) {
//		pFast = pFast->next->next;
//		pSlow = pSlow->next;
//	}
//	return pSlow;
//}

//Node* deleteDuplicates(Node* head) {
//	if (head == NULL) {
//		return NULL;
//	}
//	Node* cur = head;
//	while (cur->next) {
//		if (cur->val == cur->next->val) {
//			cur->next = cur->next->next;
//			continue;
//		}
//		else {
//			cur = cur->next;
//		}
//	}
//	return head;
//}

//Node* deleteDuplicates(Node* head) {
//	if (head == NULL) {
//		return NULL;
//	}
//	Node* pre = NULL;
//	Node* cur = head;
//	while (cur) {
//		if (cur->next!=NULL&&cur->val == cur->next->val) {
//			int value = cur->val;
//			while (cur->next != NULL && cur->next->val == value) {
//				cur = cur->next;
//			}
//			if (pre == NULL) {
//				head = cur->next;
//			}
//			else {
//				pre->next = cur->next;
//			}
//		}
//		else {
//			pre = cur;
//		}
//		cur = cur->next;
//	}
//	return head;
//}

//Node* removeNthFromEnd(Node* head, int n) {
//	if (head == NULL) {
//		return NULL;
//	}
//	Node* pFast = head;
//	Node* pSlow = head;
//	int i = 0;
//	while (pFast) {
//		pFast = pFast->next;
//		i++;
//	}
//	int j = i - n - 1;
//	if (j < 0) {
//		return head->next;
//	}
//	while (j--) {
//		pSlow->next= pSlow->next;
//	}
//	pSlow = pSlow->next->next;
//	return pSlow;
//}

Node* swapPairs(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* p1 = head;
	Node* p2 = head->next;
	Node* p3 = NULL;
	Node*pre=(Node*)malloc(sizeof(Node));
	Node* temp = head->next;
	pre->next = head;
	while (1) {
		p3 = p2->next;
		p2->next = p1;
		pre->next = p2;
		pre = p1;
		pre->next = p3;
		if (p3 && p3->next) {
			p1 = p3;
			p2 = p1->next;
		}
		else {
			break;
		}
	}
	return temp;
}