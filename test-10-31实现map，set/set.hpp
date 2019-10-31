#pragma once
#include"test.hpp"
namespace bite {
	template<class K>
	class set {
		typedef K valuetype;
		struct keyofvalue {
			const K& operator()(const valuetype& data) {
				return data;
			}
		};
		typedef RBTree<valuetype, keyofvalue>RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		set()
			:t()
		{}
		iterator begin() {
			return t.Begin();
		}
		iterator end() {
			return t.End();
		}
		bool empty()const {
			return t.Empty();
		}
		size_t size()const {
			return t.size();
		}
		pair<iterator, bool>insert(const valuetype& data) {
			return t.Insert(data);
		}
		void clear() {
			t.clear();
		}
		iterator find(const K& key) {
			return t.Find(key);
		}
	private:
		RBTree t;
	};
}
void Testset() {
	int a[] = { 1,0,2,9,3,8,4,7,5,6,0,9,8,7,6,5,4,3,2,1 };
	bite::set<int>s;
	for (auto e : a) {
		s.insert(e);
	}
	cout << s.size() << endl;
	auto it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
