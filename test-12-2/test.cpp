#include<iostream>
using namespace std;

#if 0
int main() {
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		int num = 2 * n;
		vector<int>v(num);
		for (int i = 0; i < v.size(); ++i) {
			cin >> v[i];
		}
		while (k--) {
			vector<int>res;
			res = v;
			for (int i = 0; i < n; ++i) {
				v[2 * i] = res[i];
				v[2 * i + 1] = res[n + i];
			}
		}
		for (int i = 0; i < num - 1; ++i) {
			cout << v[i] << ' ';
		}
		cout << v[num-1] << endl;
	}
	return 0;
}
#endif

#if 0
#include<vector>
int getMost(vector<vector<int>>board) {
	int i, j;
	for (i = 1; i < 6; i++) {
		board[0][i] += board[0][i - 1];
	}
	for (i = 0; i < 6; ++i) {
		board[i][0] += board[i - 1][0];
	}
	for (i = 1; i < 6; ++i) {
		for (j = 1; j < 6; ++j) {
			if (board[i - 1][j] > board[i][j - 1]) {
				board[i][j] += board[i - 1][j];
			}
			else {
				board[i][j] += board[i][j - 1];
			}
		}
	}
	return board[5][5];
}
int main(){
	return 0;
}
#endif

#include<vector>
#include<string>
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		int max = 0;
		vector<vector<int>>v(len1 + 1, vector<int>(len2 + 1));
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				if (max < v[i][j]) {
					max = v[i][j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}