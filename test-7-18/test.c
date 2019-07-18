#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
////直接插入排序
//void insertsort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		int k = a[i];
//		int j;
//		for (j = i-1;j >= 0 && k < a[j];j--) {
//			a[j + 1] = a[j];
//		}
//		a[j + 1] = k;
//	}
//}
//int main() {
//	int a[] = { 8,4,5,3,2,6,7,9,1 };
//	int strlen = sizeof(a) / sizeof(int);
//	insertsort(a,strlen);
//	for (int i = 0;i < strlen;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
////希尔排序
//void insertsortwithGap(int a[], int size, int gap) {
//	for (int i = 0;i < size;i++) {
//		int k = a[i];
//		int j;
//		for (j = i - gap;j >= 0 && a[j] > k;j-=gap) {
//			a[j + gap] = a[j];
//		}
//		a[j + gap] = k;
//	}
//}
//void shellsort(int a[], int size) {
//	int gap = size;
//	while (1) {
//		gap = gap / 3 + 1;
//		insertsortwithGap(a, size, gap);
//		if (gap == 1) {
//			break;
//		}
//	}
//}
//int main() {
//	int a[] = { 9,1,8,2,7,3,6,4,5 };
//	int strlen = sizeof(a) / sizeof(int);
//	shellsort(a, strlen);
//	for (int i = 0;i < strlen;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
////堆排序
//void heapfy(int a[], int size, int index) {
//	int left = 2 * index + 1;
//	int right = 2 * index + 2;
//	if (left >=size) {
//		return;
//	}
//		int max = left;
//		if (right<size && a[left]<a[right]) {
//			max = right;
//		}
//		if (a[index] > a[max]) {
//			return;
//		}
//		else {
//			int t = a[max];
//			a[max] = a[index];
//			a[index] = t;
//		}
//	heapfy(a, size, max);
//}
//void creatheapfy(int a[], int size) {
//	for (int i =(size-2)/2;i >= 0;i--) {
//		heapfy(a, size, i);
//	}
//}
//void heapsort(int a[], int size) {
//	//建堆
//	creatheapfy(a, size);
//	for (int i = 0;i < size;i++) {
//		// 无序 [0, size  - i)
//		// 有序 [size - i, size)
//		int t = a[0];
//		a[0] = a[size-i-1];
//		a[size-i-1] = t;
//		// 无序 [0, size - i - 1)
//		//有序[size - i - 1, size)
//		//在无序区间中再进行向上调整
//		heapfy(a, size - i - 1, 0);
//	}
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int strlen = sizeof(a) / sizeof(int);
//	heapsort(a, strlen);
//	for (int i = 0;i < strlen;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
////选择排序1
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
//int main() {
//	int a[] = { 1,9,2,8,3,7,4,6,5 };
//	int strlen = sizeof(a) / sizeof(int);
//	selectsort(a, strlen);
//	for (int i = 0;i < strlen;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
////选择排序2
//void selectsort(int a[], int size) {
//	for (int i = 0;i < size;i++) {
//		int min = i;
//		for (int j = i+1;j < size;j++) {
//			if (a[j] < a[min]) {
//				min = j;
//			}
//		}
//		int t = a[min];
//		a[min] = a[i];
//		a[i] = t;
//	}
//}
//int main() {
//	int a[] = { 1,9,2,8,3,7,5,4,6 };
//	int strlen = sizeof(a) / sizeof(int);
//	selectsort(a, strlen);
//	for (int i = 0;i < strlen;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
//选择排序3
void swap(int *a, int *b) {
	int* t = a;
	a = b;
	b = t;
}
void selectsort(int a[], int size) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int min = left;
		int max = left;
		for (int i = left + 1;i < right;i++) {
			if (a[i] < a[min]) {
				min = i;
			}
			if (a[i] > a[max]) {
				max = i;
			}
			swap(a+min,a+left);
			if (a[max] == a[left]) {
				max = min;
			}
			swap(a+max,a+right);
			left++;
			right--;
		}
	}
}
int main() {
		int a[] = { 1,9,2,8,3,7,5,4,6 };
		int strlen = sizeof(a) / sizeof(int);
		selectsort(a, strlen);
		for (int i = 0;i < strlen;i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return 0;
	}

