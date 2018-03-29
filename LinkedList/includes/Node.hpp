/*
 * Node.h
 *
 *  Created on: Mar 26, 2018
 *      Author: abhishek
 */

#ifndef INCLUDES_NODE_HPP_
#define INCLUDES_NODE_HPP_

#include <iostream>

template <class T>
class Node {
public:
	Node(){
		next = nullptr;
		data = '\0';
	};

	Node(const T& data, Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
	}
	virtual ~Node() {};
	Node<T>* next;
	T data;
};



#endif /* INCLUDES_NODE_HPP_ */
