//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#define MAX_SIZE 10
//#include<assert.h>
//#include"test.h"
//
//template<class Type>
//SeqList<Type>::SeqList() {
//	array = new Type[MAX_SIZE];
//	capacity = 0;
//	size = 0;
//}
//template<class Type>
//SeqList<Type>::SeqList(size_t sz) {//����ռ�
//	capacity = sz > MAX_SIZE? sz : MAX_SIZE;
//	array = new int[capacity];
//	size = 0;
//}
//template<class Type>
//bool SeqList<Type>::isfull() {
//	return size >= capacity;
//}
//template<class Type>
//bool SeqList<Type>::isempty() {
//	return size == 0;
//}
//template<class Type>
//void SeqList<Type>::SeqListPushFront(const Type& val) {
//	if (isfull) {
//		cout << "˳������������ɲ���" << endl;
//	}
//	else {
//		for (int i = size - 1;i >= 0;i--) {
//			array[i + 1] = array[i];
//		}
//	}
//}
//template<class Type>
//void SeqList<Type>::SeqListPushBack(const Type& val) {
//	if (isfull) {
//		cout << "˳������������ɲ���" << endl;
//	}
//	array[size++] = val;
//}
//template<class Type>
//void SeqList<Type>::SeqListPopFront() {
//	if (isempty) {
//		cout << "˳���Ϊ�գ�����ɾ��" << endl;
//	}
//	for (int i = 0;i < size;i++) {
//		array[i] = array[i + 1];
//		size--;
//	}
//}
//template<class Type>
//void SeqList<Type>::SeqListPopBack() {
//	if (isempty) {
//		cout << "˳���Ϊ�գ�����ɾ��" << endl;
//	}
//	size--;
//}
//template<class Type>
//void SeqList<Type>::SeqListprint() {
//	for (int i = 0;i < size;i++) {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//	
//}

