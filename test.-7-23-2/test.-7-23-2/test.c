#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//定义二叉树左右指针结构体
typedef struct Node {
	char value;
	struct Node* left;
	struct Node* right;
}Node;
//创建二叉树
 Node* createNode(ch) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;
	return node;
}
 //销毁二叉树
 Node* Tree_Destroy(Node* root) {
	 free(root);
	 return NULL;
 }
 //拷贝二叉树
 Node* copyTree(Node* root) {
	 Node* newroot = NULL;
	 Node* newleft = NULL;
	 Node* newright = NULL;
	 if (root == NULL) {
		 return NULL;
	 }
	 if (root->left == NULL) {
		 newleft = NULL;
	 }
	 else {
		 newleft = copyTree(root->left);//拷贝左子树
	 }
	 if (root->right == NULL) {
		 newright = NULL;
	 }
	 else {
		 newright = copyTree(root->right);//拷贝右子树
	 }
	 newroot = (Node*)malloc(sizeof(Node));//为新的根结点分配内存
	 newroot->left = newleft;
	 newroot->right = newright;
	 newroot->value = root->value;
	 return newroot;
 }
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
	 postorderTraversal(root->left);
	 postorderTraversal(root->right);
	 printf("%c ", root->value);
 }
 int getNodecount(Node* root) {
	 if (root == NULL) {
		 return 0;
	 }
	 else {
		 int left = getNodecount(root->left);
		 int right = getNodecount(root->right);
		 return left + 1 + right;
	 }
 }
 int Max(int a, int b) {
	return  a >=b ? a : b;
 }
 int getheight(Node* root) {
	 if (root == NULL) {
		 return 0;
	 }
	 else {
		 int left = getheight(root->left);
		 int right = getheight(root->right);
		 return Max(left, right) + 1;
	 }
 }
 int getleafcount(Node* root) {
	 if (root == NULL) {
		 return 0;
	 }
	 else if (root->left==NULL&&root->right == NULL) {
		 return 1;
	 }
	 else {
		 return getleafcount(root->left) + getleafcount(root->right);
	 }
 }
 int getkleafcount(Node* root, int k) {
	 if (root == NULL) {
		 return 0;
	 }
	 else if (k == 1) {
		 return 1;
	 }
	 else {
		 return getkleafcount(root->left, k - 1) + getkleafcount(root->right, k - 1);
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
	 printf("结点个数：%d",getNodecount(a));printf("\n");
	 printf("二叉树高度：%d", getheight(a));printf("\n");
	 printf("叶子结点：%d", getleafcount(a));printf("\n");
	 printf("第一层结点个数：%d", getkleafcount(a, 1));printf("\n");
	 printf("第二层结点个数：%d", getkleafcount(a, 2));printf("\n");
	 printf("第三层结点个数：%d", getkleafcount(a, 3));printf("\n");
	 printf("第四层结点个数：%d", getkleafcount(a, 4));printf("\n");
	 copyTree(a);
	 system("pause");
 }
