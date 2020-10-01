#include <iostream>
#include <ostream>
#include <vector>
#include "include/ds/linkedlist.h"
#include "include/ds/stack.h"
#include "include/ds/queue.h"

int main() {
	LinkedList<int> linkedlist;
	linkedlist.Append(3);
	linkedlist.Append(5);
	linkedlist.Insert(7, 1);
	linkedlist.Insert(8, 0);
	linkedlist.Insert(4, 10);
	linkedlist.Insert(6, 2);
	linkedlist.Display("\n");
	std:: cout << "GET INDEX 4\n";
	std:: cout << linkedlist.GetIndex(4) << std::endl;
	std:: cout << "GET DATA 1\n";
	std:: cout << linkedlist.GetData(1) << std::endl;
	linkedlist.Display();
	linkedlist.Remove(6);
	linkedlist.RemoveFrom(2);
	linkedlist.Display();
	linkedlist.Pop();
	linkedlist.Clear();
	linkedlist.Append(3);
	linkedlist.Append(5);
	linkedlist.Append(4);
	linkedlist.Insert(6, 2);
	linkedlist.Insert(7, 1);
	linkedlist.Insert(9, 0);
	linkedlist.Display();
	linkedlist.Reverse();
	linkedlist.Display();

	LinkedList<int> list2;
	list2.Append(1);
	list2.Append(3);
	list2.Append(5);
	list2.Append(9);
	list2.Display();
	std::cout << "IS SORTED list2 = " << list2.IsSorted() << std::endl;
	std::cout << "IS SORTED linkedlist = " << linkedlist.IsSorted() << std::endl;
	linkedlist.Display();

	Stack<int> stk;
	std::cout <<  "Stack Empty = " << stk.IsEmpty() << std::endl;
	stk.Push(20);
	stk.Push(7);
	stk.Push(11);
	stk.Push(9);
	stk.Push(1);
	stk.Push(13);
	stk.Push(16);
	stk.Push(22);
	stk.Push(21);
	std::cout <<  "Stack Not Empty = " << stk.IsEmpty() << std::endl;
	Stack<int> stk2;
	stk2 = stk;
	while(!stk.IsEmpty()){
		std::cout << stk.Pop() << " ";
	}
	std::cout << std::endl;
	while(!stk2.IsEmpty()){
		std::cout << stk2.Pop() << " ";
	}
	std::cout << std::endl;

	stk.Push(31);
	stk.Push(33);
	stk.Clear();

	Queue<int> q;
	q.Enqueue(3);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(7);
	q.Enqueue(8);
	q.Enqueue(0);
	q.Enqueue(6);
	q.Enqueue(1);
	q.Enqueue(4);
	while(!q.IsEmpty()){
		std::cout << q.Dequeue() << " ";
	}
	std::cout << std::endl;

	q.Enqueue(0);
	q.Enqueue(6);
	q.Enqueue(1);
	q.Enqueue(4);
	Queue<int> q2;
	q2 = q;
	while(!q.IsEmpty()){
		std::cout << q.Dequeue() << " ";
	}
	std::cout << std::endl;
	std::cout << q2.Front() << std::endl;
	q2.Clear();
	return 0;
}
