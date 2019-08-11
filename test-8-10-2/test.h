#pragma once
class SeqList {
private:
	int* array;
	int capacity;
	 int size;
public:
	SeqList();
	~SeqList();
	void ensurecapacity();
	void SeqListPushFront(int val);
	void SeqListPushBack(int val);
	void SeqListPopFront();
	void SeqListPopBack();
	void SeqlistInsert(int index, int val);
	void SeqListErase(int index);
	void SeqListprint();
};