#include<iostream>
using namespace std;
#if 0
int getcount(int n) {
	int count = 0;
	if (n < 3) {
		count = 1;
	}
	else {
		count = getcount(n - 1) + getcount(n - 2);
	}
	return count;
}
int main() {
	int n;
	while (cin >> n) {
		cout << getcount(n) << endl;
	}
	return 0;
}
#endif

#if 0
#include<algorithm>
#include<vector>
int main() {
	vector<int>n{ 0,1,3,2,5,4 };
	sort(n.begin(), n.end());
	for (auto& e : n) {
		cout << e;
	}
	cout << " ";
	return 0;
}
#endif


#if 0
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<vector<int> > res;
		for (int i = 0; i < N - 2; ++i) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = N - 1;
			while (l < r) {
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0) {
					--r;
				}
				else if (s < 0) {
					++l;
				}
				else {
					res.push_back({ nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[++l]);
					while (l < r && nums[r] == nums[--r]);
				}
			}
		}
		return res;
	}
};
#endif

#if 0
#include<vector>
#include<algorithm>
vector<vector<int>>threesum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>res;
	int N = nums.size();
	for (int i = 0; i < N - 2; ++i) {
		if (nums[i] > 0) {
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int l = i + 1;
		int r = N - 1;
		while (l < r) {
			int s = nums[i] + nums[l] + nums[r];
			if (s < 0) {
				++l;
			}
			else if (s > 0) {
				--r;
			}
			else {
				res.push_back({ nums[i],nums[l],nums[r] });
				while (l < r && nums[l] == nums[++l]);
				while (l < r && nums[r] == nums[--r]);
			}
		}
	}
	return res;
}
int main() {
	vector<int>v{ -1, 0, 1, 2, -1, -4 };
	cout << threesum << endl;
	return 0;
}
#endif

#if 0
#include<vector>
#include<algorithm>
int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int ret;
	int min = abs(nums[0] + nums[1] + nums[2] - target);
	int temp1, temp2;
	for (int i = 0; i < size - 2; ++i) {
		for (int j = i + 1; j < size - 1; ++j) {
			for (int k = j + 1; k < size; ++k) {
				temp1 = nums[i] + nums[j] + nums[k];
				temp2 = abs(temp1 - target);
				if (temp2 <= min) {
					min = temp2;
					ret = temp1;
				}
			}
		}
	}
	return ret;
}
int main() {
	vector<int>v{-1,2,1,4};
	int targe = 1;
	cout<<threeSumClosest(v, targe)<<endl;
	return 0;
}
#endif



