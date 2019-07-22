#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//int partition(int a[], int left,  int right) {
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
//void quicksortInternal(int a[], int left, int right) {
//	if (left >= right) {
//		return;
//	}
//	int piovtIndex=partition(a, left, right);
//	quicksortInternal(a, left,piovtIndex-1);
//	quicksortInternal(a,piovtIndex, right);
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
//		a[begin] = piovt;
//		return begin;
//	}
//void quicksortInternal(int a[], int left, int right) {
//	if (left >= right) {
//		return;
//	}
//	int piovtIndex = partition(a, left, right);
//	quicksortInternal(a, left, piovtIndex-1);
//	quicksortInternal(a, piovtIndex, right);
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
//	swap(a + div, a + right);
//	return div;
//}
//void quicksortInternal(int a[], int left, int right) {
//	if (left >= right)
//	{
//		return;
//	}
//	int piovtIndex = partition(a, left, right);
//	quicksortInternal(a, left, piovtIndex - 1);
//	quicksortInternal(a, piovtIndex, right);
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
void Merge(int a[], int b[], int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
			k++;
		}
		else {
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while ( i<=mid) {
		b[k] = a[i];
		i++;
		k++;
	}
	while (j <= end) {
		b[k] = a[j];
		j++;
		k++;
	}
	int m;
	for (m = 0;m < k;m++) {
		a[start + m] = b[m];
	}
}
void Twocut(int a[], int b[], int start, int end) {
	if (start < end) {
		int mid = (start +end) / 2;
		Twocut(a, b, start, mid);
		Twocut(a, b, mid+1, end);
		Merge(a, b, start, mid,end);
	}
}
int main() {
	int a[] = { 1,9,2,8,3,7,4,6,5 };
	int b[9] = { 0 };
	int size = sizeof(a) / sizeof(int);
	Twocut(a, b, 0, size - 1);
	for (int i = 0;i < size;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
