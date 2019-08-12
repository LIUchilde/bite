#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
	int val;
	struct Node* next;
}Node;
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
//	}
//	Node* curA = headA;
//	Node* curB = headB;
//	int gap = sizeA - sizeB;
//	if (gap > 0) {
//		while (gap--) {
//			curA = curA->next;
//		}
//	}
//	if (gap < 0) {
//		while (gap++) {
//			curB = curB->next;
//		}
//	}
//	while (curA != curB) {
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return curA;
//}
//int main() {
//	Node* getIntersectionNode(Node * heada, Node * headb);
//	system("pause");
//	return 0;
//}
//bool hasCycle(Node*head){
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
//int main() {
//	bool hasCycle(Node * head);
//	system("pause");
//	return 0;
//}
//Node* detectCycle(Node* head) {
//	Node* pFast = head;
//	Node* pSlow = head;
//	Node* pInput = head;
//	if (head == NULL) {
//		return NULL;
//	}
//		while (pFast && pFast->next) {
//			pFast = pFast->next->next;
//			pSlow = pSlow->next;
//			if (pFast == pSlow) {
//				while (pSlow != pInput) {
//					pSlow = pSlow->next;
//					pInput = pInput->next;
//				}
//				return pInput;
//			}
//		}
//		return NULL;
//	}
//int main() {
//	Node* detectCycle(Node * head);
//	system("pause");
//	return 0;
//}
//Node* reserveList(Node* head) {
//	Node* newListhead = NULL;
//	Node* cur = head;
//	while (cur != NULL) {
//		Node* next = cur->next;
//		cur->next = newListhead;
//		newListhead = cur;
//		cur = next;
//	}
//	return newListhead;
//}
//int main() {
//	Node* resreveList(Node * head);
//	system("pause");
//	return 0;
//}
//void deleteNode(Node* node) {//删除链表中的结点
//	node->val = node->next->val;
//	node->next = node->next->next;
//}
//int main() {
//	void deleteNode(Node * node);
//	system("pause");
//	return 0;
//}


