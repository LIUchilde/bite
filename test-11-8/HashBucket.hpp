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
		//1.���㵱ǰԪ�����ڵ�Ͱ��
		size_t buckutNo = HashFunc(data);
		Node* pCur = _table[buckutNo];
		while (pCur) {
			if (pCur->_data == data) {
				return false;
			}
			pCur = pCur->_pNext;
		}
		//�����½ڵ�
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
					//ɾ�����ǵ�һ���ڵ�
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
		//���ɹ�ϣͰ�еĽ��ֱ�Ӱ��Ƶ��¹�ϣͰ
		for (size_t i = 0; i < _table.capacity(); ++i) {
			Node* pCur = _table[i];
			while (pCur) {
				//1.��pCur���Ӿɹ�ϣͰ��ɾ��
				_table[i] = pCur->_pNext;
				//2.��pCur���뵽�¹�ϣͰ��
				size_t buckNo = ht.HashFunc(pCur->_data);
				//3.������
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