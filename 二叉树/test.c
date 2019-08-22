#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"test.h"
void creatBinaryTree(Node** a) {
	TypeData ch;
	int n = scanf("%d", &ch);
	if (ch == '#') {
		*a = NULL;
	}
	else {
		*a = (Node*)malloc(sizeof(Node));
		if (!(*a)) {
			(*a)->val = ch;
			printf("%c ", ch);
		}
		creatBinaryTree(&(*a)->left);
		creatBinaryTree(&(*a)->right);
	}
} 
void preOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}