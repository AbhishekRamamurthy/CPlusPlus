/*
 * BinaryTree.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: abhishek
 */

#include "../includes/BinaryTree.h"

template class BinaryTree<int>;
template class BinaryTree<char>;
template class BinaryTree<float>;

template <class T>
BinaryTree<T>::BinaryTree():root(nullptr) {}

template <class T>
BinaryTree<T>::~BinaryTree(){}

template <class T>
Node<T>* BinaryTree<T>::CreateNode(const T& data){

	Node<T>* temp = new Node<T>(data);
	return temp;
}

template <class T>
void BinaryTree<T>::Insert(const T& data, Node<T>* root) {

	if(data < root->data) {
		if (root->left != nullptr)
			Insert(data,root->left);
		else {
			root->left = new Node<T>(data);
		}
	} else {

		if (root->right != nullptr)
			Insert(data,root->right);
		else {
			root->right = new Node<T>(data);
		}
	}
}

template <class T>
void BinaryTree<T>::Insert(const T& data) {

	if(root == nullptr)
		root = CreateNode(data);
	else {
		Insert(data,root);
	}
}

template <class T>
Node<T>* BinaryTree<T>::GetHead(){

	return root;
}

template <class T>
void BinaryTree<T>::UpdateHead(Node<T>* root){

	this->root = root;
}

template <class T>
void BinaryTree<T>::InOrder(Node<T>* root,std::vector<Node<T>*>& nodes) {

	if(root == nullptr)
		return ;

	InOrder(root->left,nodes);
	nodes.push_back(root);
	InOrder(root->right,nodes);
}

template <class T>
void BinaryTree<T>::BalanceTree() {
	std::vector<Node<T>*> nodes;
	InOrder(root,nodes);
	int size = nodes.size();
	std::cout << "Size = " << size << std::endl;
	this->root =BalanceTree(nodes,0,size-1);
}

template <class T>
Node<T>* BinaryTree<T>::BalanceTree(std::vector<Node<T>*> nodes, int start,int end) {

	if(start > end)
		return nullptr;

	int mid = (start + end)/2;
	Node<T>* root = nodes[mid];
	root->left = BalanceTree(nodes,start,mid-1);
	root->right = BalanceTree(nodes,mid+1,end);
	return root;
}

template <class T>
unsigned int BinaryTree<T>::Height(Node<T>* root) {

	if (root == nullptr)
		return 0;
	unsigned int left = Height(root->left);
	unsigned int right = Height(root->right);

	return left > right ? left+1: right+1;
}

template <class T>
unsigned int BinaryTree<T>::Height() {

	return Height(root);
}

template <class T>
void BinaryTree<T>::LevelOrder() {
	std::queue<Node<T>*> n_queue;

	n_queue.push(root);
	while(1) {
		unsigned int node_count = n_queue.size();

		if(node_count == 0)
			break;

		while(node_count > 0) {
			Node<T>* temp = n_queue.front();
			std::cout << temp->data << " ";
			n_queue.pop();
			if(temp->left != nullptr)
				n_queue.push(temp->left);
			if(temp->right != nullptr)
				n_queue.push(temp->right);
			node_count--;
		}
		std::cout << std::endl;
	}
}

template <class T>
Node<T>* BinaryTree<T>::LeastCommonAncestor(Node<T>* node, const T& x, const T& y) {

	if(node == nullptr)
		return nullptr;

	if(node->data == x || node->data == y)
		return node;

	Node<T>* left = LeastCommonAncestor(node->left,x,y);
	Node<T>* right = LeastCommonAncestor(node->right,x,y);

	if(left && right)
		return node;

	return left != nullptr ? left : right;
}

template <class T>
void BinaryTree<T>::Display(Node<T>* root) {

	if(root == nullptr)
		return;

	Display(root->left);
	std::cout << root->data << " ";
	Display(root->right);
}
