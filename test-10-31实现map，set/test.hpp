#pragma once
#if 0
#include<iostream>
enum Color{RED,BLACK};
using namespace std;
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
struct RBTreeIterator {
	typedef RBTreeNode<T>Node;
	typedef RBTreeIterator<T>self;
public:
	RBTreeIterator(Node*pNode) 
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
	self operator++(int) {
		self temp(*this);
		Increament();
		return temp;
	}
	self& operator--() {
		Decreament();
		return *this;
	}
	self operator--(int) {
		self temp(*this);
		Decreament();
		return temp;
	}
	bool operator==(const self&s) {
		return _pNode == s._pNode;
	}
	bool operator!=(const self& s) {
		return _pNode != s._pNode;
	}
	void Increament() {
		if (_pNode->_pRight) {
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft) {
				_pNode = _pNode->_pLeft;
			}
		}
		else {
			Node* pParent = _pNode->_pParent;
			while (pParent->_pRight == _pNode) {
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			if (_pNode->_pRight != pParent) {
				_pNode = pParent;
			}
		}
	}
	void Decreament() {
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED) {
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
	Node* _pNode;
};
template<class T>
class RBTree {
	typedef RBTreeNode<T>Node;
public:
	typedef RBTreeIterator<T>iterator;
public:
	RBTree() {
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const T& data) {
		Node*& pRoot = GetRoot();
		if (pRoot == nullptr) {
			pRoot = new Node(data);
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
		while (_pHead != pParent && pParent->_color == RED) {
			Node* grandfather = pParent->_pParent;
			if (grandfather->_pLeft == pParent) {
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
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
	Node* LeftMost() {
		Node*pRoot = GetRoot();
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
	iterator Begin() {
		return iterator(LeftMost());
	}
	iterator End() {
		return iterator(_pHead);
	}
	void InOrder() {
		_InOrder(GetRoot());
	}
	bool IsvalidRBTree() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "违反性质二：根结点的颜色为黑色" << endl;
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
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && pParent->_color == RED && pRoot->_color == RED) {
			cout << "违反性质三不能存在连在一起的红色结点：" << endl;
			return false;
		}
		if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr) {
			if (pathblack != blackCount) {
				cout << "违反性质四：每条路径上的黑色结点数目相同" << endl;
				return false;
			}
		}
		return _IsvalidRBTree(pRoot->_pLeft, blackCount, pathblack) && _IsvalidRBTree(pRoot->_pRight, blackCount, pathblack);
	}
	Node*& GetRoot() {
		return _pHead->_pParent;
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
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (pPParent == _pHead) {
			pSubL = _pHead->_pParent;
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
	int a[] = { 2,4,1,3,6,5,9,7,8,0 };
	RBTree<int>t;
	for (auto e : a) {
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	auto it = t.Begin();
	while (it != t.End()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	if (t.IsvalidRBTree()) {
		cout << "is RBTree" << endl;
	}
	else {
		cout << "not is RBTree" << endl;
	}
}
#endif

#pragma once
#include<iostream>
enum Color { RED, BLACK };
using namespace std;
template<class T>
struct RBTreeNode {
	RBTreeNode(const T& data = T(), Color color = RED)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
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
	self operator++(int) {
		self temp(*this);
		Increament();
		return temp;
	}
	self& operator--() {
		Decreament();
		return *this;
	}
	self operator--(int) {
		self temp(*this);
		Decreament();
		return temp;
	}
	bool operator==(const self& s) {
		return _pNode == s._pNode;
	}
	bool operator!=(const self& s) {
		return _pNode != s._pNode;
	}
	void Increament() {
		if (_pNode->_pRight) {
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft) {
				_pNode = _pNode->_pLeft;
			}
		}
		else {
			Node* pParent = _pNode->_pParent;
			while (pParent->_pRight == _pNode) {
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			if (_pNode->_pRight != pParent) {
				_pNode = pParent;
			}
		}
	}
	void Decreament() {
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED) {
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
	Node* _pNode;
};

//key可能是键值对<key,value> 也可能是key
//不论结点中存储的是键值对还是key，都是按照key来比较的
//keyofvalue：提取data中的key
template<class T,class keyofvalue>
class RBTree {
	typedef RBTreeNode<T>Node;
public:
	typedef RBTreeIterator<T>iterator;
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	pair<iterator,bool> Insert(const T& data) {
		Node*& pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if (pRoot == nullptr) {
			pNewNode = pRoot = new Node(data);
			pRoot->_pParent = _pHead;
		}
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (keyofvalue()(data) < keyofvalue()(pCur->_data)) {
				pCur = pCur->_pLeft;
			}
			else if (keyofvalue()(data) > keyofvalue()(pCur->_data)) {
				pCur = pCur->_pRight;
			}
			else {
				return make_pair(iterator(pCur),false);
			}
		}
		pNewNode = pCur = new Node(data);
		if (keyofvalue()(data) < keyofvalue()(pParent->_data)) {
			pParent->_pLeft = pCur;
		}
		else {
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;
		while (_pHead != pParent && pParent->_color == RED) {
			Node* grandfather = pParent->_pParent;
			if (grandfather->_pLeft == pParent) {
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
		_size++;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode),true);
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
	iterator Begin() {
		return iterator(LeftMost());
	}
	iterator End() {
		return iterator(_pHead);
	}
	bool Empty()const {
		return _pHead->_pLeft == _pHead->_pRight == _pHead;
	}
	size_t size()const {
		return _size;
	}
	iterator Find(const T&data) {
		Node* pCur = GetRoot();
		while (pCur) {
			if (keyofvalue()(data) == keyofvalue()(pCur->_data)) {
				return iterator(pCur);
			}
			else if (keyofvalue()(data) < keyofvalue()(pCur->_data)) {
				pCur = pCur->_pLeft;
			}
			else {
				pCur = pCur->_pRight;
			}
		}
		return End();
	}
	void clear() {
		_Destroy(GetRoot());
	}
	void InOrder() {
		_InOrder(GetRoot());
	}
	bool IsvalidRBTree() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "违反性质二：根结点的颜色为黑色" << endl;
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
		size_t pathblack = 0;
		return _IsvalidRBTree(pRoot, blackCount, pathblack);
	}
private:
	void _Destroy(Node* pRoot) {
		if (pRoot) {
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot == nullptr;
		}
	}
	bool _IsvalidRBTree(Node* pRoot, size_t blackCount, size_t pathblack) {
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color == BLACK) {
			pathblack++;
		}
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && pParent->_color == RED && pRoot->_color == RED) {
			cout << "违反性质三不能存在连在一起的红色结点：" << endl;
			return false;
		}
		if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr) {
			if (pathblack != blackCount) {
				cout << "违反性质四：每条路径上的黑色结点数目相同" << endl;
				return false;
			}
		}
		return _IsvalidRBTree(pRoot->_pLeft, blackCount, pathblack) && _IsvalidRBTree(pRoot->_pRight, blackCount, pathblack);
	}
	Node*& GetRoot() {
		return _pHead->_pParent;
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
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (pPParent == _pHead) {
			pSubL = _pHead->_pParent;
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
	size_t _size;
};


