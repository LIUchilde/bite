#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
#include<vector>
bool Find(int targe, vector<vector<int>>array) {
		int m = array.size();
		int n = array[0].size();
		int rows = m - 1;
		int cols = 0;
		if (m == 0 && n == 0) {
			return false;
		}
		while (rows >= 0 && cols < n) {
			if (targe < array[rows][cols]) {
				rows--;
			}
			else if(targe>array[rows][cols]) {
				cols--;
			}
			else {
				return true;
			}
		}
		return false;
	}
int main() {
	vector<vector<int>>v;
	vector<int>array1;
	vector<int>array2;
	vector<int>array3;
	vector<int>array4;
	vector<int>array5;
	for (size_t i = 0;i < 5;i++) {
		array1.push_back(i);
	}
	for (size_t i = 5;i < 10;i++) {
		array2.push_back(i);
	}
	for (size_t i = 10;i < 15;i++) {
		array3.push_back(i);
	}
	for (size_t i = 15;i < 20;i++) {
		array4.push_back(i);
	}
	for (size_t i = 20;i < 25;i++) {
		array5.push_back(i);
	}
	v.push_back(array1);
	v.push_back(array2);
	v.push_back(array3);
	v.push_back(array4);
	v.push_back(array5);
	for (size_t i = 0;i < v.size();i++) {
		for (size_t j = 0;j < v[i].size();j++) {
			cout << v[i][j]<<" ";
		}
		cout << endl;
	}
	bool Ret = Find(30, v);
	if (Ret) {
		cout << "find" << endl;
	}
	else {
		cout << "not find" << endl;
	}
	return 0;
}
#endif

#if 0
class Solution {
public:
	void replaceSpace(char* str, int length) {
		if (str == nullptr || length <= 0) {
			return;
		}
		int oldlength = 0;
		int count = 0;
		int i = 0;
		while (str[i] != '\0') {
			if (str[i] == ' ') {
				count++;
			}
			oldlength++;
			i++;
		}
		int newlength = oldlength + 2 * count;
		int newindex = newlength;
		int oldindex = oldlength;
		while (oldindex >= 0 && newindex >= 0) {
			if (str[oldindex] == ' ') {
				str[newindex--] = '0';
				str[newindex--] = '2';
				str[newindex--] = '%';
			}
			else {
				str[newindex--] = str[oldindex];
			}
			oldindex--;
		}
	}
};
int main() {
	return 0;
}
#endif

#if 0
#include<vector>
#include<stack>
struct ListNode {
	int val;
	struct ListNode* next;
};
class Solution {
public:
	vector<int>printListFromTailToHead(ListNode* head) {
		vector<int>list;
		ListNode* cur = nullptr;
		cur = head;
		stack<int>s;
		while (cur != nullptr) {
			s.push(cur->val);
		}
		while (!s.empty()) {
			list.push_back(s.top());
			s.pop();
		}
		return list;
	}
};
int main() {
	return 0;
}
#endif

#if 0
#include<stack>
class solution {
public:
	void push(int node) {
		s1.push(node);
	}
	int pop() {
		int a;
		if (s2.empty()) {
			while (!s1.empty()) {
				a = s1.top();
				s2.push(a);
				s1.pop();
			}
		}
		a = s2.top();
		s2.pop();
		return a;
	}
private:
	stack<int>s1;
	stack<int>s2;
};
int main() {
	return 0;
}
#endif

#if 0
	int Fibonacci(int n) {
		if (n == 0) {
			return 0;
		}
		if (n <= 2) {
			return 1;
		}
		else {
			return Fibonacci(n - 1) + Fibonacci(n - 2);
		}
		
	}
int main() {
	cout << Fibonacci(10)<<" ";
	cout << endl;
	return 0;
}
#endif

#if 0
int jumpFloor(int number) {
	if (number == 0) {
		return -1;
	}
	else if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 2;
	}
	else {
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
}
int main() {
	int n;
	cin >> n;
	cout << jumpFloor(n);
	return 0;
}
#endif

#if 0
int jumpFloorII(int number) {
	if (number < 0) {
		return -1;
	}
	else if (number == 1) {
		return 1;
	}
	else {
		return 2 * jumpFloorII(number - 1);
	}
}
int main() {
	int n;
	cin >> n;
	cout << jumpFloorII(n);
	return 0;
}
#endif

#if 0
#include<vector>
void reOrderArray(vector<int>& array) {
	for (unsigned int i = 0;  i < array.size();i++) {
		for (unsigned int j = array.size() - 1;j > i;j--) {
			if (array[j - 1] % 2 == 0 && array[j] % 2 == 1) {
				swap(array[j - 1], array[j]);
			}
		}
	}
}
int main() {
	return 0;
}
#endif

#if 0
struct ListNode {
	int val;
	struct ListNode* next;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* pFast = pListHead;
	ListNode* pSlow = pListHead;
	int count = 0;
	while (pFast) {
		pFast = pFast->next;
		count++;
		if (k == count) {
			break;
		}
	}
	if (k != count) {
		return NULL;
	}
	while (pFast) {
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
int main() {
	return 0;
}
#endif

#if 0
struct ListNode {
	int val;
	struct ListNode* next;
};
ListNode* ReverseList(ListNode* pHead) {
	ListNode* cur = pHead;
	ListNode* pre = NULL;
	while (cur) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
int main() {
	return 0;
}
#endif

#if 0
struct ListNode {
	int val;
	struct ListNode* next;
};
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == nullptr) {
		return pHead2;
	}
	if (pHead2 == nullptr) {
		return pHead1;
	}
	ListNode* rHead = NULL;
	ListNode* cur = NULL;
	while (pHead1 != NULL && pHead2 != NULL) {
		if (pHead1->val < pHead2->val) {
			if (rHead == NULL){
				rHead = cur=pHead1;
			}
			else {
				cur->next = pHead1;
				cur = cur->next;
			}
			pHead1 = pHead1->next;
		}
		else {
			if (rHead == NULL) {
				rHead = cur = pHead2;
			}
			else {
				cur->next = pHead2;
				cur = cur->next;
			}
			pHead2 = pHead2->next;
		}
	}
	if (pHead1 == NULL) {
		cur->next = pHead2;
	}
	if (pHead2 == NULL) {
		cur->next = pHead1;
	}
	return rHead;
}
int main() {
	return 0;
}
#endif

#if 0
struct ListNode {
	int val;
	struct  ListNode* next;
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* pFast = pHead1;
	ListNode* pSlow = pHead2;
	int m = 0;
	int n = 0;
	while (pFast) {
		pFast = pFast->next;
		m++;
	}
	while (pSlow) {
		pSlow = pSlow->next;
		n++;
	}
	if (pFast != pSlow) {
		return NULL;
	}
	int size = m - n;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	if (m > n) {
		while (size--) {
			cur1 = cur1->next;
		}
	}
	else {
		while (size++) {
			cur2 = cur2->next;
		}
	}
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1 == cur2) {
			break;
		}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
}
int main() {
	return 0;
}
#endif

#if 0
#include<string>
int FirstNotRepeatingChar(string str) {
	int count[256] = { 0 };
	for (size_t i = 0;i < str.size();i++) {
		count[str[i]] += 1;
	}
	for (size_t i = 0;i < str.size();i++) {
		if (count[str[i]] == 1) {
			return i;
		}
	}
	return -1;
}
int main() {
	return 0;
}
#endif


