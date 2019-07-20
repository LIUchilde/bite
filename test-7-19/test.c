#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//void selectsort(int a[], int size) {
//	int left = 0;
//	int right = size - 1;
//	while (left < right) {
//		int min = left;
//		int max = left;
//		for (int i = left + 1; i <=right; i++) {
//			if (a[i] < a[min]) {
//				min = i;
//			}
//			if (a[i] > a[max]) {
//				max = i;
//			}
//		}
//		swap(a+min,a+left);
//		if (max == left) {
//			max = min;
//		}
//		swap(a + max, a + right);
//		left++;
//		right--;
//	}
//	}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int strlen = sizeof(a) / sizeof(int);
//	selectsort(a, strlen);
//	for (int i = 0; i < strlen; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//Ã°ÅÝÅÅÐò
//void bubblesort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		for (int j = 0;j < size - 1 - i;j++) {
//			if (a[j] > a[j + 1]) {
//				int t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//		}
//	}
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int strlen = sizeof(a) / sizeof(int);
//	bubblesort(a, strlen);
//	for (int i = 0; i < strlen; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//¿ìËÙÅÅÐò
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition1(int a[], int left, int right) {
	int begin = left;
	int end = right;
	int piovt = a[right];
	while (begin < end) {
		while (begin < end && a[begin] <= piovt) {
			begin++;
		}
		while (begin<end && a[end]>=piovt) {
			end--;
		}
		swap(a + begin, a + end);
	}
	swap(a + begin, a + right);
	return begin;
}
void quicksortInternal(int a[], int left,int right) {
	if (left >=right) {
		return;
	}
	int piovtIndex = partition1(a, left, right);
	quicksortInternal(a,left, piovtIndex - 1);
	quicksortInternal(a, piovtIndex + 1, right);
}
int main() {
	int a[] = { 1,9,2,8,3,7,4,6,5 };
	int strlen = sizeof(a) / sizeof(int);
	quicksortInternal(a, 0, strlen - 1);
	for (int i = 0; i < strlen; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//int partition2(int a[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int piovt = a[right];
//	while (begin<end) {
//		while (begin < end && a[begin] <= piovt) {
//			begin++;
//		}
//		a[end] = a[begin];
//		while (begin < end && a[end] >= piovt) {
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
//	int piovtIndex = partition2(a, left, right);
//	quicksortInternal(a, left, piovtIndex - 1);
//	quicksortInternal(a, piovtIndex + 1, right);
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int size = sizeof(a) / sizeof(int);
//	quicksortInternal(a, 0, size - 1);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//  system("pause");
//	return 0;
//}
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//int partition(int a[], int left, int right) {
//	int div = left;
//	int i = left;
//	for (;i < right;i++) {
//		if (a[i] < a[right]) {
//			swap(a + i, a + div);
//			div++;
//		}
//	}
//		swap(a + div, a + right);
//		return div;
//	}
//void quicksortInternal(int a[],int left,int right){
//	if (left >= right) {
//		return;
//	}
//	int piovtIndex = partition(a, left, right);
//	quicksortInternal(a, left, piovtIndex - 1);
//	quicksortInternal(a, piovtIndex + 1, right);
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int size = sizeof(a) / sizeof(int);
//	quicksortInternal(a, 0, size - 1);
//	for (int i = 0;i < size;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}




