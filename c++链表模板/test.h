#pragma once
#include<iostream>
using namespace std;
template<class type>

class ListNode {
private:
	ListNode<type>* next;
	type Data;
public:
	 ListNode();
	 ~ListNode();
	void  ListNodePushFront(ListNode<type>*head,type val);
	void  ListNodePushBack(ListNode*head,type val);
	void  ListNodePopFront(ListNode* head);
	void  ListNodePopBack(ListNode* head);
	void  ListNodeinsert(ListNode* head,int pos, type val);
	void  ListNodeErase(ListNode* head,int pos);
	void ListNodeprint(ListNode* head);
};
template<class type>
ListNode<type>::ListNode(){
	ListNode*head =new ListNode<type>;
}
template<class type>
ListNode<type>::~ListNode() {
	ListNode* head;
	ListNode<type>* cur = head;
	while (cur) {
		delete cur;
		cur = cur->next;
	}
}
template<class type>
void ListNode<type>::ListNodePushFront(ListNode<type>*head,type val) {
	ListNode<type>*node = new ListNode<type>(Data);
	node->Data = Data;
	node->next = head;
	head = node;
}
template<class type>
void ListNode<type>::ListNodeprint(ListNode* head) {
	ListNode* cur = head;
	while (cur) {
		printf("%d-->", cur->Data);
		cur = cur->next;
	}
}





