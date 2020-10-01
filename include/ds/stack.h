#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
#include <iostream>

template <class T>
class Stack{
	private:
		LinkedList<T> stack;
	
	public:
		bool IsEmpty();
		bool IsFull();

		void Push(T data);
		void Clear();

		T Pop();
		const T& Top();

		Stack<T>& operator=(const Stack<T>& input);
		
};

template <class T>
bool Stack<T>::IsEmpty(){
	return this->stack.IsEmpty();
}

template <class T>
bool Stack<T>::IsFull(){
	return this->stack.IsFull();
}

template <class T>
void Stack<T>::Push(T data){
	if(this->stack.IsFull()){
		std::cerr << "WARNING: Stack is full. No space in heap"\
			<< std::endl;
		return;
	}
	this->stack.Insert(data, 0);
}

template <class T>
void Stack<T>::Clear(){
	this->stack.Clear();
}

template <class T>
T Stack<T>::Pop(){
	if (stack.IsEmpty()){
		std::cerr << "Stack is already empty. There is nothing to pop"\
			<< std::endl;
		throw "Stack Empty";
	}
	T data = stack.GetData(0);
	stack.RemoveFrom(0);
	return data;
}

template <class T>
const T& Stack<T>::Top(){
	if (stack.IsEmpty()){
		std::cerr << "Stack is already empty. There is nothing to pop"\
			<< std::endl;
		throw "Stack Empty";
	}
	return this->stack.GetData(0);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& input){
	this->stack = input.stack;
	return *this;
}

#endif // STACK_H
