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
	bool operator != (const self & s) {
		return _pNode != s._pNode;
	}
	const bool operator!=(const self& s)const {
		return _pNode != s._pNode;
	}
	bool operator==(const self& s) {
		return _pNode == s._pNode;
	}
	const bool operator==(const self& s)const {
		return _pNode == s._pNode;
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
			_pNode =_pNode->_pRight;
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
	typedef RBTreeIterator<T>iterator;
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const T& data) {
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
			Node* grandefather = pParent->_pParent;
			if (pParent == grandefather->_pLeft) {
				Node* uncle = grandefather->_pRight;
				if (uncle && uncle->_color == RED) {
					uncle->_color = BLACK;
					pParent->_color = BLACK;
					grandefather->_color = RED;
					pCur = grandefather;
					pParent = pCur->_pParent;
				}
				else {
					if (pCur == pParent->_pRight) {
						RotateL(pParent);
						swap(pParent, pCur);
					}
					pParent->_color = BLACK;
					grandefather->_color = RED;
					RotateR(grandefather);
				}
			}
			else {
				Node* uncle = grandefather->_pLeft;
				if (uncle && uncle->_color == RED) {
					uncle->_color = BLACK;
					pParent->_color = BLACK;
					grandefather->_color = RED;
					pCur = grandefather;
					pParent = pCur->_pParent;
				}
				else {
					if (pCur == pParent->_pLeft) {
						RotateR(pParent);
						swap(pParent, pCur);
					}
					pParent->_color = BLACK;
					grandefather->_color = RED;
					RotateL(grandefather);
				}
			}
		}
		_size++;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
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
	iterator Begin() {
		return iterator(LeftMost());
	}
	iterator End() {
		return iterator(_pHead);
	}
	size_t size()const {
		return _size;
	}
	bool Empty()const {
		return _pHead->_pLeft == _pHead->_pRight == _pHead;
	}
	void clear() {
		_Destroy(GetRoot);
	}
	bool IsvalidRBTree() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "违反性质二：根节点的颜色为黑色" << endl;
			return false;
		}
		Node* pCur = pRoot;
		size_t blackCount = 0;
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
			cout << "违反性质三：不能有连在一起的红色结点" << endl;
			return false;
		}
		if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr) {
			if (pathblack != blackCount) {
				cout << "违反性质四：每条路径上的黑色结点数相同" << endl;
				return false;
			}
		}
		return _IsvalidRBTree(pRoot->_pLeft, blackCount, pathblack) && _IsvalidRBTree(pRoot->_pRight, blackCount, pathblack);
	}
	void* _Destroy(Node* pRoot) {
		if (pRoot) {
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
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
private:
	Node*& GetRoot() {
		return _pHead->_pParent;
	}
private:
	size_t _size;
	Node* _pHead;
};
void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : a)
		t.Insert(e);
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	if (t.IsvalidRBTree())
		cout << "t is RBTree" << endl;
	else
		cout << "t is not RBTree" << endl;
	auto it = t.Begin();
	while (it != t.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
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
	bool operator != (const self& s) {
		return _pNode != s._pNode;
	}
	const bool operator!=(const self& s)const {
		return _pNode != s._pNode;
	}
	bool operator==(const self& s) {
		return _pNode == s._pNode;
	}
	const bool operator==(const self& s)const {
		return _pNode == s._pNode;
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
private:
	Node* _pNode;
};
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
			pNewNode = pRoot = new Node(data,BLACK);
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
			Node* grandefather = pParent->_pParent;
			if (pParent == grandefather->_pLeft) {
				Node* uncle = grandefather->_pRight;
				if (uncle && uncle->_color == RED) {
					uncle->_color = BLACK;
					pParent->_color = BLACK;
					grandefather->_color = RED;
					pCur = grandefather;
					pParent = pCur->_pParent;
				}
				else {
					if (pCur == pParent->_pRight) {
						RotateL(pParent);
						swap(pParent, pCur);
					}
					pParent->_color = BLACK;
					grandefather->_color = RED;
					RotateR(grandefather);
				}
			}
			else {
				Node* uncle = grandefather->_pLeft;
				if (uncle && uncle->_color == RED) {
					uncle->_color = BLACK;
					pParent->_color = BLACK;
					grandefather->_color = RED;
					pCur = grandefather;
					pParent = pCur->_pParent;
				}
				else {
					if (pCur == pParent->_pLeft) {
						RotateR(pParent);
						swap(pParent, pCur);
					}
					pParent->_color = BLACK;
					grandefather->_color = RED;
					RotateL(grandefather);
				}
			}
		}
		++_size;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode),true);
	}
	iterator Find(const T& data) {
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
	iterator Begin() {
		return iterator(LeftMost());
	}
	iterator End() {
		return iterator(_pHead);
	}
	size_t size()const {
		return _size;
	}
	bool Empty()const {
		return _pHead->_pLeft == _pHead->_pRight == _pHead;
	}
	void clear() {
		_Destroy(GetRoot);
	}
	bool IsvalidRBTree() {
		Node* pRoot = GetRoot();
		if (pRoot == nullptr) {
			return true;
		}
		if (pRoot->_color != BLACK) {
			cout << "违反性质二：根节点的颜色为黑色" << endl;
			return false;
		}
		Node* pCur = pRoot;
		size_t blackCount = 0;
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
			cout << "违反性质三：不能有连在一起的红色结点" << endl;
			return false;
		}
		if (pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr) {
			if (pathblack != blackCount) {
				cout << "违反性质四：每条路径上的黑色结点数相同" << endl;
				return false;
			}
		}
		return _IsvalidRBTree(pRoot->_pLeft, blackCount, pathblack) && _IsvalidRBTree(pRoot->_pRight, blackCount, pathblack);
	}
	void* _Destroy(Node* pRoot) {
		if (pRoot) {
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
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
private:
	Node*& GetRoot() {
		return _pHead->_pParent;
	}
private:
	size_t _size;
	Node* _pHead;
};
 template<class K,class V>
 struct keyofvalue {
	 const K& operator()(const pair<K, V>& data) {
		 return data.first;
	 }
 };
 void TestRBTree() {
	 RBTree<pair<int, int>, keyofvalue<int, int>>t;
	 int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	 for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		 t.Insert(make_pair(a[i], i));
	 }
	 auto it = t.Begin();
	 while (it != t.End()) {
		 cout << it->first << "<-->" << it->second << endl;
		 ++it;
	 }
 }


