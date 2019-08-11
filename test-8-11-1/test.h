#pragma once
#include<iostream>
using namespace std;
#define MAX_SIZE 10
template<class Type>
class SeqList {
private:
	Type* array;
	size_t capacity;
	size_t size;
public:
	~SeqList();
	SeqList(size_t sz=MAX_SIZE);
	bool isfull()const;
	bool isempty()const;
	void SeqListPushFront(const Type& val);//头插
	void SeqListPushBack(const Type &val);//尾插
	void SeqListPopFront();//头删
	void SeqListPopBack();//尾删
	void SeqListprint();//打印
	void SeqListInsert(int index, const Type& val);//按位置插入
	void SeqListerase(int index);//按位置删除
	int Find(const Type& val);//按值查找
	void delete_val(const Type& val);//按值删除
	int length();//求长度
	void reserve();//反转
	void sort();//排序
	void clear();
};
	template<class Type>
SeqList<Type>::~SeqList() {
	delete[]array;
	capacity = 0;
	size = 0;
}
template<class Type>
SeqList<Type>::SeqList(size_t sz) {//分配空间
	capacity = sz > MAX_SIZE? sz : MAX_SIZE;
	array = new int[capacity];
	size = 0;
}
template<class Type>
bool SeqList<Type>::isfull()const {
	return size >= capacity;
}
template<class Type>
bool SeqList<Type>::isempty()const {
	return size==0;
}
template<class Type>
void SeqList<Type>::SeqListPushFront(const Type& val) {
	if (isfull()) {
		cout << "顺序表已满，不可插入" << endl;
	}
	else {
		for (int i = size;i >0;i--) {
			array[i] = array[i-1];
		}
		array[0] = val;
		size++;
	}
}
template<class Type>
void SeqList<Type>::SeqListPushBack(const Type& val) {
	if (isfull()) {
		cout << "顺序表已满，不可插入" << endl;
	}
	array[size++] = val;
}
template<class Type>
void SeqList<Type>::SeqListPopFront() {
	if (isempty()) {
		cout << "顺序表为空，不可删除" << endl;
	}
	for (int i = 0;i < size ;i++) {
		array[i] = array[i + 1];
	}
	size--;
}
template<class Type>
void SeqList<Type>::SeqListPopBack() {
	if (isempty()) {
		cout << "顺序表为空，不可删除" << endl;
	}
	size--;
}
template<class Type>
void SeqList<Type>::SeqListprint() {
	for (int i = 0;i < size;i++) {
		cout << array[i] << " ";
	}
	cout << endl;	
}
template<class Type>
void SeqList<Type>::SeqListInsert(int index, const Type& val) {
	if (index<0 || index>size) {
		cout << " 插入位置非法" << endl;
	}
	if (isfull()) {
		cout << "顺序表已满，不可插入" << endl;
	}
	for (int i = size;i > index;i--) {
		array[i] = array[i - 1];
	}
	array[index] = val;
	size++;
}
template<class Type>
void SeqList<Type>::SeqListerase(int index) {
	if (isempty()) {
		cout << " 顺序表为空，不可删除" << endl;
	}
	for (int i = index;i < size;i++) {
		array[i] = array[i + 1];
	}
	size--;
}
template<class Type>
int SeqList<Type>::Find(const Type& val) {
	for (int i = 0;i < size;i++) {
		if (array[i] == val)
		{
			cout << i << endl;
			return i;
		}
	}
	cout << "顺序表中没有该数" << endl;
	return -1;
}
template<class Type>
void SeqList<Type>::delete_val(const Type& val) {
	for (int i = 0;i < size;i++) {
		if (array[i] == val) {
			return SeqListerase(i);
		}
	}
	return;
}
template<class Type>
int SeqList<Type>::length() {
	 cout << size << endl;
	 return size;
}
template<class Type>
void SeqList<Type>::reserve() {
	int m = size - 1;
	for (int i = 0;i <=((size-1)/ 2);i++) {
		int temp = array[i];
		array[i] = array[m];
		array[m] = temp;
		m--;
	}	
}
template<class Type>
void SeqList<Type>::sort() {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size - i - 1;j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
template<class Type>
void SeqList<Type>::clear() {
	while (size) {
		array[size--] =NULL;
	}
}

