#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define INIT_CAPAICTY 100
#include"test.h"
SeqList::SeqList() {
	array = new int[INIT_CAPAICTY];
	capacity = INIT_CAPAICTY;
	size = 0;
}
SeqList::~SeqList() {
	delete[]array;
	capacity = 0;
	size = 0;
}
void SeqList::ensurecapacity() {
	if (size < capacity) {
		return;
	}
	else {
		int newcapacity = 2 * capacity;
		int* newarray = new int[newcapacity];
		for (int i = 0;i < size;i++) {
			newarray[i] = array[i];
		}
		delete[]array;
		array = newarray;
	}
}
void SeqList::SeqListPushFront(int val) {
	for (int i = size-1;i >=0;i--) {
		array[i+1] = array[i];
	}
	array[0] = val;
	size++;
}
void SeqList::SeqListPushBack(int val) {
	array[size] = val;
	size++;
}
void SeqList::SeqListPopFront() {
	for (int i = 0;i<size;i++) {
		array[i] = array[i+1];
	}
	size--;
}
void SeqList::SeqListPopBack() {
	size--;
}
void SeqList::SeqlistInsert(int index, int val) {
	if (index<0 || index>size) {
		cout << "下标不合法" << endl;
	}
	ensurecapacity();
	for (int i = size;i > index;i--) {
		array[i] = array[i-1];
	}
	array[index] = val;
	size++;
}
void SeqList::SeqListErase(int index) {
	for (int i = index;i < size;i++) {
		array[i] = array[i + 1];
	}
	size--;
}
void SeqList::SeqListprint() {
	for (int i = 0;i < size;i++) {
		cout << array[i]<<" ";
	}
	cout << endl;
}