#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<stdlib.h>
template<class type>
int main() {
	ListNode<int>* head = nullptr;
	ListNode<int> Node;
	Node.ListNodePushFront(head,1);
	Node.ListNodePushFront(head,2);
	Node.ListNodePushFront(head,3);
	Node.ListNodePushFront(head,4);
	Node.ListNodeprint(head);
	system("pause");
	return 0;
}