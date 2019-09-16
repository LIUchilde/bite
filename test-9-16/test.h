#pragma once
template<class T>
struct ListNode {
	ListNode(const T& data = T())
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
		{}
	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
	T _data;
};
namespace bite
{
	template<class T>
	struct ListIterator {
		typedef ListNode<T>Node;
		typedef Node* PNode;
		typedef ListIterator<T>Self;
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& s) 
			:_pNode(s._pNode)
		{}
		T& operator*() {
			return _pNode->_data;
		}
		T* operator->() {
			return &(_pNode->_data);
		}
		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int) {
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--() {
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self operator--(int) {
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& s)const {
			return _pNode != s._pNode;
		}
		bool operator==(const Self& s)const {
			return _pNode == s._pNode;
		}
		PNode _pNode;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef T* iterator;
	public:
		list() {
			CreateHead();
		}
		list(size_t n, const T& data = T()) {
			CreateHead();
			for (size_t i = 0;i < n;i++) {
				push_back(data);
			}
		}
		list(T* first, T* last) {
			CreateHead();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l) {
			CreateHead();
			PNode pCur = l._pHead;
			while (pCur != l._pHead) {
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}
		~list() {
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		iterator begin() {
			return iterator(_pHead->_pNext);
		}
		iterator end() {
			return iterator(_pHead);
		}
		size_t size()const {
			size_t count = 0;
			PNode pCur = _pHead;
			while (pCur != _pHead) {
				count++;
				pCur = pCur->pNext;
			}
		}
		bool empty()const {
			return _pHead == _pHead->_pNext;
		}
		void resize(size_t newsize, const T& data = T()) {
			size_t oldsize = size();
			if (oldsize < newsize) {
				for (size_t i=oldsize;i < newsize;++i) {
					push_back(data);
				}
			}
			else {
				for (size_t i = newsize;i < oldsize;i++) {
					pop_back(data);
				}
			}
		}
		T& front() {
			return _pHead->_pNext;
		}
		const T& front()const {
			return _pHead->_pNext;
		}
		T& back() {
			return _pHead->_pPre;
		}
		const T& back()const {
			return _pHead->_pPre;
		}
		void push_back(const T& data) {
			PNode PnewNode = new Node(data);
			PnewNode->_pNext = _pHead;
			PnewNode->_pPre = _pHead->_pPre;
			_pHead->_pPre = PnewNode;
			PnewNode->_pPre->_pNext = PnewNode;
		}
		void pop_back() {
			PNode pDelNode = _pHead->_pPre;
			_pHead->_pPre = pDelNode->_pPre;
			pDelNode->_pPre->_pNext = _pHead;
			delete pDelNode;
		}
		void push_front(const T& data) {
			PNode pNewNode = new Node(data);
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}
		void pop_front() {
			PNode pDelNode = _pHead->_pNext;
			_pHead->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = _pHead;
			delete pDelNode;
		}
		void swap(list<T>& l) {
			swap(_pHead, l._pHead);
		}
		void clear() {
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead) {
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		iterator insert(iterator pos, const T& x) {
			PNode pNewNode = new Node(x);
			PNode pCur = pos._pNode;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		iterator earse(iterator pos) {
			PNode pCur = pos._pNode;
			if (pCur == _pHead) {
				return end();
			}
			PNode pRet = pCur->_pNext;
			pCur->_pPre->_pNext = pCur->_pNext;
			pCur->_pNext->_pPre = pCur->_pPre;
			delete pCur;
			return iterator(pRet);
		}
	private:
		void CreateHead() {
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}