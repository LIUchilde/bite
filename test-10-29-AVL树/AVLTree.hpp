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
	AVLTreeNode <T>* _pLeft;
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
		pCur->_pParent = pParent;
		while (pParent) {
			if (pCur == pParent->_pRight) {
				pParent->_bf++;
			}
			else {
				pParent->_bf--;
			}
			if (0 == pParent->_bf) {
				break;
			}
			else if (1 == pParent->_bf || -1 == pParent->_bf) {
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
	bool IsAVLTree() {
		return _IsAVLTree(_pRoot);
	}
private:
	void RotateL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		pParent->_pRight = pSubRL;
		if (pSubRL) {
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		pParent->_pParent = pSubR;
		if (nullptr == pPParent) {
			_pRoot = pSubR;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubR;
			}
			else {
				pPParent->_pRight = pSubR;
			}
		}
		pParent->_bf = pSubR->_bf = 0;
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
	void RotateRL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;
		RotateR(pParent->_pRight);
		RotateL(pParent);
		if (bf == -1) {
			pSubR->_bf = 1;
		}
		else if(bf==1){
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
	Node* _InOrder(Node*pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
		return _pRoot;
	}
	bool _IsAVLTree(Node* pRoot) {
		if (pRoot == nullptr) {
			return true;
		}
		int leftHeigth = _Heigth(pRoot->_pLeft);
		int rightHeigth = _Heigth(pRoot->_pRight);
		if (abs(leftHeigth - rightHeigth) > 1 || rightHeigth - leftHeigth != pRoot->_bf) {
			return false;
		}
		return _IsAVLTree(pRoot->_pLeft) && _IsAVLTree(pRoot->_pRight);
	}
	size_t _Heigth(Node* pRoot) {
		if (pRoot == nullptr) {
			return 0;
		}
		size_t leftHeigth = _Heigth(pRoot->_pLeft);
		size_t rightHeigth = _Heigth(pRoot->_pRight);
		return leftHeigth > rightHeigth ? leftHeigth+1 : rightHeigth+1;
	}
private:
	Node* _pRoot;
};
void TestAVLTree() {
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int>t;
	for (auto& e : a) {
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	if (t.IsAVLTree()) {
		cout << " is AVLTree" << endl;
	}
	else {
		cout << "is not AVLTree" << endl;
	}
}