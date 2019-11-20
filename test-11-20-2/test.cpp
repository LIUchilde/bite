#include<iostream>
using namespace std;
#if 0
#include<map>
void Testmap() {
	map<string, string>m;
	m.insert(pair<string, string>("peach", "����"));
	m.insert(make_pair("banana", "�㽶"));
	m["apple"] = "ƻ��";
	cout << m.size() << endl;
	for (auto e : m) {
		cout << e.first << "--->" << e.second << endl;
	}
	m["peach"] = "��ɫ";
	for (auto& e : m) {
		cout << e.first << "-->" << e.second << endl;
	}
	m.erase("apple");
	if (1 == m.count("apple")) {
		cout << "apple����" << endl;
	}
	else {
		cout << "apple��ɾ��" << endl;
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
