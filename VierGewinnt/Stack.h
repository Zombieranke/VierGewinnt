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

	friend class ComputerPlayer;
public:
	void push(Stack* &list, int value);
	int pop(Stack* &list);
	void print(Stack* list);
	void empty();
	Stack();
	Stack(int value);
	~Stack();

private:
	int value;
	Stack* next;
};

#endif /* STACK_H_ */
