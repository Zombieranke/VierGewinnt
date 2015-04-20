/*
 * Stack.cpp
 *
 *  Created on: 19.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include "Stack.h"
#include <iostream>
#include <cstddef>

Stack::Stack()
{
	next = NULL;
	value = 0;
}


Stack::Stack( int value)
{
	next = NULL;
	this->value = value;
}


void Stack::push(Stack* &list, int value)
{
	Stack* newEntry = new Stack(value);
	newEntry->next = list;
	list = newEntry;
}


int Stack::pop(Stack* &list)
{
	Stack* temp = NULL;
	int returnValue = 0;

	if(list != NULL)
	{
		returnValue = list->value;
		temp = list->next;
		delete list;
		list = temp;
		return returnValue;
	}
	else
	{
		std::cerr << "Stack is already NULL" << std::endl;
		return -1337;
	}
}

void Stack::print(Stack* list)
{
	Stack* temp = list;

	while(temp!=NULL)
	{
		std::cout << " " << temp->value;
		temp = temp->next;
	}
}

Stack::~Stack()
{
	if(next!=NULL)
	{
		delete this->next;
	}
	next = NULL;
}
