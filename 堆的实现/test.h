#pragma once

typedef int HPDataType;
typedef struct Heap {
	HPDataType* arr;
	int capacity;
	int size;
}Heap;
void HeapInit(Heap* hp, HPDataType n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapadjustDown(Heap* hp, HPDataType index);
HPDataType HeapTop(Heap* hp);
HPDataType Heapsize(Heap* hp);
HPDataType HeapEmpty(Heap* hp);


