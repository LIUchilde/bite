#pragma once
#include<iostream>
using namespace std;
enum Color{RED,BLACK};
template<class T>
struct RBTreeNode {
	RBTreeNode(const T&data=T(),Color color=RED)
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
		if (pRoot == nullptr) {
			pRoot = new Node(data,BLACK);
			pRoot->_pParent = _pHead;
			return true;
		}
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
				//���һ����
				Node* uncle = grandfather->_pRight;
				if (uncle && uncle->_color == RED) {
					uncle->_color = BLACK;
					pParent->_color = BLACK;
					grandfather->_color = RED;
					pCur = grandfather;
					pParent = pCur->_pParent;
				}
				else {
					//�����
					if (pCur == pParent->_pRight) {
						RotateL(pParent);
						swap(pCur, pParent);
					}
					//�����
					pParent->_color = BLACK;
					grandfather->_color = RED;
					RotateR(grandfather);
				}
			}
			else {
				//���һ�����ķ����
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
						swap(pCur, pParent);
					}
					pParent->_color = BLACK;
					grandfather->_color = RED;
					RotateL(grandfather);
				}
			}
		}
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = LeftMost();
		return true;
	}
	void RotateL(Node*pParent) {
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
		if (pPParent == nullptr) {
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
		Node* pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (pPParent == nullptr) {
			_pHead->_pParent = pSubL;
		}
		else {
			if (pParent == pPParent->_pLeft) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
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
	void InOrder() {
		_InOrder(GetRoot());
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
	bool IsValidRBTree() {
		Node* pRoot = GetRoot();
		if (nullptr == pRoot) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "Υ��������һ" << endl;
			return false;
		}
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur) {
			if (pCur->_color == BLACK) {
				blackCount++;
			}
			pCur = pCur->_pLeft;
		}
		size_t pathBlack = 0;
		return _IsValidRBTree(pRoot, blackCount, pathBlack);
}
	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathblack) {
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color == BLACK) {
			pathblack++;
		}
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && pParent->_color == RED && pRoot->_color == RED) {
			cout << "Υ������3�����ܴ�������һ��������ڵ�" << endl;
			return false;
		}
		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight) {
			if (pathblack != blackCount) {
				cout << "Υ��������4��ÿ��·���Ϻ�ɫ�����ͬ" << endl;
				return false;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft,blackCount,pathblack) && _IsValidRBTree(pRoot->_pRight,blackCount,pathblack);
	}
private:
	Node* _pHead;
};
void TestRBTree() {
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int>t;
	for (auto& e : a) {
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	if (t.IsValidRBTree()) {
		cout << "is RBTree" << endl;
	}
	else {
		cout << "not is RBTree" << endl;
	}
}