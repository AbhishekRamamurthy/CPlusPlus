/*
 * Node.h
 *
 *  Created on: Mar 30, 2018
 *      Author: abhishek
 */

#ifndef INCLUDES_NODE_HPP_
#define INCLUDES_NODE_HPP_

#include <iostream>

template <class T>
class Node {
public:
	Node() {
		left = nullptr;
		right = nullptr;
		data =0;
	}
	Node(const T& data, Node<T>* right = nullptr, Node<T>* left = nullptr) {
		this->data = data;
		this->right = right;
		this->left = left;
	}
	virtual ~Node() {}
	Node<T>* left;
	Node<T>* right;
	T data;
};



#endif /* INCLUDES_NODE_HPP_ */
