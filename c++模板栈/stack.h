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
	stack();//创建栈
	~stack();//销毁栈
	bool push(stack*s,Datatype val);//压栈
	Datatype pop(stack* s);//出栈并返回出栈元素
	Datatype size(stack* s);//返回栈中元素个数
	Datatype Top(stack* s);//返回栈顶元素
	void Clear(stack* s);//清空栈
	bool empty(stack* s);//判空
};
template<class T>
bool stack<T>::push(stack* s,Datatype val) {
	if (s->top == stack_size - 1) {
		cout << "栈空" << endl;
		return false;
	}
	s->top++;
	s->arr[s->top] = val;
	return true;
}
template<class T>
Datatype stack<T>::pop(stack* s) {
	if (s->top == stack_size - 1) {
		cout << "栈空" << endl;
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
