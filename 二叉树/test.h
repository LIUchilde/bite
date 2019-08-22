#pragma once
typedef int TypeData;
typedef struct BinaryTreeNode {
	TypeData val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}Node;
void creatBinaryTree(Node **a);
void preOrder(Node* root);
