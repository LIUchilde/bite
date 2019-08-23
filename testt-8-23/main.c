#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdlib.h>
//#include"test.h"
//int main() {
//	int a[10] = { 1,9,0,2,4,3,8,6,7,5 };
//	insertsort(a, 10);//时间复杂度 O(n2)  稳定
//	printArray(a, 10);
//	shellsort(a, 10);//时间复杂度O(nlogn)  不稳定
//	printArray(a, 10);
//	selectsort(a, 10);//时间复杂度O(n2)   不稳定
//	printArray(a, 10);
//	heapsort(a, 10);//时间复杂度O(nlogn)    不稳定
//	printArray(a, 10);
//	bubblesort(a, 10);//时间复杂度O(n2)    稳定
//	printArray(a, 10);
//	quicksort1(a, 10);//时间复杂度O(nlogn)  不稳定
//	printArray(a, 10);
//	quicksort2(a, 10);
//	printArray(a, 10);
//	quicksort3(a, 10);
//	printArray(a, 10);
//	Mergesort(a, 10);//时间复杂度O(nlogn)  稳定
//	printArray(a, 10);
//	system("pause");
//	return 0;
//}

#include"test.h"
#include<stdio.h>
#include<stdlib.h>
//int main() {
//	stack s;
//	stackInit(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d ", s.top);
//	printf("\n");
//	printf("%d ", Top(&s));
//	printf("\n");
//	while (!IsEmpty(&s)) {
//		printf("%d ", pop(&s));
//	}
//	printf("\n");
//	printf("%d ", Top(&s));
//	system("pause");
//	return 0;
//}

//int main() {
//	Queue q;
//	QueueInit(&q);
//	Queuepush(&q, 1);
//	Queuepush(&q, 2);
//	Queuepush(&q, 3);
//	Queueprint(&q);
//	printf("\n");
//	Queuepop(&q);
//	printf("\n");
//	QueueIsEmpty(&q);
//	printf("\n");
//	Queuepop(&q);
//	Queuepop(&q);
//	QueueIsEmpty(&q);
//	system("pause");
//	return 0;
//}

int main() {
	Node* root;
	char a[] = "ABD#GI##J###CE#HK###F##";
	root = creatBinaryTree(a);
	preOrder(root);
	printf("\n");
	preOrderNor(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	inOrderNor(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	printf("%d ",getNodecount(root));
	printf("\n");
	printf("%d ", getHeight(root));
	printf("\n");
	printf("%d ", getleafcount(root));
	printf("\n");
	printf("%d ", getkleafcount(root, 2));
	printf("\n");
	system("pause");
	printf("\n");
	return 0;
}