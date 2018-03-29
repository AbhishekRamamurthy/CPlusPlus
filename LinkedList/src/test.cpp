/*
 * test.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: abhishek
 */

#include <iostream>
#include "../includes/LinkedList.hpp"
#include "../includes/Node.hpp"

using namespace std;

int main() {

	LinkedList<int> obj;
	LinkedList<int> obj2;
	Node<int>* list = obj.CreateNode(1);
	list = obj.Insert_End(list,2);
	list = obj.Insert_End(list,3);
	list = obj.Insert_End(list,4);
	list = obj.GetHead();
	obj.Display();
	Node<int>* list2 = obj2.CreateNode(1);
	list2 = obj2.Insert_End(list2,2);
	list2 = obj2.Insert_End(list2,3);
	list2 = obj2.Insert_End(list2,4);
	list2 = obj2.GetHead();
	obj2.Display();
	cout << "Data " << list->data << endl;
	obj.Display();
	obj.Insert_Position(5,2);
	obj.Display();
	obj.Insert_Position(5,1);
	obj.Display();
	obj.Insert_Begining(5);
	obj.Display();
	obj.Delete_Begining();
	obj.Display();
	obj.Delete_Position(2);
	obj.Display();
	obj.Remove_duplicates();
	obj.Remove_Duplicates_NoMap();
	obj.Display();
	Node<int>* head = obj.GetHead();
	head = obj.KthtoLastElement(head,2);
	cout << "Position "<< 2 << " to Last Element = ";
	for(;head != nullptr; head = head->next)
		cout << head->data << " ";
	cout << endl;
	list = obj.Insert_End(list,2);
	obj.Display();
	head = obj.GetHead();
	std::cout << "Before Partition list = ";
	obj.Display();
	head = obj.Partition_List(head,3);
	cout << "Partitioned about "<< 3 << " = ";
	for(;head != nullptr; head = head->next)
		cout << head->data << " ";
	cout << endl;
	obj.Display();

	head = obj.Sum(obj.GetHead(),obj2.GetHead());
	cout << " Sum = ";
	for(;head != nullptr; head = head->next)
		cout << head->data;
	return 0;
}

