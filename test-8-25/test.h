#pragma once
#include<stdbool.h>
//typedef int DataType;
//typedef struct DListNode {
//	DataType data;
//	struct DListNode* next;
//	struct DListNode* pre;
//}pNode;
//void DListNodeInit(pNode** head);
//void Clear(pNode* head);
//void Destroy(pNode* head);
//void IsEmpty(pNode* head);
//void PushFront(pNode* head, DataType val);
//void PushBack(pNode* head, DataType val);
//void insert(pNode* head,int pos, DataType val);
//void PopFront(pNode* head);
//void PopBack(pNode* head);
//void Delete(pNode* head,int pos);
//void print(pNode* head);


typedef int DataType;
typedef struct ListNode {
	DataType val;
	struct ListNode* next;
}Node;
//编写一个程序，找到两个单链表相交的起始节点。
//Node* getIntersectionNode(Node* headA, Node* headB);
//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//struct ListNode* partition(struct ListNode* head, int x);
//给定一个链表，判断链表中是否有环。
//bool hasCycle(struct ListNode* head);
//给一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//Node* detectCycle(Node* head);
//翻转链表
//Node* reverseList(Node* head);
//移除链表元素、
//Node* removeElements(Node* head, int val);
//Node* reverseBetween(Node* head, int m, int n);
//合并两个有序链表
//Node* MergeListNode(Node* l1, Node* l2);
//返回中间结点
//Node* middleNode(Node* head);
//删除链表中的重复元素
//Node* deleteDuplicates(Node* head);
//删除链表中的重复结点II
//Node* deleteDuplicates(Node* head);
//删除链表倒数第n个结点
//Node* removeNthFromEnd(Node* head, int n);
//两两交换链表中的结点
Node* swapPairs(Node* head);