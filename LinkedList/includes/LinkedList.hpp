/*
 * LinkedList.h
 *
 *  Created on: Mar 26, 2018
 *      Author: abhishek
 */

#ifndef INCLUDES_LINKEDLIST_HPP_
#define INCLUDES_LINKEDLIST_HPP_

#include "Node.hpp"
#include <bits/stdc++.h>

template<class T>
class LinkedList {
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	};

	virtual ~LinkedList() {}

	Node<T>* CreateNode(const T& data) {

		Node<T>* temp = new Node<T>(data);
		if(head == nullptr){
			head = temp;
			tail = temp;
			temp = nullptr;
		} else {
			tail->next = temp;
			tail = temp;
		}
		return head;
	}

	Node<T>* GetHead() {
		return head;
	}

	Node<T>* GetTail() {
		return tail;
	}

	Node<T>* Insert_End(Node<T>* node,const T& data ) {

		Node<T>* temp = new Node<T>(data);
		node->next = temp;
		node = node->next;
		tail = node;
		temp = nullptr;
		return tail;
	}

	void Insert_Begining(const T& data) {
		Node<T>* temp = new Node<T>(data);
		temp->next = head;
		head = temp;
	}

	void Insert_Position(const T& data, int pos) {
		Node<T>* temp = new Node<T>(data);
		Node<T>* temp_ptr = head;
		Node<T>* temp_holder = nullptr;
		for(int i=0; i<pos-1 ;i++)
			temp_ptr = temp_ptr->next;
		temp_holder = temp_ptr->next;
		temp_ptr->next = temp;
		temp->next = temp_holder;
	}

	void Delete_Begining() {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}

	void Delete_Position(int pos) {
		Node<T>* temp = head;
		for(int i=0; i < pos-1; i++)
			temp = temp->next;
		temp->next = temp->next->next;
		delete temp->next;
	}

	/*
	 * remove duplicates from a linkedlist
	 * Sorted/Unsorted
	 */
	void Remove_duplicates() {
		Node<T>* temp = head;
		Node<T>* temp_ptr = nullptr;
		std::map<T,int> count;

		for(;temp!= nullptr; temp = temp->next) {

			if(temp_ptr == nullptr) {
				temp_ptr = temp;
			} else {
				if(!count[temp->data]) {
					count[temp->data]++;
					temp_ptr->next = temp;
					temp_ptr = temp_ptr->next;
				}
			}
		}
		tail = temp_ptr;
		temp_ptr = nullptr;
		temp = nullptr;
	}

	void Remove_Duplicates_NoMap(){
		Node<T>* temp = head;

		while(temp != nullptr) {
			Node<T>* temp_ptr = temp;
			while(temp_ptr->next != nullptr) {

				if(temp_ptr->next->data == temp->data)
						temp_ptr->next = temp_ptr->next->next;
				else temp_ptr = temp_ptr->next;
			}
			temp = temp->next;
		}
	}

	/*
	 * print Kth to Last element of a linked list
	 */
	Node<T>* KthtoLastElement(Node<T>* head, int pos) {

		if(head == nullptr)
			return 0;

		Node<T>* temp = head;
		Node<T>* temp_ptr =head;

		for(int i=0; i<pos;i++)
			temp = temp->next;

		for(;temp!= nullptr;temp = temp->next)
			temp_ptr = temp_ptr->next;

		return head = temp_ptr;
	}

	/*
	 * partition the given linked list about a value
	 */

	Node<T>* Partition_List(Node<T>* head, const T& val) {

		Node<T>* temp = head;
		Node<T>* temp_ptr = head;

		while(head != nullptr) {

			Node<T>* next = head->next;
			if(head->data < val) {
				head->next = temp;
				temp = head;
			} else {
				temp_ptr->next = head;
				temp_ptr = head;
			}
			head = next;
		}
		temp_ptr->next = nullptr;
		return head = temp;
	}
	/*
	 * Sum the values in two linked lists
	 */

	Node<T>* Sum(Node<T>* first, Node<T>* second) {

		Node<T>* result = nullptr;
		Node<T>* temp;
		Node<T>* prev = new Node<T>();
		int sum =0, carry=0;

		while (first != nullptr || second != nullptr)
		{
			sum = carry + (first? first->data: 0) + (second? second->data: 0);

			carry = (sum >= 10)? 1 : 0;

			sum = sum % 10;

			temp = new Node<T>(sum);
			if(result == nullptr)
				result = temp;
			else
				prev->next = temp;

			prev  = temp;
			if (first) first = first->next;
			if (second) second = second->next;
		}

		if (carry > 0)
			temp->next = new Node<T>(carry);

		return result;
	}

	void Display() {
		Node<T>* temp = head;

		for(;temp != nullptr; temp = temp->next)
			std::cout<< temp->data << " ";
		std::cout << std::endl;
	}

private:
	Node<T>* head;
	Node<T>* tail;
};


#endif /* INCLUDES_LINKEDLIST_HPP_ */
