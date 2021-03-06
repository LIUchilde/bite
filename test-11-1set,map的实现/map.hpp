#pragma once
#include"RBTree.hpp"
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
		typename typedef RBTree ::iterator iterator;
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
		size_t size()const {
			return t.size();
		}
		bool empty()const {
			return t.Empty();
		}
		V& operator[](const K& key) {
			return (*(t.Insert(pair<K, V>(key, V())).first)).second;
		}
		pair<iterator, bool>insert(const valuetype& data) {
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
#include<string>
void Testmap() {
	bite::map<string, string>m;
 	m.insert(pair<string,string>("����", "������"));
	cout << m.size() << endl;
	m.insert(make_pair("�ν�", "��ʱ��"));
	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "<-->" << it->second << endl;
		it++;
	}
	m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;

}