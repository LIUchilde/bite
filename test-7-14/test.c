#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node {
	char value;
	struct Node* left;
	struct Node* right;
}Node;
void preorderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		printf("%c ", root->value);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void inorderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		inorderTraversal(root->left);
		printf("%c ", root->value);
		inorderTraversal(root->right);
	}
}
void postorderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}
	else {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%c ", root->value);
		}
	}
Node* createNode(ch) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;
	return node;
}
int getNodecount(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left=getNodecount(root->left);
	int right=getNodecount(root->right);
	return left + 1 + right;
}
int myMax(int a, int b) {
	return a >= b ? a : b;
}
int getheight(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = getheight(root->left);
	int right = getheight(root->right);
	return myMax(left, right) + 1;
}
int getleafcount(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left==NULL&&root->right==NULL) {
		return 1;
	}
	else {
		return getleafcount(root->left) + getleafcount(root->right);
	}
}
int getklefecount(Node* root, int k) {
	if (root == NULL) {
		return 0;
	}
	else if (k == 1) {
		return 1;
	}
	else {
		return getklefecount(root->left, k - 1) + getklefecount(root->right, k - 1);
	}
}
Node* find(Node* root, char v) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == v) {
		return root;
	}
	Node* left = find(root->left, v);
		if (left != NULL) {
			return left;
	}
		Node* right = find(root->right, v);
	 if (right != NULL) {
		return right;
	}
	 else {
		 return NULL;
	 }
}
int main() {
	Node* a = createNode('A');
	Node* b = createNode('B');
	Node* c = createNode('C');
	Node* d = createNode('D');
	Node* e = createNode('E');
	Node* f = createNode('F');
	Node* g = createNode('G');
	Node* h = createNode('H');
	a->left = b;a->right = c;
	b->left = d;b->right = e;
	c->left = f;c->right = g;
	d->left = NULL;d->right = NULL;
	e->left = NULL;e->right = h;
	preorderTraversal(a);printf("\n");
	inorderTraversal(a);printf("\n");
	postorderTraversal(a);printf("\n");
	printf("结点个数：%d", getNodecount(a));printf("\n");
	printf("高度：%d", getheight(a));printf("\n");
	printf("叶子结点个数：%d", getleafcount(a));printf("\n");
	printf("第一层结点个数：%d", getklefecount(a, 1));printf("\n");
	printf("第二层结点个数：%d", getklefecount(a, 2));printf("\n");
	printf("第三层结点个数：%d", getklefecount(a, 3));printf("\n");
	printf("第四层结点个数：%d", getklefecount(a, 4));printf("\n");
}
