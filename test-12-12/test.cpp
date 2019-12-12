#include<iostream>
using namespace std;
#if 0
#include<vector>
#include<algorithm>
int main() {
	int n;
	cin >> n;
	vector<int>A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	vector<int>B(n);
	for (int i = 0; i < n; ++i) {
		B[i] = A[i] * A[i];
	}
	sort(B.begin(), B.end());
	for (int i = 0; i < n; ++i) {
		cout << B[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

#include<vector>
int main() {
	int m, n;
	cin >> m >> n;
	vector<int>nums1;
	vector<int>nums2;
	for (int i = 0; i < m; ++i) {
		cin >> nums1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> nums2[i];
	}
	int p = m-- + n-- - 1;
	while (m >= 0 && n >= 0) {
		nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}
	while (n >= 0) {
		nums1[p--] = nums2[n--];
	}
	for (int i = 0; i < nums1.size(); ++i) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	return 0;
}
