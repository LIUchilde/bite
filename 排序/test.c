#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include"test.h"
void printfArray(int a[], int size) {
	for (int i = 0;i < size;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
//¼òµ¥²åÈëÅÅÐò
void insertsort(int a[], int size) {
	for (int i = 0;i < size;i++) {
		int k = a[i];
		int j;
		for (j = i - 1;j >= 0 && k < a[j];j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}
//Ï£¶ûÅÅÐò
void insertsortwithGap(int a[], int size, int gap) {
	for (int i = 0;i < size;i++) {
		int k = a[i];
		int j;
		for (j = i - gap;j >= 0 && k < a[j];j-=gap) {
			a[j + gap] = a[j];
		}
		a[j + gap] = k;
	}
}
void shellsort(int a[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		insertsortwithGap(a, size, gap);
		if (gap == 1) {
			break;
		}
	}
}
//Ñ¡ÔñÅÅÐò
void selectsort(int a[], int size) {
	for (int i = 0;i < size;i++) {
		int max = 0;
		for (int j = 1;j < size - i;j++) {
			if (a[j] > a[max]) {
				max = j;
			}
		}
		int t = a[max];
		a[max] = a[size - i - 1];
		a[size - i - 1] = t;
	}
}
//¶ÑÅÅÐò
void heapify(int a[], int size, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size) {
		return;
	}
	int max = left;
	if (right < size && a[right] > a[left]) {
		max = right;
	}
	if (a[index] > a[max]) {
		return;
	}
	int t = a[max];
	a[max] = a[index];
	a[index] = t;
	heapify(a, size, max);
}
void creatheap(int a[], int size) {
	for (int i = (size - 2) / 2;i >= 0;i--) {
		heapify(a, size, i);
	}
}
void heapsort(int a[], int size) {
	creatheap(a, size);
	for (int i = 0;i < size;i++) {
		int t = a[0];
		a[0] = a[size - i - 1];
		a[size - i - 1] = t;
		heapify(a, size - 1 - i, 0);
	}
}
void bubblesort(int a[], int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size-i-1;j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}
void dealMerge(int a[], int temp[], int start, int end) {
	if (start > end) {
		return;
	}
	int mid = (start + end) / 2;
	dealMerge(a, temp, start, mid);
	dealMerge(a, temp, mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i<=mid&&j<=end) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	for (;i <= mid;i++, k++) {
		temp[k] = a[i];
	}
	for (;j <= end;j++, k++) {
		temp[k] = a[j];
	}
	for (int m = 0;m <=end;m++) {
		a[m] = temp[m];
	}
}
void Mergesort(int a[], int size) {
	int* temp = (int*)malloc(size * (sizeof(int)));
	dealMerge(a, temp, 0, size - 1);
	free(temp);
}