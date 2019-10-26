#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTreeNode {
	BSTreeNode(const T&data=T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};
template<class T>
class BSTree {
	typedef BSTreeNode<T>Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	bool Insert(const T& data) {
		if (_pRoot == nullptr) {
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data) {
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_pRight;
			}
			else {
				return false;
			}
		}
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}
		else {
			pParent->_pRight = pCur;
		}
		return true;
	}
	bool Delete(const T& data) {
		if (_pRoot == nullptr) {
			return false;
		}
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			if (pCur->_data == data) {
				break;
			}
			else if (data < pCur->_data) {
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else {
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		if (pCur == nullptr) {
			return false;
		}
		if (nullptr == pCur->_pLeft) {
			if (nullptr==pParent) {
				_pRoot= pCur->_pRight;
			}
			else {
				if (pCur = pParent->_pLeft) {
					pParent->_pLeft = pCur->_pRight;
				}
				else {
					pParent->_pRight = pCur->_pRight;
				}
			}
		}
		else if (nullptr == pCur->_pRight) {
			if (nullptr==pParent) {
				_pRoot = pCur->_pLeft;
			}
			else {
				if (pCur == pParent->_pLeft) {
					pParent->_pLeft = pCur->_pLeft;
				}
				else {
					pParent->_pRight = pCur->_pLeft;
				}
			}
		}
		else {
			Node* pDelNode = pCur->_pRight;
			pParent = pCur;
			while (pDelNode->_pLeft) {
				pParent = pDelNode;
				pDelNode = pDelNode->_pLeft;
			}
			pCur->_data = pDelNode->_data;
			if (pDelNode == pParent->_pLeft) {
				pParent->_pLeft = pDelNode->_pRight;
			}
			else {
				pParent->_pRight = pDelNode->_pRight;
			}
			pCur = pDelNode;
		}
		delete pCur;
		return true;
	}
	Node* LeftMost() {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_pLeft) {
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node* RightMost() {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_pRight) {
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	Node* Find(const T& data) {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur) {
			if (data == pCur->_data) {
				return pCur;
			}
			else if (data < pCur->_data) {
				pCur = pCur->_pLeft;
			}
			else {
				pCur = pCur->_pRight;
			}
		}
		return nullptr;
	}
	void InOrder() {
		_InOrder(_pRoot);
	}
private:
	Node* _InOrder(Node* pRoot) {
		if (pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = pRoot;
		_InOrder(pCur->_pLeft);
		cout << pCur->_data << " ";
		_InOrder(pCur->_pRight);
		return pRoot;
	}
private:
	Node* _pRoot;
};
void TestBSTree() {
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int>bst;
	for (auto& e : a) {
		bst.Insert(e);
	}
	bst.InOrder();
	cout << endl;
	cout << bst.LeftMost()->_data << endl;
	cout << bst.RightMost()->_data << endl;
	cout << bst.Find(5)->_data << endl;
	bst.Delete(1);
	bst.InOrder();
}
