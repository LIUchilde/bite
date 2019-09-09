#pragma once
#include<iostream>
using namespace std;
template<class T>
class ListNode {
public:
	ListNode();
	//ListNode(const ListNode& L);
	//ListNode& operator=(const ListNode& L);
	//~ListNode();
	void pushFront(ListNode* head,T val);
	//ListNode* pushBack(ListNode* head,T val);
	//ListNode* PopFront(ListNode* head);
	//ListNode* PopBack(ListNode* head);
	//ListNode* Clear(ListNode* head);
	//bool isEmpty(ListNode* head);
	ListNode* Print(ListNode* head);
private:
	ListNode* next;
	T Data;
};
template<class T>
ListNode<T>::ListNode() {
	ListNode<T>* head =nullptr ;
}
//template<class T>
//ListNode<T>::ListNode(const ListNode<T>& L) {
//
//}
//template<class T>
//ListNode<T>&ListNode<T>::operator=(const ListNode& L) {
//	
//}
//template<class T>
//ListNode<T>::~ListNode() {
//	ListNode* head=NULL;
//	if (head) {
//		return;
//	}
//	while (head) {
//		ListNode* next = head->next;
//		delete head;
//		head = next;
//	}
//}
template<class T>
void ListNode<T>::pushFront(ListNode<T>* head,T val) {
	ListNode<T>*node = new ListNode<T>(Data);
	node->Data = val;
	node->next = head;
	head = node;
}
template<class T>
ListNode<T>* ListNode<T>::Print(ListNode* head) {
	for (ListNode* cur = head;cur != NULL;cur = cur->next) {
		cout << cur->Data << "-->";
	}
	cout << endl;
	return head;
}
