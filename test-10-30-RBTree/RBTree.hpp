#pragma once
#include<iostream>
using namespace std;
enum Color{RED,BLACK};
template<class T>
struct RBTreeNode {
	RBTreeNode(const T&data=T(),Color color= RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	Color _color;
	T _data;
};
template<class T>
struct RBTreeIterator {
	typedef RBTreeNode<T>Node;
	typedef RBTreeIterator<T>self;
public:
	RBTreeIterator(Node* pNode)
		:_pNode(pNode)
	{}
	RBTreeIterator(const self& s) {
		_pNode = s._pNode;
	}
	T& operator*() {
		return _pNode->_data;
	}
	T* operator->() {
		return &(operator*());
	}
	self& operator++() {
		Increament();
		return *this;
	}
	self operator++() {
		self temp(*this);
		Increament();
		return *this;
	}
	self& operator--() {
		Decreament();
		return *this;
	}
	self operator--() {
		self temp(*this);
		Decreament();
		return *this;
	}
	bool operator==(const self& s) {
		return _pNode = s._pNode;
	}
	bool operator!=(const self& s) {
		return _pNode != s._pNode;
	}
private:
	void Increament() {
		if (_pNode->_pRight) {
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft) {
				_pNode = _pNode->_pLeft;
			}
		}
		else {
			Node* pParent = _pNode->_pParent;
			while (_pNode = pParent->_pRight) {
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			if (_pNode->_pRight != pParent) {
				_pNode = pParent;
			}
		}
	}
	void Decreament() {
		if (_pNode->_pParent->_pParent==_pNode&&_pNode->_color==RED) {
			_pNode = _pNode->_pRight;
		}
		if (_pNode->_pLeft) {
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight) {
				_pNode = _pNode->_pRight;
			}
		}
		else {
			Node* pParent = _pNode->_pParent;
			while (pParent->_pLeft == _pNode) {
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
		}
	}
private:
	Node* _pNode;
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
		if (pRoot == nullptr) {
			pRoot = new Node(data, BLACK);
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
						uncle->_color = BLACK;
						pParent->_color = BLACK;
						grandfather->_color = RED;
						pCur = grandfather;
						pParent = pCur->_pParent;
					}
					else {
						if (pCur == pParent->_pRight) {
							RotateL(pParent);
							swap(pCur, pParent);
						}
						pParent->_color = BLACK;
						grandfather->_color = RED;
						RotateR(grandfather);
					}
				}
				else {
					Node* uncle = grandfather->_pLeft;
					if (uncle && uncle->_color == RED) {
						uncle->_color = BLACK;
						pParent->_color = BLACK;
						grandfather->_color = RED;
						pCur = grandfather;
						pParent = pCur->_pParent;
					}
					else {
						if (pCur == pParent->_pLeft) {
							RotateR(pParent);
							swap(pParent, pCur);
						}
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
	void InOrder() {
		_InOrder(GetRoot());
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
		if (pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight) {
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	bool IsvalidRBTree() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "违反了性质一" << endl;
			return false;
		}
		int blackCount = 0;
		Node* pCur = pRoot;
		while (pCur) {
			if (pCur->_color == BLACK) {
				blackCount++;
			}
			pCur = pCur->_pLeft;
		}
		size_t pathblack = 0;
		return _IsvalidRBTree(pRoot, blackCount, pathblack);
	}
private:
	bool _IsvalidRBTree(Node* pRoot, size_t blackCount, size_t pathblack) {
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color == BLACK) {
			pathblack++;
		}
		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight) {
			if (pathblack != blackCount) {
				cout << "违反性质四：每条路径上的黑色结点个数相同" << endl;
				return false;
			}
		}
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && pParent->_color == RED && pRoot->_color == RED) {
			cout << "违反性质三：红色结点不能连在一起" << endl;
			return false;
		}
		return _IsvalidRBTree(pRoot->_pLeft,blackCount,pathblack) && _IsvalidRBTree(pRoot->_pRight,blackCount,pathblack);
	}
	void RotateL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		pParent->_pRight = pSubRL;
		if (pSubRL) {
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;
		if (pPParent == _pHead) {
			_pHead->_pParent=pSubR;
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
		Node*pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (pPParent == _pHead) {
			_pHead->_pParent = pSubL;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
	}
	Node*& GetRoot() {
		return _pHead->_pParent;
	}
	Node* _InOrder(Node* pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}

		return pRoot;
	}
private:
	Node* _pHead;
};
void TestRBTree() {
	int a[] = { 5, 3, 4 ,1, 7, 8, 2, 6, 0, 9 };
	RBTree<int>t;
	for (auto e : a) {
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	if (t.IsvalidRBTree()) {
		cout << "is RBTree" << endl;
	}
	else {
		cout << "is not RBTree" << endl;
	}
}
