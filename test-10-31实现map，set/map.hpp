#pragma once
#include"test.hpp"
namespace bite {
	template<class K,class V>
	class map {
		typedef pair<K, V>valuetype;
		struct keyofvalue {
			const K& operator()(const valuetype& data) {
				return data.first;
			}
		};
		typedef RBTree<valuetype, keyofvalue>RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		map()
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
		V& operator[](const K& key) {
			return (*(t.Insert(pair<K, V>(key, V())).first)).second;
		}
		pair<iterator,bool>insert(const valuetype& data) {
			return t.Insert(data);
		}
		void clear() {
			return t.clear();
		}
		iterator find(const K& key) {
			return t.Find(pair<K, V>(key, V()));
		}
	private:
		RBTree t;
	};
}
#include"string"
void Testmap() {
	bite::map<string, string>m;
	m.insert(pair<string, string>("李逵", "黑旋风"));
	m.insert(make_pair("宋江", "及时雨"));
	m["李逵"] = "铁牛";
	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "<-->" << it->second << endl;
		it++;
	}
	it=m.find("林冲");
	if (it != m.end()) {
		cout << it->second << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
}
