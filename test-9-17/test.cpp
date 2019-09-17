#define  _CRT_SECURE_NO_WARNINGS 1
#include<deque>
#include<iostream>
using namespace std;
//namespace bite {
//	template<class T,class Container=deque<T>>
//	class stack {
//	public:
//		stack()
//			:_con()
//		{}
//		void push(const T& data) {
//			_con.push_back(data);
//		}
//		void pop() {
//			_con.pop_back();
//		}
//		T& top() {
//			return _con.back();
//		}
//		const T& top()const {
//			return _con.back();
//		}
//		size_t size()const {
//			return _con.size();
//		}
//		bool empty()const {
//			return _con.empty();
//		}
//	private:
//		Container _con;
//	};
//}
//#include<vector>
//int main() {
//	bite::stack<int>s1;
//	bite::stack<int, vector<int>>s2;
//	s2.push(1);
//	s2.push(2);
//	s2.push(3);
//	s2.push(4);
//	cout << s2.top() << endl;
//	s2.pop();
//	cout << s2.top() << endl;
//	return 0;
//}

//#include<vector>
//#include<stack>
//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//	if (pushV.size() != popV.size()) {
//		return false;
//	}
//	size_t inidx = 0;
//	size_t outidx = 0;
//	stack<int>s;
//	while (outidx < popV.size()) {
//		while (s.empty() || s.top() != popV[outidx]) {
//			if (inidx < pushV.size()) {
//				s.push(pushV[inidx++]);
//			}
//			else {
//				return false;
//			}
//		}
//		s.pop();
//		outidx++;
//	}
//	return true;
//}
//int main() {
//	return 0;
//}

//#include<vector>
//#include<stack>
//int evalRPN(vector<string>& tokens) {
//	stack<int>s;
//	for (size_t i = 0;i < tokens.size();++i) {
//		string& str = tokens[i];
//		if (!(str == "+" || str == "-" || str == "*" || str == "/")) {
//			s.push(atoi(str.c_str()));
//		}
//		else {
//			int right = s.top();
//			s.pop();
//			int left = s.top();
//			s.pop();
//			switch (str[0]) {
//			case '+':
//				s.push(left + right);
//				break;
//			case '-':
//				s.push(left - right);
//				break;
//			case '*':
//				s.push(left*right);
//				break;
//			case '/':
//				s.push(left / right);
//				break;
//			}
//		}
//	}
//	return s.top();
//}
//int main() {
//	return 0;
//}

//用队列实现栈

//#include<queue>
//class stack {
//public:
//	void push(int x) {
//		if (q1.empty()) {
//			q1.push(x);
//		}
//		else {
//			q2.push(x);
//		}
//	}
//	int pop() {
//		int ret = 0;
//		if (!q1.empty()) {
//			while (q1.size() > 1) {
//				q2.push(q1.front());
//				q1.pop();
//			}
//			ret = q1.front();
//			q1.pop();
//		}
//		else {
//			while(q2.size() > 1) {
//				q1.push(q2.front());
//				q2.pop();
//			}
//			ret = q2.front();
//			q2.pop();
//		}
//		return ret;
//	}
//	int top() {
//		if (!q1.empty()) {
//			return q1.back();
//		}
//		else {
//			return q2.back();
//		}
//	}
//	bool empty() {
//		return q1.empty() && q2.empty();
//	}
//private:
//	queue<int>q1;
//	queue<int>q2;
//};
//int main() {
//	return 0;
//}

#include<vector>
#include<queue>
 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>vRet;
	if (nullptr == root) {
		return vRet;
	}
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		vector<int>level;
		size_t count = q.size();
		for (size_t i = 0;i < count;i++) {
			TreeNode* pCur = q.front();
			level.push_back(pCur->val);
			q.pop();
			if (pCur->left) {
				q.push(pCur->left);
			}
			if (pCur->right) {
				q.push(pCur->right);
			}
		}
		vRet.push_back(level);
	}
	return vRet;
}
int main() {
	return 0;
}