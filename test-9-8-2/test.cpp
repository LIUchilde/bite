#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int main() {
	ListNode<int>* head=nullptr;
	ListNode<int>L;
	L.pushFront(head, 1);
	L.pushFront(head, 2);
	L.pushFront(head, 3);
	L.pushFront(head, 4);
	L.Print(head);
	return 0;
}