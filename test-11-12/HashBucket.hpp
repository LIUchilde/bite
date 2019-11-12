#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct HBNode {
	HBNode(const T&data=T())
		:_data(data)
		,_pNext(nullptr)
	{}
private:
	T _data;
	HBNode<T>* _pNext;
};
//T如果是整形的话
template<class T>
struct T2IntDef
{
	T operator(const T& data) {
		return data;
	}
};
//T如果是其他类型：需要用户给出转换的方式
struct String2INT
{
	size_t operator()(const string& s) {
		const char* str = s.c_str();
		unsigned int seed = 131;
		unsigned int hash = 0;
		while (*str) {
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};
template<class T,class KOFV,class T2Int=T2IntDef<T>>
class HashBucket;
template<class T,class KOFV,class T2Int=T2IntDef<T>>
struct HBIterator
{
	typedef HBNode<T>Node;
	typedef HBIterator<T, KOFV, T2Int>Self;
	typedef HashBucket<T, KOFV, T2Int>HB;
	HBIterator(HB*ht=nullptr,Node*pNode=nullptr)
		:_pNode(pNode)
		._ht(ht)
	{}
	T& operator*() {
		return _pNode->_data;
	}
	T* operator->() {
		return &(operator*());
	}
	Self& operator++() {
		Next();
		return *this;
	}
	Self operator(int) {
		Self temp(*this);
		Next();
		return temp;
	}
	bool operator==(const Self& s)const {
		return _pNode == s._pNode;
	}
	bool operator!=(const Self& s)const {
		return _pNode != s._pNode;
	}
	void Next() {
		if (_pNode->_pNext) {
			_pNode = _pNode->_pNext;
		}
		else {
			size_t bucketNo = _ht->HashFunc(_pNode->_data) + 1;
			for (; bucketNo < _ht->BucketCount(); ++bucketNo) {
				_pNode = _ht->_table[bucketNo];
				if (_pNode) {
					return;
				}
			}
				_pNode = nullptr;
		}
	}
	Node* _pNode;
	HB* _ht;
};
template<class T,class KOFV,class T2Int>
class HashBucket
{
	friend struct HBIterator<T, KOFV, T2Int>;
	typedef HBNode<T>Node;
	typedef HashBucket<T, KOFV, T2Int>Self;
public:
	typedef HBIterator<T, KOFV, T2Int>iterator;
public:
	HashBucket(size_t capacity=10)
		:_table(GetNextPrime(capacity))
		,_size(0)
	{}
	size_t Size()const {
		return _size;
	}
	bool Empty()const {
		return 0 == _size;
	}
	pair<iterator, bool>Insert(const T& data) {
		size_t bucketNo = HashFunc(data);
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (pCur->_data == data) {
				return make_pair(iterator(this, pCur), false);
			}
			pCur = pCur->_data;
		}
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		_size++;
		return make_pair(iterator(this, pCur), true);
	}
	size_t Erase(const T& data) {
		size_t bucketNo = HashFunc(data);
		Node* pCur = _table[bucketNo];
		Node* pPre = nullptr;
		while (pCur) {
			if (data == pCur->_data) {
				if (_table[bucketNo] == data) {
					_table[bucketNo] = pCur->_pNext;
				}
				else {
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				--_size;
				return 1;
			}
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		return 0;
	}
	void clear() {
		for (size_t i = 0; i < _table.capacity(); ++i) {
			Node* pCur = _table[i];
			while (pCur) {
				_table[i] = pCur->_pNext;
				delete pCur;
				pCur = _table[i];
			}
		}
		_size = 0;
	}
	iterator Find(const T& data) {
		size_t bucketNo = HashFunc(data);
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (data == pCur->_data) {
				return iterator(this, pCur);
			}
			pCur = pCur->_pNext;
		}
		return End();
	}
	iterator Begin() {
		for (size_t i = 0; i < _table.capacity(); ++i) {
			if (_table[i]) {
				return iterator(this, _table[i]);
			}
		}
		return End();
	}
	iterator End() {
		return iterator(this, nullptr);
	}
	size_t BucketCount()const {
		return _table.capacity();
	}
	size_t BucketSize(size_t n)const {
		assert(n < _table.capacity());
		Node* pCur = _table[n];
		size_t Count = 0;
		while (pCur) {
			count++;
			pCur = pCur->_pNext;
		}
		return count;
	}
	size_t Bucket(const T& data)const {
		return HashFunc(data);
	}
	void PrintHashBucket() {
		for (size_t i = 0; i < _table.capacity(); ++i) {
			cout << "_table[" << i << "]:";
			Node* pCur = _table[i];
			while (pCur) {
				cout << pCur->_data<<"-->";
				pCur = pCur->_pNext;
			}
			cout << "NULL" << endl;
		}
		cout << endl;
	}
private:
	void CheckCapacity() {
		if (_size == _table.capacity()) {
			Self ht(GetNextPrime(_size));
			for (size_t i = 0; i < _table.capacity(); ++i) {
				Node* pCur = _table[i];
				while (pCur) {
					_table[i] = pCur->_pNext;
					size_t bucketNo = ht.bucketFunc(pCur->_data);
					pCur->_pNext = ht._table[bucketNo];
					ht._table[bucketNo] = pCur;
				}
			}
			this->Swap(ht);
		}
	}
	void Swap(Self& ht) {
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
	size_t bucketFunc() {
		return T2Int()(KOFV()(data)) % _table.capacity();
	}
private:
	vector<Node*>_table;
	size_t _size;
};
void TestHashBucket1() {

}