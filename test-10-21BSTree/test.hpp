#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTreeNode {
	BSTreeNode(const T& data=T())
	: _left(nullptr)
	, _right(nullptr)
	,_data(data)
	{}
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	T _data;
};
template<class T>
class BSTree {
	typedef BSTreeNode<T>Node;
public:
	BSTree() 
		:_Proot(nullptr)
	{}
	bool Insert(const T& data) {
		if (nullptr == NULL) {
			_Proot = new Node(data);
		}
		Node* cur = _Proot;
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			if (data < cur->_data) {
				cur = cur->_left;
			}
			else if (data > cur->_data) {
				cur = cur->_right;
			}
			else {
				return false;
			}
		}
		cur = new Node(data);
		if (data < parent->_data) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}
		return true;
	}
	Node* leftMost() {
		if (_Proot==nullptr) {
			return nullptr;
		}
		Node* cur = _Proot;
		while (cur->_left) {
			cur = cur->_left;
		}
		return cur;
	}
	Node* rightMost() {
		if (_Proot==nullptr) {
			return nullptr;
		}
		Node* cur = _Proot;
		while (cur->_right) {
			cur = cur->_right;
		}
		return cur;
	}
private:
	Node* _Proot;
};
void TestBSRtee() {
	BSTree<int>bst;
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : array) {
		bst.Insert(e);
	}
	cout << bst.leftMost()->_data << endl;
	cout << bst.rightMost()->_data << endl;
}