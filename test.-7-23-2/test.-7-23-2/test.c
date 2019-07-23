#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�������������ָ��ṹ��
typedef struct Node {
	char value;
	struct Node* left;
	struct Node* right;
}Node;
//����������
 Node* createNode(ch) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;
	return node;
}
 //���ٶ�����
 Node* Tree_Destroy(Node* root) {
	 free(root);
	 return NULL;
 }
 //����������
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
		 newleft = copyTree(root->left);//����������
	 }
	 if (root->right == NULL) {
		 newright = NULL;
	 }
	 else {
		 newright = copyTree(root->right);//����������
	 }
	 newroot = (Node*)malloc(sizeof(Node));//Ϊ�µĸ��������ڴ�
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
	 printf("��������%d",getNodecount(a));printf("\n");
	 printf("�������߶ȣ�%d", getheight(a));printf("\n");
	 printf("Ҷ�ӽ�㣺%d", getleafcount(a));printf("\n");
	 printf("��һ���������%d", getkleafcount(a, 1));printf("\n");
	 printf("�ڶ����������%d", getkleafcount(a, 2));printf("\n");
	 printf("�������������%d", getkleafcount(a, 3));printf("\n");
	 printf("���Ĳ��������%d", getkleafcount(a, 4));printf("\n");
	 copyTree(a);
	 system("pause");
 }
