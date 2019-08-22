#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<stdio.h>
int main() {
	Node *pNode=NULL;
	creatBinaryTree(&pNode);
	preOrder(pNode);

}