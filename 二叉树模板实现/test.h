#pragma once
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
template<class T>
struct BinaryTreeNode {
	T val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
template<class T>
class BinaryTree {
	typedef BinaryTreeNode<T>Node;
public:
	BinaryTree();//构造函数
	~BinaryTree();//析构函数
public:
	Node* BinaryTreecreat(T* a);
	void perOrder(Node* root);
	void inorder(Node* root);
	void postOrder(Node* root);
	void Destory(Node* root);
private:
	Node* root;
};
template<class T>
BinaryTree<T>::BinaryTree() {
	root = BinaryTreecreat(a);
}
template<class T>
BinaryTree<T>::~BinaryTree() {
	Destory(root);
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::BinaryTreecreat(T* a) {
	static n = 0;
	if (a[n] == '#') {
		n++;
		return NULL;
	}
	Node* cur = new Node[];
	cur->val = a[n];
	n++;
	cur->left = BinaryTreecreat(a);
	cur->right = BinaryTreecreat(a);
	return cur;
}
template<class T>
void BinaryTree<T>::Destory(Node* root) {
	Node* temp;
	if (temp==nullptr) {
		return;
	}
	Destory(temp->left);
	Destory(temp->right);
	delete(temp);
	temp = nullptr;
}
template<class T>
void BinaryTree<T>::perOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->val << endl;
	perOrder(root->left);
	perOrder(root->right);
}





