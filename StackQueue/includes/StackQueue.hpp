/*
 * StackQueue.hpp
 *
 *  Created on: Mar 28, 2018
 *      Author: abhishek
 */

#ifndef INCLUDES_STACKQUEUE_HPP_
#define INCLUDES_STACKQUEUE_HPP_

#include "Node.hpp"
#include <assert.h>

namespace SQ {
template <class T>
class Stack {
public:
	Stack(){
		next = nullptr;
		data = 0;
	};

	Node<T>* CreateNode(T data) {

		Node<T>* temp = new Node<T>(data);
		return temp;
	}

	void Push(T data) {

		if(next == nullptr) {
			next = CreateNode(data);
		}
		else {
			Node<T>* temp = CreateNode(data);
			temp->prev = next;
			next->next = temp;
			next = next->next;
			temp = nullptr;
		}
	}

	void Pop() {

		if (next == nullptr)
			return;
		Node<T>* temp= next;
		next = next->prev;
		delete temp;
	}

	T Top() {
		assert(next);
		return next->data;
	}
	bool IsEmpty() {
		if (next == nullptr) return true;
		else return false;
	}

	virtual ~Stack() {};

private:
	Node<T>* next;
	T data;

};

template <class T>
class Queue {

public:
	Queue(){
		next = nullptr;
		data = 0;
	};

	Node<T>* CreateNode(T data) {

			Node<T>* temp = new Node<T>(data);
			return temp;
		}

		void Push(T data) {

			if(next == nullptr) {
				next = CreateNode(data);
			}
			else {
				Node<T>* temp = CreateNode(data);
				next->next = temp;
				temp = nullptr;
			}
		}

		void Pop() {

			if (next == nullptr)
				return;
			Node<T>* temp= next;
			next = next->next;
			delete temp;
		}

		T Front() {
			assert(next);
			return next->data;
		}

		bool IsEmpty() {
			if (next == nullptr) return true;
			else return false;
		}

	virtual ~Queue(){};
private:
	Node<T>* next;
	T data;
};
};



#endif /* INCLUDES_STACKQUEUE_HPP_ */
