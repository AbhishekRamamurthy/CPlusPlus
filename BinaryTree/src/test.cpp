/*
 * test.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: abhishek
 */

#include<iostream>
#include "../includes/BinaryTree.h"
#include "../includes/Node.hpp"

using namespace std;

int main() {

	BinaryTree<float> obj;
	obj.Insert(5);
	obj.Insert(4);
	obj.Insert(3);
	obj.Insert(2);
	Node<float>* head = obj.GetHead();
	obj.Display(head);
	cout << endl;
	cout << "Height of Tree Before Balance " << obj.Height() << endl;
	cout << "Level order Before Balance " <<endl;
	obj.LevelOrder();
	obj.BalanceTree();
	//obj.UpdateHead(head);
	obj.Display(head);
	cout << endl;
	cout << "Height of Tree After Balance " << obj.Height() << endl;
	obj.LevelOrder();
	cout << "Level order After Balance " <<endl;
	obj.Insert(1);
	obj.LevelOrder();
	head = obj.GetHead();
	head = obj.LeastCommonAncestor(head,1,5);
	cout << "Common Ancestor = " << head->data << endl;
	return 0;
}

