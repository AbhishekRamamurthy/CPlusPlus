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
		prev = nullptr;
		data = '\0';
	};

	Node(const T& data, Node<T>* next = nullptr,Node<T>* prev = nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	virtual ~Node() {};
	Node<T>* next;
	Node<T>* prev;
	T data;
};



#endif /* INCLUDES_NODE_HPP_ */
