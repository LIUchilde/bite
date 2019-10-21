#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
#include<string>
#include<map>
void Test() {
	map<string, string>m;
	m["apple"] = "苹果";
	m["banana"] = " ";
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;
	cout << m.size() << endl;
	cout << m.at("apple") << endl;
	cout << m.at("banana") << endl;
}
int main() {
	Test();
	return 0;
}
#endif

#if 0
#include<string>
#include<map>
void Test() {
	map<string, string>m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("banana", "香蕉"));
	m["orange"] = "橘子";
	m.insert(m.find("apple"), make_pair("water", "水蜜桃"));
	cout << m.size() << endl;
	for (auto& e : m) {
		cout << e.first << "<-->" <<e.second<< endl;
	}
	m.erase("apple");
	for (auto& e : m) {
		cout << e.first<<"<-->"<<e.second << endl;
	}
	if (1 == m.count("apple")) {
		cout << "apple还在" << endl;
	}
	else {
		cout << "apple不在" << endl;
	}
}
int main() {
	Test();
	return 0;
}
#endif

#if 0
#include<map>
int main() {
	map<int, int>m1;
	int array[] = { 0,2,1,5,3,6,4,7,9,8 };
	for (size_t i = 0;i < 10;i++) {
		m1.insert(make_pair(array[i], i));
	}
	for (auto e : m1) {
		cout << e.first << "<-->" << e.second << " ";
	}
	//0<-->0 1<-->2 2<-->1 3<-->4 4<-->6 5<-->3 6<-->5 7<-->7 8<-->9 9<-->8
	cout << endl;
	auto it = m1.begin();
	while (it != m1.end()) {
		cout << it->first << "<-->" << it->second<<" ";
		it++;
	}
	cout << endl;
	map<int, int, greater<int>>m2;
	for (size_t i = 0;i < 10;i++) {
		m2.insert(make_pair(array[i], i));
	}
	for (auto e : m2) {
		cout << e.first << "<-->" << e.second << " ";
	}
	//9<-->8 8<-->9 7<-->7 6<-->5 5<-->3 4<-->6 3<-->4 2<-->1 1<-->2 0<-->0
	cout << endl;
	return 0;
}
#endif

#if 0
#include<string>
#include<map>
void Test() {
	multimap<string, string>m;
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("orange", "橘子"));
	cout << m.size() << endl;
	for (auto& e : m) {
		cout << e.first << "<-->" << e.second<<" ";
	}
	cout << endl;
}
int main() {
	Test();
	return 0;
}
#endif

#if 0
#include<map>
void Test(){
	multimap<int,int>m;
	int array[] = { 1,3,2,5,4,6,8,7,0,9 };
	for (size_t i = 0;i < 10;i++) {
		m.insert(make_pair(array[i],i));
	}
	for (auto& e : m) {
		cout << e.first << "<-->" << e.second << " ";
	}
	cout << endl;
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "<-->" << it->second << " ";
		it++;
	}
	cout << endl;
	it = m.lower_bound(1);
	cout << it->first << "<-->" << it->second << endl;
	cout << endl;
	 it = m.upper_bound(1);
	cout << it->first << "<--> " << it->second << " ";
	cout << endl;
}
int main() {
	Test();
	return 0;
}
#endif

#if 0
#include<set>
int main() {
	//去重   排序
	int array[] = { 0,2,1,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0 };
	set<int>s;
	for (auto& e: array) {
		s.insert(e);
	}
	auto it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		it++;
	}
	return 0;
}
#endif

#include<set>
int main() {
	//去重   排序
	int array[] = { 0,2,1,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0 };
	multiset<int>s;
	for (auto& e : array) {
		s.insert(e);
	}
	auto it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		it++;
	}
	return 0;
}

