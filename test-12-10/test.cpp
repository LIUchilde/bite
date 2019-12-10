#include<iostream>
using namespace std;
#if 0
int reverse(int x) {
	long rst = 0;
	while (x) {
		rst = rst * 10 + x % 10;
		x /= 10;
	}
	if ((int)rst != rst) {
		return 0;
	}
	else {
		return (int)rst;
	}
}
int main() {
	int x;
	while (cin >> x) {
		cout << reverse(x) << endl;
	}
	return 0;
}
#endif

#if 0
#include<vector>
int find(vector<int>& nums, int target) {
	if (nums.size() == 0) {
		return 0;
	}
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int target;
	cin >> target;
	cout << find(v, target) << endl;
	return 0;
}
#endif

#if 0
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	vector<int>res = nums;
	for (int i = res.size() - 1; i >= 0; --i) {
		if (res[i] == 9) {
			res[i] = 0;
			if (i == 0) {
				res.insert(res.begin(), 1);
			}
		}
		else {
			res[i]++;
			break;
		}
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

