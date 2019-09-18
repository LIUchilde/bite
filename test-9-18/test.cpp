#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<vector>
//class Minstack {
//public:
//	void push(int x) {
//		_data.push(x);
//		if (_Mindata.empty() || x <= _Mindata.top()) {
//			_Mindata.push(x);
//		}
//	}
//	void pop() {
//		if (_Mindata.top() == _data.top()) {
//			_Mindata.pop();
//		}
//		_data.pop();
//	}
//	int top() {
//		return _data.top();
//	}
//	int gatMin() {
//		return _Mindata.top();
//	}
//private:
//	stack<int>_data;
//	stack<int>_Mindata;
//};
//int main() {
//	return 0;
//}


//class solution {
//public:
//	bool IsPopOrder(vector<int>pushV, vector<int>popV) {
//		if (pushV.size() != popV.size()) {
//			return false;
//		}
//		int index = 0;
//		int outdex = 0;
//		stack<int>s;
//		while (outdex < popV.size()) {
//			while (s.empty() || s.top() != popV[outdex]) {
//				if (index < pushV.size()) {
//					s.push(pushV[index++]);
//				}
//				else {
//
//					return false;
//				}
//			}
//			s.pop();
//		}
//		return true;
//	}
//};
//int main() {
//	return 0;
//}


//bool Find(int targe, vector<vector<int>>array) {
//	int m = array.size();
//	int n = array[0].size();
//	int rows = m - 1;
//	int cols = 0;
//	if (m == 0 && n == 0) {
//		return false;
//	}
//	while (rows >= 0 && cols < n) {
//		if (targe < array[rows][cols]) {
//			rows--;
//		}
//		else if (targe > array[rows][cols]) {
//			cols++;
//		}
//		else {
//			return true;
//		}
//	}
//	return false;
//}
//int main() {
//	vector<vector<int>>v;
//	vector<int>array1;
//	vector<int>array2;
//	vector<int>array3;
//	vector<int>array4;
//	vector<int>array5;
//	for (size_t i = 0;i < 5;i++) {
//		array1.push_back(i);
//	}
//	for (size_t i = 5;i < 10;i++) {
//		array2.push_back(i);
//	}
//	for (size_t i = 10;i < 15;i++) {
//		array3.push_back(i);
//	}
//	for (size_t i = 15;i < 20;i++) {
//		array4.push_back(i);
//	}
//	for (size_t i = 20;i < 25;i++) {
//		array5.push_back(i);
//	}
//	v.push_back(array1);
//	v.push_back(array2);
//	v.push_back(array3);
//	v.push_back(array4);
//	v.push_back(array5);
//	for (size_t i = 0;i < v.size();i++) {
//		for (size_t j = 0;j < v[i].size();j++) {
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
//	bool Ret = Find(80, v);
//	if (Ret) {
//		cout << "find" << endl;
//	}
//	else {
//		cout << "not find" << endl;
//	}
//	return 0;
//}


//int main() {
//	vector<vector<int>>array;
//	int m = 0;
//	int n = 0;
//	cout<< "请输入二维数组行数"<<endl;
//	cin >> m;
//	cout << "请输入二维数组列数" << endl;
//	cin >> n;
//	vector<int>v;
//	int temp = 0;
//	for (size_t i = 0;i < m;i++) {
//		v.clear();
//		for (size_t j = 0;j < n;j++) {
//			cin >> temp;
//			v.push_back(temp);
//		}
//		array.push_back(v);
//	}
//	for (size_t i = 0;i < m;i++) {
//		for (size_t j = 0;j < n;j++) {
//			cout << array[i][j] <<" ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int minNumberInRotateArray(vector<int> rotateArray) {
//	int size = rotateArray.size();
//	if (size == 0) {
//		return 0;
//	}
//	int left = 0;
//	int right = size - 1;
//	int mid = 0;
//	while (rotateArray[left] >= rotateArray[right]) {
//		if (left + 1 == right) {
//			mid = right;
//			break;
//		}
//		mid = left + (right - left) / 2;
//		if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
//			return MinOrder(rotateArray, left, right);
//		}
//		if (rotateArray[mid] >= rotateArray[left]) {
//			left = mid;
//		}
//		else {
//			right = mid;
//		}
//	}
//	return rotateArray[mid];
//}
//	int  MinOrder(vector<int> & num, int left, int right) {
//		int result = num[left];
//		for (int i = left + 1;i <= right;i++) {
//			if (num[i] < result) {
//				result = num[i];
//			}
//		}
//		return result;
//	}
//	int main() {
//		vector<int>RotateArray{ 4,5,6,1,2,3 };
//		cout << minNumberInRotateArray(RotateArray) << endl;
//		return 0;
//	}


////用栈实现队列
//
//class myQueue {
//public:
//	void push(int x){
//		s1.push(x);
//	}
//	int pop() {
//		int a;
//		if (s2.empty()) {
//			while (!s1.empty()) {
//				a = s1.top();
//				s2.push(a);
//				s1.pop();
//			}
//		}
//		a = s2.top();
//		s2.pop();
//		return a;
//	}
//	//返回队首元素
//	int peek() {
//		int a;
//		if (s2.empty()) {
//			while (!s1.empty()) {
//				a = s1.top();
//				s2.push(a);
//				s1.pop();
//			}
//		}
//		a = s2.top();
//		return a;
//	}
//	bool empty() {
//		return s1.empty() && s2.empty();
//	}
//private:
//	stack<int>s1;
//	stack<int>s2;
//};
//int main() {
//	return 0;
//}


//用队列实现栈
#include<queue>
class myStack {
public:
	void push(int x) {
		if (!q1.empty()) {
			q1.push(x);
		}
		else {
			q2.push(x);
		}
	}
	int pop() {
		int a=0;
		if (!q1.empty()) {
			while (q1.size()>1) {
				a = q1.front();
				q2.push(a);
				q1.pop();
			}
			a = q1.front();
			q1.pop();
		}
		else {
			while (q2.size() > 1) {
				a = q2.front();
				q1.push(a);
				q2.pop();
			}
			a = q2.front();
			q2.pop();
		}
		return a;
	}
private:
	queue<int>q1;
	queue<int>q2;
};
int main() {
	return 0;
}