#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m;
	cin >> m;
	vector<int>v(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i];
	}
	int j = 0;
	for (int i = 1; i < m; ++i) {
		if (v[i] != v[j]) {
			v[++j] = v[i];
		}
	}
	cout << ++j << endl;
	return 0;
}
