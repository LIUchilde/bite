#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTreeNode {
	BSTreeNode(const T&data=T())
		:_left(nullptr)
		,_right(nullptr)
		,_data(data)
	{}
	BSTreeNode* _left;
	BSTreeNode* _right;
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
		if (nullptr == _pRoot) {
			_pRoot = new Node(data);
		}
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data) {
				pCur = pCur->_left;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_right;
			}
			else {
				return false;
			}
		}
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_left = pCur;
		}
		else {
			pParent->_right = pCur;
		}
		return true;
	}
	Node* leftMost() {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_left) {
			pCur = pCur->_left;
		}
		return pCur;
	}
	Node* rightMost() {
		if (_pRoot == nullptr) {
			return NULL;
		}
		Node* pCur = _pRoot;
		while (pCur->_right) {
			pCur = pCur->_right;
		}
		return pCur;
	}
	Node* Find(const T& data) {
		Node* pCur = _pRoot;
		while (pCur) {
			if (data == pCur->_data) 
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_left;
			else 
				pCur = pCur->_right;
		}
		return nullptr;
	}
	bool Delete(const T&data) {
		if (_pRoot == nullptr) {
			return false;
		}
		//找待删除结点在二叉搜索树的位置
		//保存其双亲
		Node* pCur = _pRoot;
		Node* pPrent = nullptr;
		while (pCur) {
			if (pCur->_data == data) {
				break;
			}
			else if (data < pCur->_data) {
				pPrent = pCur;
				pCur = pCur->_left;
			}
			else {
				pPrent = pCur;
				pCur = pCur->_right;
			}
		}
		//该节点不在二叉搜索树
		if (nullptr == pCur) {
			return false;
		}
		//找到该节点，删除
		//只有右孩子||叶子结点
		if (nullptr == pCur->_left) {
			if (pPrent == nullptr) {
				_pRoot = pCur->_right;
			}
			else if (pCur == pPrent->_left) {
				pPrent->_left = pCur->_right;
			}
			else {
				pPrent->_right = pCur->_right;
			}
		}
		//只有左孩子
		else if (nullptr == pCur->_right) {
			if (nullptr == pPrent) {
				_pRoot = pCur->_left;
			}
			else if (pCur == pPrent->_left) {
				pPrent->_left = pCur->_left;
			}
			else {
				pPrent->_right = pCur->_left;
			}
		}
		else {
			Node* pDelNode = pCur->_right;
			pPrent = pCur;
			while (pDelNode->_left) {
				pPrent = pDelNode;
				pDelNode = pDelNode->_left;
			}
			pCur->_data = pDelNode->_data;
			if (pDelNode == pPrent->_left) {
				pPrent->_left = pDelNode->_right;
			}
			else {
				pPrent->_right = pDelNode->_right;
			}
			pCur = pDelNode;
		}
		delete pCur;
		return true;
	}
	void InOrder() {
		_InOrder(_pRoot);
	}
private:
	void _InOrder(Node*pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_left);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_right);
		}
	}
private:
	Node* _pRoot;
};
void TestBSTree() {
	int array[] = { 0,1,9,2,3,5,7,8,4,6 };
	BSTree<int>bst;
	for (auto& e : array) {
		bst.Insert(e);
	}
	cout << bst.leftMost()->_data << endl;
	cout << bst.rightMost()->_data << endl;
	bst.InOrder();
	cout << endl;
	cout << bst.Find(5)->_data << endl;
	bst.Delete(8);//只有右孩子，是其双亲的右孩子
	bst.InOrder();
	cout << endl;
	bst.Delete(0);
	bst.Delete(1);//只有右孩子，是其双亲的叫左孩子
	bst.InOrder();
	cout << endl;
	bst.Delete(5);
	bst.InOrder();

}
