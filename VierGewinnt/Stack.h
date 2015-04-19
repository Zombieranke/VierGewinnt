/*
 * Stack.h
 *
 *  Created on: 19.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#ifndef STACK_H_
#define STACK_H_

class Stack {
public:
	void push(Stack* list, int value);
	int pop(Stack* list);
	Stack();
	Stack(int value);
	~Stack();

private:
	int value;
	Stack* next;
};

#endif /* STACK_H_ */
