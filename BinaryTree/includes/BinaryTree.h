/*
 * BinaryTree.h
 *
 *  Created on: Mar 30, 2018
 *      Author: abhishek
 */

#ifndef INCLUDES_BINARYTREE_H_
#define INCLUDES_BINARYTREE_H_

#include "Node.hpp"
#include <vector>
#include <queue>

template<class T>
class BinaryTree {

public:
	BinaryTree();
	Node<T>* CreateNode(const T&);
	void Insert(const T&);
	void Display(Node<T>* root);
	Node<T>* GetHead();
	void UpdateHead(Node<T>*);
	void InOrder(Node<T>*,std::vector<Node<T>*>&);
	void LevelOrder();
	unsigned int Height();
	unsigned int Height(Node<T>*);
	void BalanceTree();
	Node<T>* BalanceTree(std::vector<Node<T>*>, int,int);
	Node<T>* LeastCommonAncestor(Node<T>*,const T&, const T&);
	virtual ~BinaryTree();
private:
	void Insert(const T&, Node<T>*);
	Node<T>* root;
};

#endif /* INCLUDES_BINARYTREE_H_ */
