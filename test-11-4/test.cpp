#include<iostream>
using namespace std;
#if 0
struct RandomListNode {
	int label;
	struct RandomListNode* next, * random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead==nullptr) {
		return NULL;
	}
	RandomListNode* pCur = pHead;
	while (pCur) {
		RandomListNode* pClone = new RandomListNode(pCur->label);
		pClone->next = pCur->next;
		pCur->next = pClone;
		pCur = pClone->next;
	}
	pCur = pHead;
	while (pCur) {
		RandomListNode* pClone = pCur->next;
		if (pCur->random) {
			pClone->random = pCur->random->next;
		}
		pCur = pClone->next;
	}
	pCur = pHead;
	RandomListNode* result = pHead->next;
	while (pCur) {
		RandomListNode* pClone = pCur->next;
		pCur->next = pClone->next;
		pCur = pCur->next;
		if (pCur != nullptr) {
			pClone->next = pCur->next;
		}
	}
	return result;
}
int main() {
	return 0;
}
#endif

#if 0
#include<vector>
int MoreThanHalfNum_Solution(vector<int> numbers) {
	size_t size = numbers.size();
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (numbers[i] == numbers[j]) {
				count++;
			}
		}
			if (count > size / 2) {
				return numbers[i];
			}
			else {
				count = 0;
			}
		}
	return 0;
}
int main() {
	vector<int>v;
	v = { 1,2,3,2,2,2,5,4,2 };
	cout<<MoreThanHalfNum_Solution(v)<<endl;
	return 0;
}
#endif

#if 0
#include<vector>
int FindGreatestSumOfSubArray(vector<int> array) {
	int m = array[0];
	int n = array[0];
	for (int i = 1; i < array.size(); i++) {
		m += array[i];
		if (m < array[i]) {
			m = array[i];
		}
		if (m > n) {
			n = m;
		}
	}
	return n;
}
int main() {
	vector<int>v;
	v = { 6,-3,-2,7,-15,1,2,2 };
	cout<<FindGreatestSumOfSubArray(v)<<endl;
	return 0;
}
#endif
