#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include"test.h"
//void printArray(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void insertsort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		int k = a[i];
//		int j;
//		for (j = i - 1;j >= 0 && a[j] > k;j--) {
//			a[j + 1] = a[j];
//		}
//		a[j + 1] = k;
//	}
//}
//void insertsortwithgap(int a[], int size,int gap) {
//	for (int i = 0;i < size;i++) {
//		int k = a[i];
//		int j;
//		for ( j = i - gap;j >= 0 && a[j] > k;j-=gap) {
//			a[j + gap] = a[j];
//		}
//		a[j + gap] = k;
//	}
//}
//void shellsort(int a[], int size) {
//	int gap = size;
//	while (1) {
//		gap = gap / 3 + 1;
//		insertsortwithgap(a, 10, gap);
//		if (gap == 1) {
//			break;
//		}
//	}
//}
//void selectsort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		int max = 0;
//		for (int j = 1;j < size - i;j++) {
//			if (a[j] > a[max]) {
//				max = j;
//			}
//		}
//		int t = a[max];
//		a[max] = a[size - i - 1];
//		a[size - i - 1] = t;
//	}
//}
//void heapify(int a[], int size, int index) {
//	int left = 2 * index + 1;
//	int right = 2 * index + 2;
//	if (left >= size) {
//		return;
//	}
//	int max =left;
//	if (right<size && a[right]>a[left]) {
//		max = right;
//	}
//	if (a[index] >= a[max]) {
//		return;
//	}
//	else {
//		int t = a[max];
//		a[max] = a[index];
//		a[index] = t;
//	}
//	heapify(a, size, max);
//}
//void creatheap(int a[], int size) {
//	for (int i = (size - 2) / 2;i >= 0;i--) {
//		heapify(a, size, i);
//	}
//}
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void heapsort(int a[], int size) {
//	creatheap(a, size);
//	for (int i = 0;i < size;i++) {
//		int t = a[0];
//		a[0] = a[size - i - 1];
//		a[size - i - 1] = t;
//		heapify(a, size - i - 1, 0);
//	}
//}
//void bubblesort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		for (int j = 0;j < size - i - 1;j++) {
//			if (a[j] > a[j + 1]) {
//				int t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//		}
//	}
//}
//int partition1(int a[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int pivot = a[right];
//	while (begin<end) {
//		while (begin < end && a[begin] < pivot) {
//			begin++;
//		}
//		while (begin<end && a[end]>pivot) {
//			end--;
//		}
//		swap(a + begin, a + end);
//	}
//	swap(a + begin, a + right);
//	return begin;
//}
//void dealquicksort1(int a[], int left, int right) {
//	if (left > right) {
//		return;
//	}
//	int pivotIndex = partition1(a, left, right);
//	dealquicksort1(a, left, pivotIndex - 1);
//	dealquicksort1(a, pivotIndex + 1, right);
//}
//void quicksort1(int a[], int size) {
//	dealquicksort1(a, 0, size - 1);
//}
//int partition2(int a[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int pivot = a[right];
//	while (begin < end) {
//		while (begin < end && a[begin] < pivot) {
//			begin++;
//		}
//		a[right] = a[begin];
//		while (begin<end && a[end]>pivot) {
//			end--;
//		}
//		a[begin] = a[end];
//	}
//	a[begin] = pivot;
//	return begin;
//}
//void dealquicksort2(int a[], int left, int right) {
//	if (left > right) {
//		return;
//	}
//	int pivotIndex = partition2(a, left, right);
//	dealquicksort2(a, left, pivotIndex - 1);
//	dealquicksort2(a, pivotIndex + 1, right);
//}
//void quicksort2(int a[], int size) {
//	dealquicksort2(a, 0, size - 1);
//}
//int partition3(int a[], int left, int right) {
//	int i = left;
//	int div = left;
//	for (;i < right;i++) {
//		if (a[i] < a[right]) {
//			swap(a + i, a + div);
//			div++;
//		}
//	}
//	swap(a + div, a + right);
//	return div;
//}
//void dealquicksort3(int a[], int left, int right) {
//	if (left > right) {
//		return;
//	}
//	int pivotIndex = partition3(a, left, right);
//	partition3(a, left, pivotIndex - 1);
//	partition3(a, pivotIndex - 1, right);
//}
//void quicksort3(int a[], int size) {
//	dealquicksort3(a, 0, size - 1);
//}
//void dealmergesort(int a[], int temp[], int start, int end) {
//	if (start > end) {
//		return;
//	}
//	int mid = (start + end) / 2;
//	dealmergesort(a, temp, start, mid);
//	dealmergesort(a, temp, mid + 1, end);
//	int m = start;
//	int n = mid + 1;
//	int p = start;
//	while (m <= mid && n <= end) {
//		if (a[m] < a[n]) {
//			temp[p] = a[m];
//			m++;
//		}
//		if (a[m] > a[n]) {
//			temp[p] = a[n];
//			n++;
//		}
//		p++;
//	}
//	for (;m <= mid;m++,p++) {
//		temp[p] = a[m];
//	}
//	for (;n <= end;n++, p++) {
//		temp[p] = a[n];
//	}
//	for (int i = 0;i <p;i++) {
//		a[i] = temp[i];
//	}
//}
//void Mergesort(int a[], int size) {
//	int* temp = (int*)malloc(size * (sizeof(int)));
//	dealmergesort(a, temp, 0, size - 1);
//	free(temp);
//}
#include"test.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void stackInit(stack* s) {
	s->top = 0;
}
int IsEmpty(stack* s) {
	return s->top == 0;
}
void push(stack* s,DataType val) {
	s->arr[s->top] = val;
	s->top++;
}
int pop(stack* s) {
	return s->arr[--s->top];
}
int Top(stack* s) {
	if (s->top == 0) {
		printf("栈空");
		return 0;
	}
	return s->arr[s->top - 1];
}
void destroy(stack* s) {
	if (s->arr) {
		free(s->arr);
	}
	s->top = 0;
}
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
}
void Queuedestroy(Queue* q) {
	while (q->front) {
		pNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
void Queuepush(Queue* q, int val) {
	pNode* node = (pNode*)malloc(sizeof(pNode));
	node->val = val;
	node->next = NULL;
	if (q->front == NULL) {
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
}
int Queuepop(Queue* q) {
	assert(q->front != NULL);
	pNode* second = q->front->next;
	int val = q->front->val;
	free(q->front);
	q->front = second;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	return val;
}
void QueueIsEmpty(Queue* q) {
	if (q->front == NULL) {
		printf("队空");
	}
	else {
		printf("队不为空");
	}
}
void Queueprint(Queue* q) {
	pNode* cur = q->front;
	while (cur) {
		printf("%d ", cur->val);
		cur = cur->next;
	}
}
Node* creatBinaryTree(TypeData* a) {
	static int n = 0;
	if (a[n] == '#') {
		n++;
		return NULL;
	}
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->val = a[n];
	n++;
	cur->left = creatBinaryTree(a);
	cur->right = creatBinaryTree(a);
	return cur;
}
void preOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	printf("%c ", root->val);
	inOrder(root->right);
}
void postOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->val);
}
void preOrderNor(Node* root) {
	stack s;
	stackInit(&s);
	Node* cur = root;
	while (cur != NULL || !IsEmpty(&s)) {
		while (cur != NULL) {
			printf("%c ", cur->val);
			push(&s, cur);
			cur = cur->left;
		}
		Node* top = Top(&s);
		pop(&s);
		cur = top->right;
	}
}
void inOrderNor(Node* root) {
	stack s;
	stackInit(&s);
	Node* cur = root;
	while (cur != NULL || !IsEmpty(&s)) {
		while (cur != NULL) {
			push(&s, cur);
			cur = cur->left;
		}
		Node* top = Top(&s);
		printf("%c ", top->val);
		pop(&s);
		cur = top->right;
	}
}
int getNodecount(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = getNodecount(root->left);
	int right = getNodecount(root->right);
	return left + 1 + right;
}
int myMax(int a, int b) {
	return a > b ? a : b;
}
int getHeight(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return myMax(left, right) + 1;
}
int getleafcount(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return getleafcount(root->left) + getleafcount(root->right);
}
int getkleafcount(Node* root, int k) {
	assert(k >= 1);

	if (root == NULL) {
		return 0;
	}
	else if (k == 1) {
		return 1;
	}
	else {
		return getkleafcount(root->left, k - 1) + getkleafcount(root->right, k - 1);
	}
}
Node* find(Node* root, char v) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == v) {
		return root;
	}
	Node* left = find(root->left, v);
	if (left!=NULL) {
		return left;
	}
	Node* right = find(root->right, v);
	if (right!=NULL) {
		return right;
	}
	else {
		return NULL;
	}
}