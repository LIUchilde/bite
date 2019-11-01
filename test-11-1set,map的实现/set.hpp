#pragma once
#include"RBTree.hpp"
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
			return t.clear();
		}
		iterator find(const K& key) {
			return t.Find(key);
		}
	private:
		RBTree t;
	};
}
void Testset()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1 };
	bite::set<int> s;
	for (auto e : array)
		s.insert(e);

	cout << s.size() << endl;

	for (auto e : s)
		cout << e << " ";
	cout << endl;
}