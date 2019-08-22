#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include"test.h"
int main() {
	Node* root;
	char a[] = "ABD#GI##J###CE#HK###F##";
	root=creatBinaryTree(a);
	preOrder(root);
	printf("\n");
	preOrderNor(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	inOrderNor(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	system("pause");
	return 0;
}