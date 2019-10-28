#pragma once
#include<iostream>
using namespace std;
enum Color
{RED,BLACK};
template<class T>
struct RBTreeNode {
	RBTreeNode(const T&data=T(),Color color = RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
};
template<class T>
class RBTree {
	typedef RBTreeNode<T>Node;
public:
	RBTree() {
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const T& data) {
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot) {
			pRoot = new Node(data,BLACK);
			pRoot->_pParent = _pHead;
			return true;
		}
		else {
			Node* pCur = pRoot;
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
			pCur->_pParent = pParent;
			while (pParent != _pHead && pParent->_color == RED) {
				Node* grandfather = pParent->_pParent;
				if (pParent == grandfather->_pLeft) {
					Node* uncle = grandfather->_pRight;
					if (uncle && uncle->_color == RED) {
						//情况一
						uncle->_color = BLACK;
						pParent->_color = BLACK;
						grandfather->_color = RED;
						pCur = grandfather;
						pParent = pCur->_pParent;
					}
					else {
						//叔叔结点不存在||叔叔结点存在并且颜色为黑
						if (pCur == pParent->_pRight) {
							//情况三
							RotateL(pParent);
							swap(pCur, pParent);
						}
						//情况二
						grandfather->_color = RED;
						pParent->_color = BLACK;
						RotateR(grandfather);
					}
				}
				else {
					//一二三的反情况
					Node* uncle = grandfather->_pLeft;
					if (uncle && uncle->_color == RED) {
						//情况一反情况
						uncle->_color = BLACK;
						pParent->_color = BLACK;
						grandfather->_color = RED;
						pCur = grandfather;
						pParent = pCur->_pParent;
					}
					else {
						if (pParent->_pLeft = pCur) {
							//情况三反情况
							RotateR(pParent);
							swap(pParent, pCur);
						}
						//情况二反情况
						pParent->_color = BLACK;
						grandfather->_color = RED;
						RotateL(grandfather);
					}
				}
			}
		}
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
	Node*& GetRoot() {
		return _pHead->_pParent;
	}
	Node* LeftMost() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft) {
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node* RightMost() {
		Node* pRoot = GetRoot();
		if (nullptr == pRoot) {
			return NULL;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight) {
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	void RotateL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		pParent->_pRight = pSubRL;
		if (pSubRL) {
			pSubRL->_pParent=pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		pParent->_pParent = pSubR;
		if (pPParent == _pHead) {
			_pHead->_pParent = pSubR;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubR;
			}
			else {
				pPParent->_pRight = pSubR;
			}
		}
	}
	void RotateR(Node* pParent) {
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		pParent->_pParent = pSubL;
		if (pPParent == _pHead) {
			_pHead->_pParent = pSubL;
		}
		else {
			if (pPParent->_pLeft = pParent) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
	}
	void InOrder() {
		_InOrder(GetRoot());
	}
private:
	Node* _InOrder(Node* pRoot) {
		if (pRoot == nullptr) {
			return NULL;
		}
		_InOrder(pRoot->_pLeft);
		cout << pRoot->_data << " ";
		_InOrder(pRoot->_pRight);
		return pRoot;
	}
private:
	Node* _pHead;
};
void TestRBTree() {
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : a) {
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
}