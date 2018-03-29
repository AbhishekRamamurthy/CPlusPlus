/*
 * test.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: abhishek
 */


#include <iostream>
#include "../includes/StackQueue.hpp"
using namespace std;

int main() {

	SQ::Stack<int> sObj;
	sObj.Push(1);
	sObj.Push(2);
	int data = sObj.Top();
	cout << "Stack Top = " << data << endl;
	cout << "Is Empty Stack " << sObj.IsEmpty() << endl;
	sObj.Pop();
	data = sObj.Top();
	cout << "Stack Top = " << data << endl;
	sObj.Pop();
	//for assertion
	//data = obj.Top();
	//cout << "DATA = " << data << endl;
	cout << "Is Empty Stack " << sObj.IsEmpty() << endl;

	SQ::Queue<int> qObj;
	qObj.Push(1);
	qObj.Push(2);
	data = qObj.Front();
	cout << "Queue Top = " << data << endl;
	cout << "Is Empty Queue " << qObj.IsEmpty() << endl;
	qObj.Pop();
	data = qObj.Front();
	cout << "Queue Top = " << data << endl;
	qObj.Pop();
	cout << "Is Empty Queue " << qObj.IsEmpty() << endl;
	//for assertion
	//data = qObj.Front();
	//cout << "Queue Top = " << data << endl;
	return 0;
}

