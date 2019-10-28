#pragma once
#include<iostream>
using namespace std;
template<class T>
struct AVLTreeNode {
	AVLTreeNode(const T&data=T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};
template<class T>
class AVLTree {
	typedef AVLTreeNode<T>Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	bool Insert(const T& data = T()) {
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
		pCur->_pParent = pParent;
		while (pParent) {
			if (pCur == pParent->_pLeft) {
				pParent->_bf--;
			}
			else {
				pParent->_bf++;
			}
			if (pParent->_bf == 0) {
				break;
			}
			else if (pParent->_bf == 1||pParent->_bf==-1) {
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else {
				if (pParent->_bf == 2) {
					if (pCur->_bf == 1) {
						RotateL(pParent);
					}
					else {
						RotateRL(pParent);
					}
				}
				else {
					if (pCur->_bf == -1) {
						RotateR(pParent);
					}
					else {
						RotateLR(pParent);
					}
				}
				break;
			}
		}
		return true;
	}
	void RotateR(Node*pParent) {
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
		if (pPParent == nullptr) {
			_pRoot = pSubL;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
		pParent->_bf = pSubL->_bf = 0;
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
		if (pPParent==nullptr) {
			_pRoot = pSubR;
		}
		else {
			if (pParent == pPParent->_pLeft) {
				pPParent->_pLeft = pSubR;
			}
			else {
				pPParent->_pRight = pSubR;
			}
		}
		pParent->_bf = pSubR->_bf = 0;
	}
	void RotateRL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;
		RotateR(pParent->_pRight);
		RotateL(pParent);
		if (bf == -1) {
			pSubR->_bf = 1;
		}
		else if (bf == 1) {
			pParent->_bf = -1;
		}
	}
	void RotateLR(Node* pParent) {
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;
		RotateL(pParent->_pLeft);
		RotateR(pParent);
		if (bf == -1) {
			pParent->_bf = 1;
		}
		else if (bf == 1) {
			pSubL->_bf = -1;
		}
	}
	void InOrder() {
		_InOrder(_pRoot);
	}
	Node* LeftMost() {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_pLeft) {
			pCur = pCur->_pLeft;
		}
	}
	Node* RightMpst() {
		if (nullptr == _pRoot) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_pRight) {
			pCur = pCur->_pRight;
		}
	}
private:
	void _InOrder(Node* pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	Node* _pRoot;
};
void TestAVLTree() {
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int> v;
	for (auto e : a) {
		v.Insert(e);
	}
	v.InOrder();
	cout << endl;
	cout << v.LeftMost()->_data << endl;
	cout << v.RightMpst()->_data << endl;
}
