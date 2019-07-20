#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void Merge(int a[], int b[], int start, int mid, int end) {
//	int i = start;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid && j <= end) {
//		if (a[i] < a[j]) {
//			b[k] = a[i];
//			i++;
//			k++;
//		}
//		else {
//			b[k] = a[j];
//			j++;
//			k++;
//		}
//	}
//	while (i<=mid) {
//		b[k] = a[i];
//		k++;
//		i++;
//	}
//	while (j <= end) {
//		b[k] = a[j];
//		j++;
//		k++;
//	}
//	int m;
//	for (m = 0;m < k;m++) {
//		a[start + m] = b[m];
//	}
//}
//void Twocut(int a[], int b[], int start, int end) {
//	if (start < end) {
//		int mid = (start + end) / 2;
//		Twocut(a, b, start, mid);
//		Twocut(a, b, mid + 1, end);
//		Merge(a, b, start, mid, end);
//	}
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int size = sizeof(a) / sizeof(int);
//	int b[9] = { 0 };
//	Twocut(a, b, 0, size - 1);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//Ö±½Ó²åÈëÅÅÐò
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
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,5,6 };
//	int size = sizeof(a) / sizeof(int);
//	insertsort(a, size);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//Ï£¶ûÅÅÐò
//void insertsortwithgap(int a[], int size,int gap) {
//	for (int i = 0;i < size;i++) {
//		int k = a[i];
//		int j;
//		for (j = i - gap;j >= 0 && a[j] > k;j -= gap) {
//			a[j + gap] = a[j];
//		}
//		a[j + gap] = k;
//	}
//}
//void shellsort(int a[], int size) {
//	int gap = size;
//	while (1) {
//		gap = gap / 3 + 1;
//		insertsortwithgap(a, size,gap);
//		if (gap == 1) {
//			break;
//		}
//	}
//}
//int main() {
//	int a[] = { 1,2,4,5,7,3 };
//	int size = sizeof(a) / sizeof(int);
//	shellsort(a, size);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//¼òµ¥Ñ¡ÔñÅÅÐò
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void selectsort(int a[],int size) {
//	int left = 0;
//	int right = size - 1;
//	while (left < right) {
//		int min = left;
//		int max = left;
//		for (int i = left + 1;i <= right;i++) {
//			if (a[i] < a[min]) {
//				min = i;
//			}
//			if (a[max] < a[i]) {
//				max = i;
//			}
//		}
//		swap(a + left, a + min);
//		if (max == left) {
//			max = min;
//		}
//		swap(a + right, a + max);
//		left++;
//		right--;
//	}
//	}
//int main() {
//	int a[] = { 1,3,2,4,6,5,8,7 };
//	int size = sizeof(a) / sizeof(int);
//	selectsort(a, size);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//¶ÑÅÅÐò
//void heapify(int a[], int size,int index) {
//	int left = 2 * index + 1;
//	int right = 2 * index + 2;
//	if (left >= size) {
//		return;
//	}
//	int max = left;
//	if (right < size && a[right]> a[left]) {
//		max = right;
//	}
//	if (a[index] > a[max]) {
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
//		heapify(a, size,i);
//	}
//}
//void heapsort(int a[], int size) {
//	creatheap(a, size);
//	for (int i = 0;i < size;i++) {
//		int t = a[0];
//		a[0] = a[size - i - 1];
//		a[size - i - 1] = t;
//		heapify(a, size - 1 - i, 0);
//	}
//}
//int main() {
//	int a[] = { 1,4,3,2,6,5,8,7 };
//	int size = sizeof(a) / sizeof(int);
//	heapsort(a, size);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//Ã°ÅÝÅÅÐò
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void bubblesort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		for (int j = 0;j < size - 1 - i;j++) {
//			if (a[j] > a[j + 1]) {
//				swap(a + j, a + (j + 1));
//			}
//		}
//	}
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int size = sizeof(a) / sizeof(int);
//	bubblesort(a, size);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//¿ìËÙÅÅÐò1
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//int partition(int a[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int piovt = a[right];
//	while (begin < end) {
//		while (begin < end && a[begin] <= piovt) {
//			begin++;
//		}
//		while (begin<end && a[end]>=piovt) {
//			end--;
//		}
//		swap(a + begin, a + end);
//	}
//	swap(a + begin, a + right);
//	return begin;
//}
//void quicksortInternal(int a[], int left,int right) {
//	if (left >= right) {
//		return;
//	}
//	int piovtIndex=partition(a, left, right);
//	quicksortInternal(a, left, piovtIndex - 1);
//	quicksortInternal(a, piovtIndex, right);
//}
//int main() {
//	int a[] = { 1,9,2,7,6,4,5,3,8 };
//	int size = sizeof(a) / sizeof(int);
//	quicksortInternal(a, 0, size - 1);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//¿ìËÙÅÅÐò2
//int partition(int a[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int piovt = a[right];
//	while (begin < end) {
//		while (begin < end && a[begin] < piovt) {
//			begin++;
//		}
//		a[end] = a[begin];
//		while (begin<end && a[end]>piovt) {
//			end--;
//		}
//		a[begin] = a[end];
//	}
//	a[begin] = piovt;
//	return begin;
//}
//void quicksortInternal(int a[], int left, int right) {
//	if (left >= right) {
//		return;
//	}
//	int piovtIndex = partition(a, left, right);
//	quicksortInternal(a, left, piovtIndex - 1);
//	quicksortInternal(a, piovtIndex + 1, right);
//}
//int main() {
//	int a[] = { 1,9,3,8,2,7,4,6,5 };
//	int size = sizeof(a) / sizeof(int);
//	quicksortInternal(a, 0, size - 1);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}





