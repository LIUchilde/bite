#pragma once
#include<iostream>
#include"stack.h"
#define stack_size 100
using namespace std;
typedef int Datatype;
template<class T>
class stack {
private:
	int arr[stack_size];
	int top;
public:
	stack();//����ջ
	~stack();//����ջ
	bool push(stack*s,Datatype val);//ѹջ
	Datatype pop(stack* s);//��ջ�����س�ջԪ��
	Datatype size(stack* s);//����ջ��Ԫ�ظ���
	Datatype Top(stack* s);//����ջ��Ԫ��
	void Clear(stack* s);//���ջ
	bool empty(stack* s);//�п�
};
template<class T>
bool stack<T>::push(stack* s,Datatype val) {
	if (s->top == stack_size - 1) {
		cout << "ջ��" << endl;
		return false;
	}
	s->top++;
	s->arr[s->top] = val;
	return true;
}
template<class T>
Datatype stack<T>::pop(stack* s) {
	if (s->top == stack_size - 1) {
		cout << "ջ��" << endl;
		return false;
	}
	return s->arr[--s->top];

}
template<class T>
Datatype stack<T>::size(stack* s) {
	return top;
}
template<class T>
Datatype stack<T>::Top(stack* s) {
	return s->arr[s->top - 1];
}
template<class T>
void stack<T>::Clear(stack* s) {
	while (top > 0) {
		pop(&s);
	}
}
template<class T>
bool stack<T>::empty(stack* s) {
	return (s->top == 0 ? true : false);
}
