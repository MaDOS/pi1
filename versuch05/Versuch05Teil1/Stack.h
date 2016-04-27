#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include "ListElem.h"

class Stack
{
	private:
		ListElem *tail;
		ListElem *head;
	public:
		Stack();
		void push(Student &data);
		void print();
		bool pop(Student &data);
		int b(int a);
};
#endif
