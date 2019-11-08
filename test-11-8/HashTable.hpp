#pragma once
#include<iostream>
using namespace std;
#include<vector>
enum State{EMPTY,EXIST,DELETE};
template<class T,bool Isline=true>
class HashTable {
	struct Elem {
		T _value;
		State _state;
	};
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		,_size(0)
	{
		for (auto& e : _ht)
			e._state = EMPTY;
	}
	bool Insert(const T& value) {
		checkCapacity();
		//通过哈希函数计算元素在哈希表中的存储位置
		size_t hashAddr = HashFunc(value);
		int i = 0;
		while (EMPTY != _ht[hashAddr]._state) {
			//发生哈希冲突  使用线性探测解决
			if (EXIST == _ht[hashAddr]._state && value == _ht[hashAddr]._value) {
				return false;
			}
			i++;
			if (Isline) {
				++hashAddr;
				if (hashAddr == _ht.capacity()) {
					hashAddr = 0;
				}
			}
			else {
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _ht.capacity();
			}
		}
		_ht[hashAddr]._value = value;
		_ht[hashAddr]._state = EXIST;
		++_size;
		return true;
	}
	int Find(const T& value) {
		size_t hashAddr = HashFunc(value);
		while (EMPTY != _ht[hashAddr]._state) {
			if (EXIST == _ht[hashAddr]._state&&value==_ht[hashAddr]._value) {
				return hashAddr;
			}
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		return -1;
	}
	bool Erase(const T& value) {
		int ret = Find(value);
		if (ret != -1) {
			_ht[ret]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
private:
	size_t HashFunc(const T& value) {
		return value % _ht.capacity();
	}
	void checkCapacity() {
		if ((_size / ht.capacity()) * 10 >= 7) {
			HashTable<T>newHT(_ht.capacity() * 2);
			for (size_t i = 0; i < _ht.capacity(); ++i) {
				if (_ht[i]._state == EXIST) {
					newHT.Insert(_ht[i].value);
				}
			}
			swap(newHT);
		}
	}
	void swap(HashTable<T>& ht) {
		_ht.swap(ht._ht);
		swap(_size, ht._size);
	}
private:
	vector<Elem>_ht;
	size_t _size;
};
void TestHashTable() {
	HashTable<int>ht;
	ht.Insert(4);
	ht.Insert(7);
	ht.Insert(8);
	ht.Insert(27);
}