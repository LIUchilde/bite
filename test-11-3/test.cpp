#include<iostream>
using namespace std;
#if 0
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr) {
			return false;
		}
		if (pRoot1->val == pRoot2->val && isSubtree(pRoot1,pRoot2)) {
			return true;
		}
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	bool isSubtree(TreeNode* p1, TreeNode* p2) {
		if (p2 == nullptr) {
			return true;
		}
		if (p1 == nullptr) {
			return false;
		}
		if (p1->val == p2->val) {
			return isSubtree(p1->left, p2->left) && isSubtree(p1->right, p2->right);
		}
		return false;
	}
};
int main() {
	return 0;
}
#endif

#if 0
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	void Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) {
			return;
		}
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};
int main() {
	return 0;
}
#endif

#if 0
#include<vector>
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int>result;
	int row = matrix.size();
	int col = matrix[0].size();
	if (row == 0 || col == 0) {
		return result;
	}
	int left = 0, right = col - 1, top = 0, bottom = row - 1;
	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; i++) {
			result.push_back(matrix[top][i]);
		}
		for (int i = top+1; i <= bottom; i++) {
			result.push_back(matrix[i][right]);
		}
		if (top != bottom) {
			for (int i = right - 1; i >= left; i--) {
				result.push_back(matrix[bottom][i]);
			}
		}
		if (left != right) {
			for (int i = bottom - 1; i > top; i--) {
				result.push_back(matrix[i][left]);
			}
		}
		left++, right--, top++, bottom--;
	}
	return result;
}
int main() {
	return 0;
}
#endif

#if 0
#include<vector>
#include<queue>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int>v;
	if (root == nullptr) {
		return v;
	}
	queue<TreeNode*>q;
	TreeNode* pCur = root;
	q.push(pCur);
	while (!q.empty()) {
		pCur = q.front();
		v.push_back(pCur->val);
		if (pCur->left) {
			q.push(pCur->left);
		}
		if (pCur->right) {
			q.push(pCur->right);
		}
		q.pop();
	}
	return v;
}
int main() {
	return 0;
}
#endif

int main() {
	return 0;
}
