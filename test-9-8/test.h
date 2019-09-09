#pragma once
#include<iostream>
using namespace std;
template<class T>
class seqList {
public:
	seqList();
	seqList(const seqList& s);
	seqList& operator=(const seqList& s);
	~seqList();
	bool isImpty(seqList& s);
	bool isfull(seqList& s);
	void seqListpushFront(seqList&s,T val);
	void seqListpushBack(seqList&s,T val);
	void seqListInsert(seqList&s,int index,T val);
	void seqListPopFront(seqList&s);
	void seqListPopBack(seqList&s);
	void seqListErase(seqList&s,int index);
	void seqListReverse(seqList& s);
	void seqListFind(seqList& s, T val);
	void seqListClear(seqList&s);
	void seqListPrint(seqList& s);
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
template<class T>
seqList<T>::seqList()
	:_array(new T[100])
	,_capacity(100)
	,_size(0)
{}
template<class T>
seqList<T>::seqList(const seqList& s) {
	_size = s._size;
	_capacity = s._capacity;
	_array = new T[s._size + 1];
	for (size_t i = 0;i < _size;i++) {
		_array[i] = s._array[i];
	}
}
template<class T>
seqList<T>&seqList<T>::operator=(const seqList& s) {
	if (this != &s) {
		T* array = new T[_size + 1];
		for (size_t i = 0;i < _size;i++) {
			array[i] = _array[i];
		}
		delete[]_array;
		_array = array;
		_size = s._size;
		_capacity = s._size;
	}
	return *this;
}
template<class T>
seqList<T>::~seqList() {
	if (_array) {
		delete[]_array;
		_array = nullptr;
	}
}
template<class T>
bool seqList<T>::isImpty(seqList& s) {
	if (s._size == 0) {
		cout << "该顺序表为空" << endl;
		return true;
	}
	return false;
}
template<class T>
bool seqList<T>::isfull(seqList& s) {
	if (s._size == s._capacity) {
		return true;
	}
	return false;
}
template<class T>
void seqList<T>::seqListpushFront(seqList&s,T val) {
	if (s._size == s._capacity) {
		_array = new T[2 * _capacity];
	}
	for (size_t i = _size;i >0;i--) {

		_array[i] = _array[i - 1];
	}
	_array[0] = val;
	_size++;
}
template<class T>
void seqList<T>::seqListpushBack(seqList& s, T val) {
	if (s._size == s._capacity) {
		_array = new T[2 * _capacity];
	}
	_array[_size] = val;
	_size++;
}
template<class T>
void seqList<T>::seqListPrint(seqList& s) {
	for (size_t i = 0;i < _size;i++) {
		cout << _array[i] << " ";
	}
	cout << endl;
}
template<class T>
void seqList<T>::seqListPopFront(seqList& s) {
	if (s.isImpty(s)) {
		return;
	}
	for (unsigned int i = 0;i < _size;i++) {
		_array[i] = _array[i + 1];
	}
	_size--;
}
template<class T>
void seqList<T>::seqListPopBack(seqList& s) {
	if (s.isImpty(s)) {
		return;
	}
	_size--;
}
template<class T>
void seqList<T>::seqListInsert(seqList& s,int index, T val) {
	if (s._size == s._capacity) {
		_array = new T[2 * s._capacity];
	}
	for (size_t i = _size;i>index;i--) {
		_array[i] = _array[i-1];
	}
	_array[index] = val;
	_size++;
}
template<class T>
void seqList<T>::seqListErase(seqList& s,int index) {
	if (s.isImpty(s)) {
		return;
	}
	for (size_t i = index;i < _size;i++) {
		_array[i] = _array[i + 1];
	}
	_size--;
}
template<class T>
void seqList<T>::seqListClear(seqList& s) {
	if (!s.isImpty(s)) {
		while (_size) {
			_size--;
		}
		_array = nullptr;
	}
}
template<class T>
void seqList<T>::seqListReverse(seqList& s) {
	if (s.isImpty(s)) {
		return;
	}
	int m = _size - 1;
	for (size_t i = 0;i <= (_size - 1) / 2;i++) {
		int temp = _array[i];
		_array[i] = _array[m];
		_array[m] = temp;
		m--;
	}
}
template<class T>
void seqList<T>::seqListFind(seqList& s, T val) {
	for (size_t i = 0;i < _size;i++) {
		if (_array[i] == val) {
			cout << "以查到该数" << val << endl;
			return;
		}
	}
	cout << "该顺序表中没有此数" << endl;
}