#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <iostream>

template <class T>
class Queue{
	private:
		LinkedList<T> queue;
	
	public:
		bool IsEmpty() const;
		bool IsFull() const;

		void Enqueue(T data);
		void Clear();

		T Dequeue();
		const T& Front() const;

		Queue<T>& operator=(const Queue<T>& input);
		
};

template <class T>
bool Queue<T>::IsEmpty() const{
	return this->queue.IsEmpty();
}

template <class T>
bool Queue<T>::IsFull() const {
	return this->queue.IsFull();
}

template <class T>
void Queue<T>::Enqueue(T data){
	if(this->queue.IsFull()){
		std::cerr << "WARNING: Queue is full. No space in heap"\
			<< std::endl;
		return;
	}
	this->queue.Append(data);
}

template <class T>
void Queue<T>::Clear(){
	this->queue.Clear();
}

template <class T>
T Queue<T>::Dequeue(){
	if (queue.IsEmpty()){
		std::cerr << "Queue is already empty. There is nothing to pop"\
			<< std::endl;
		throw "Queue Empty";
	}
	T data = queue.GetData(0);
	queue.RemoveFrom(0);
	return data;
}

template <class T>
const T& Queue<T>::Front() const {
	if (queue.IsEmpty()){
		std::cerr << "Queue is already empty. There is nothing to pop"\
			<< std::endl;
		throw "Queue Empty";
	}
	return this->queue.GetData(0);
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& input){
	if (this != &input){
		this->queue = input.queue;
	}
	return *this;
}

#endif // QUEUE_H
