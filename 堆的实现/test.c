#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"test.h"
void HeapInit(Heap* hp, HPDataType n) {
    Heap*arr = (Heap*)malloc(sizeof(Heap) * n);
	hp->capacity = n;
	hp->size = 0;
}
void HeapDestory(Heap* hp) {
	if (hp->arr) {
		free(hp->arr);
	}
	hp->arr = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
void HeapPush(Heap* hp, HPDataType x) {
	if (hp->size = hp->capacity) {//堆满
		HPDataType* arr = (HPDataType*)malloc(hp->capacity * 2);
		hp->capacity = 2 * hp->capacity;
	}
	//建小堆向上调整算法
	hp->arr[hp->size] = x;
	hp->size++;
	int i = hp->size - 1;
	while (i) {
		int j = (i - 1) / 2;
		if (x > hp->arr[j]) {
			break;
		}
		hp->arr[i] = hp->arr[j];
		i = j;
	}
	hp->arr[i] = x;
}
void HeapadjustDown(Heap* hp, HPDataType index) {
	while (1) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left > hp->size) {
			return;
		}
		int min = left;
		if (right<hp->size && hp->arr[left]>hp->arr[right]) {
			min = right;
		}
		if (hp->arr[index] < hp->arr[min]) {
			return;
		}
		else {
			int t = hp->arr[index];
			hp->arr[index] = hp->arr[min];
			hp->arr[min] = t;
		}
		index = min;
	}
}
void HeapPop(Heap* hp) {
	if (hp->size == 0) {
		printf("堆空");
		exit(0);
	}
	HPDataType temp = hp->arr[0];
	hp->size--;
	if (hp->size == 0) {
		exit(1);
	}
	HPDataType lastData = hp->arr[hp->size - 1];
	//最小堆的向下调整算法
	HeapadjustDown(hp,0);
	hp->arr[0] = lastData;
}HPDataType HeapEmpty(Heap* hp) {
	assert(hp->arr);
	return hp->size == 0;
}
HPDataType Heapsize(Heap* hp) {
	return hp->size;
}
HPDataType HeapTop(Heap* hp) {
	assert(hp->arr);
		if (!HeapEmpty(hp)) {
			return hp->arr[0];
	}
		else {
			return - 1;
		}
}

