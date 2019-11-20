#include<iostream>
using namespace std;
#if 0
#include<map>
void Testmap() {
	map<string, string>m;
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("banana", "香蕉"));
	m["apple"] = "苹果";
	cout << m.size() << endl;
	for (auto e : m) {
		cout << e.first << "--->" << e.second << endl;
	}
	m["peach"] = "桃色";
	for (auto& e : m) {
		cout << e.first << "-->" << e.second << endl;
	}
	m.erase("apple");
	if (1 == m.count("apple")) {
		cout << "apple还在" << endl;
	}
	else {
		cout << "apple被删除" << endl;
	}
}
int main() {
    Testmap();
	return 0;
}
#endif

#if 0
#include<map>
void Testmap() {
	map<int, int>m;
	int array[10] = {1,2,3,4,5,4,3,2,1};
	for (size_t i = 0; i < 10; ++i) {
		m.insert(make_pair(array[i], i));
	}
	for (auto& e : m) {
		cout << e.first << "-->" << e.second << endl;
	}
}
int main() {
	Testmap();
	return 0;
}
#endif

#include<map>
void Testmultimap() {
	int array[10] = { 1,2,3,4,5,3,2,4,2,0 };
	multimap<int, int>m;
	for (size_t i = 0; i < 10; ++i) {
		m.insert(make_pair(array[i], i));
	}
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "-->" << it->second << endl;
		it++;
	}
}
int main() {
	Testmultimap();
	return 0;
}
