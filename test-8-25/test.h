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
//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//Node* getIntersectionNode(Node* headA, Node* headB);
//����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
//struct ListNode* partition(struct ListNode* head, int x);
//����һ�������ж��������Ƿ��л���
//bool hasCycle(struct ListNode* head);
//��һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//Node* detectCycle(Node* head);
//��ת����
//Node* reverseList(Node* head);
//�Ƴ�����Ԫ�ء�
//Node* removeElements(Node* head, int val);
//Node* reverseBetween(Node* head, int m, int n);
//�ϲ�������������
//Node* MergeListNode(Node* l1, Node* l2);
//�����м���
//Node* middleNode(Node* head);
//ɾ�������е��ظ�Ԫ��
//Node* deleteDuplicates(Node* head);
//ɾ�������е��ظ����II
//Node* deleteDuplicates(Node* head);
//ɾ����������n�����
//Node* removeNthFromEnd(Node* head, int n);
//�������������еĽ��
Node* swapPairs(Node* head);