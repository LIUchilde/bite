#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct HBNode {
	HBNode(const T&data)
		:_data(data)
		,_pNext(nullptr)
	{}
	HBNode<T>* _pNext;
	T _data;
};
template<class T>
class HashBucket {
	typedef HBNode<T>Node;
public:
	HashBucket(size_t capacity) 
		:_table(capacity,nullptr)
	{}
	bool Insert(const T& data) {
		//1.计算当前元素所在的桶号
		size_t buckutNo = HashFunc(data);
		Node* pCur = _table[buckutNo];
		while (pCur) {
			if (pCur->_data == data) {
				return false;
			}
			pCur = pCur->_pNext;
		}
		//插入新节点
		pCur = new Node(data);
		pCur->_pNext = _table[buckutNo];
		_table[buckutNo] = pCur;
		_size++;
		return true;
	}
	Node* Find(const T& data) {
		size_t buckNo = HashFunc(data);
		Node* pCur = _table[buckNo];
		while (pCur) {
			if (pCur->_data == data) {
				return pCur;
			}
			pCur = pCur->_pNext;
		}
		return NULL;
	}
	bool Erase(const T& data) {
		size_t buckNo = HashFunc(data);
		Node* pCur = _table[buckNo];
		Node* pPre = nullptr;
		while (pCur) {
			if (data == pCur->_data) {
				if (_table[buckNo] == data) {
					//删除的是第一个节点
					_table[buckNo] = pCur->_pNext;
				}
				else {
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				_size--;
			}
		}
		pPre = pCur;
		pCur = pCur->_pNext;
		return false;
	}
private:
	void Swap(HashBucket<T>& ht) {
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
	void checkCapacity() {
		//if (_size == _table.capacity()) {
		//	HashBucket<T>ht(_size * 2);
		//	for (size_t i = 0; i < _table.capacity(); ++i) {
		//		Node* pCur = _table[i];
		//		while (pCur) {
		//			ht.Insert(pCur->_data);
		//			pCur = pCur->_pNext;
		//		}
		//	}
		//	Swap(ht);
		//}

		HashBucket<T>ht(_size * 2);
		//将旧哈希桶中的结点直接搬移到新哈希桶
		for (size_t i = 0; i < _table.capacity(); ++i) {
			Node* pCur = _table[i];
			while (pCur) {
				//1.将pCur结点从旧哈希桶中删除
				_table[i] = pCur->_pNext;
				//2.将pCur插入到新哈希桶中
				size_t buckNo = ht.HashFunc(pCur->_data);
				//3.插入结点
				pCur->_pNext = ht._table[buckNo];
				ht._table[buckNo] = pCur;
			}
		}
		this->Swap(ht);
	}
	size_t HashFunc(const T& data) {
		return data % _table.capacity();
	}
private:
	vector<Node*>_table;
	size_t _size;
};