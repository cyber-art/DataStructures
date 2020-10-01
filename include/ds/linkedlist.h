//
// Created by cyber_art on 25.09.2020.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template<class T>
class LinkedList{
    public:
        class Node{
            private:
                T data;
            public:
                Node* next;
		
		Node() : next{nullptr}{}
		Node(T data): data{data}, next{nullptr}{}
		Node(T data, Node* next): data{data}, next{next}{}

                const T& GetData() const;

                void SetData(T data)const;
        };

	LinkedList(): head{nullptr}, tail{nullptr}, length{0}{}
	LinkedList(T data){
		Node* temp;
		temp = new Node(data);
		this->head = temp;
		this->tail = temp;
		this->length = 1;
	}
	LinkedList(T* data){
		Node* current;
		Node* temp;
		int index = 1;
		current = new Node(*data);
		this->head = current;
		this->length = 1;
		while((*data) != '\0'){
			temp = new Node(*(data+index));
			current->next = temp;
			current = temp;
			index += 1;
			this->length += 1;
		}
		this->tail = current;
	}
	LinkedList(const LinkedList &list){
		this->head = list.head;
		this->length = list.length;
		this->tail = list.tail;
	}

	bool IsEmpty() const;
	bool IsFull() const;
	bool IsSorted(bool ascending = true) const;

	void Insert(T data, int index);
	void Append(T data);
	void Remove(T data);
	void RemoveFrom(int index);
	void Display(std::string seperator = " ") const;
	void Pop();
	void Clear();
	void Reverse();
	void Concat(const LinkedList<T>& input);
	void Concat(LinkedList<T>* input);

	const T& GetData(int index) const;

	int GetIndex(T data) const;

	LinkedList<T>& operator=(const LinkedList<T>& input);
	
	~LinkedList(){
		if (this->IsEmpty())
			return;
		this->Clear();
	}

    private:
        Node* head;
        Node* tail;
	Node* FindPrevious(int index) const;
	
	int length;
};

template <class T>
const T& LinkedList<T>::Node::GetData() const {return this->data;}

template <class T>
void LinkedList<T>::Node::SetData(T data) const {this->data = data;}

template <class T>
bool LinkedList<T>::IsEmpty() const {
	return (this->length == 0) ? true : false;
}

template <class T>
bool LinkedList<T>::IsFull() const {
	Node* temp = new Node();
	if (temp == NULL || temp == nullptr)
		return true;
	delete temp;
	return false;
}

template <class T>
bool LinkedList<T>::IsSorted(bool ascending) const {
	if (this->IsEmpty()){
		return true;
	}
	Node* temp = this->head;
	while (temp != this->tail){
		if (ascending && (temp->GetData() > temp->next->GetData()))
			return false;
		else if (!ascending && (temp->GetData() < temp->next->GetData()))
			return false;
		temp = temp->next;
	}
	return true;
}

template <class T>
void LinkedList<T>::Insert(T data, int index){
	if (index == this->length)
		this->Append(data);
	else if (index > this->length){
		std::cerr << "WARNING: Index out of range. However, the "\
			<< "given item is added at the end of the list"\
			<< std::endl;
		this->Append(data);
		return;
	}
	else if (index < 0){
		std::cerr << "Index out of range (must be non-negative)" << \
			std::endl;
		return;
	}
	else if (this->IsFull()){
		std::cerr << "WARNING: List is full. There is no space"\
			<< std::endl;
		return;
	}
	else{
		if (index == 0){
			Node* add = new Node(data);
			add->next = this->head;
			this->head = add;
			this->length += 1;
			return;
		}
		Node* current = this->FindPrevious(index);
		Node* add = new Node(data);
		add->next = current->next;
		current->next = add;
		this->length += 1;
	}
}

template <class T>
void LinkedList<T>::Append(T data){
	if (this->IsFull()){
		std::cerr << "WARNING: List is full. There is no space"\
			<< std::endl;
		return;
	}
	Node* temp = new Node(data);
	if (this->head == nullptr){
		this->head = temp;
		this->tail = temp;
		this->length += 1;
		return;
	}
	this->tail->next = temp;
	this->tail = temp;	
	this->length += 1;
}

template <class T>
void LinkedList<T>::Remove(T data){
	if (this->IsEmpty()){
		std::cerr << "WARNING: List is already empty" << std::endl;
		return;
	}
	Node* curr = this->head;
	Node* prev = nullptr;
	while(curr->next != nullptr){
		if(curr->GetData() == data){
			if (curr == this->head)
				this->head = curr->next;
			if (curr == this->tail)
				this->tail = prev;
			if (prev != nullptr){
				prev->next = curr->next;
			}
			delete curr;
			this->length -= 1;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	std::cerr << "WARNING: Given data is not found in the list" << std::endl;
}

template <class T>
void LinkedList<T>::RemoveFrom(int index){
	if (index < 0){
		std::cerr << "WARNING: Index out of range (must be non"\
			<<"-negative)" << std::endl;
		return;
	}
	else if (index > this->length){
		std::cerr << "WARNING: Index out of range. " <<\
			"The last item will be deleted" << std::endl;
		this->RemoveFrom(this->length);
	}
	int i = 0;
	Node* curr;
	Node* prev = this->FindPrevious(index);
	if (prev != nullptr){
		curr = prev->next;
		prev->next = curr->next;
	}
	else{
		curr = this->head;
		this->head = curr->next;
	}
	if (curr == this->tail)
		this->tail = prev;
	delete curr;
	this->length -= 1;
}

template <class T>
void LinkedList<T>::Display(std::string seperator) const {
	if (this->length == 0){
		std::cerr << "WARNING: List is empty. There is nothing"\
			<< " to display" << std::endl;
		return;
	}
	Node* temp = this->head;
	std::cout << "Data in the list are:\n";
	while(temp != nullptr){
		std::cout << temp->GetData() << seperator;
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <class T>
void LinkedList<T>::Pop(){
	if (this->IsEmpty()){
		std::cerr << "WARNING: List is empty. There is nothing"\
			<< " to pop" << std::endl;
		return;
	}
	Node* temp = FindPrevious(this->length-1);
	temp->next = nullptr;
	delete this->tail;
	this->tail = temp;
	this->length -= 1;
}

template <class T>
void LinkedList<T>::Clear(){
	Node* temp = this->head;
	while(this->head != nullptr){
		this->head = temp->next;
		delete temp;
		temp = this->head;
	}
	this->length = 0;
}

template <class T>
void LinkedList<T>::Reverse(){ // you can make it better with 3 pointers
	if (this->IsFull()){
		std::cerr << "WARNING: List is full. There is no space"\
			<< "Reverse() operation is failed" << std::endl;
		return;
	}
	Node* curr = new Node(this->head->GetData());
	this->tail = curr;

	Node* temp = this->head;
	this->head = this->head->next;
	delete temp;

	while(this->head != nullptr){
		temp = new Node(this->head->GetData());
		temp->next = curr;
		curr = temp;
		temp = this->head;
		this->head = temp->next;	
		delete temp;
	}
	this->head = curr;
}

template <class T>
void LinkedList<T>::Concat(const LinkedList<T>& input){
	if (this->IsFull()){
		std::cerr << "WARNING: List is full. There is no space"\
			<< "Concat() operation is failed" << std::endl;
		return;
	}
	if (input.IsEmpty()){
		return;
	}
	Node *travel;
	travel = input.head;
	while(travel != nullptr){
		this->Append(travel->GetData());
		travel = travel->next;
	}
}

template <class T>
void LinkedList<T>::Concat(LinkedList<T>* input){
	if (this->IsFull()){
		std::cerr << "WARNING: List is full. There is no space"\
			<< "Concat() operation is failed" << std::endl;
		return;
	}
	if (input.IsEmpty()){
		return;
	}
	Node* travel, temp;
	travel = input->head;
	while(travel != nullptr){
		temp = new Node(travel->GetData());
		this->tail->next = temp;
		this->tail = temp;
		travel = travel->next;
	}
	this->length += input->length;
}

template <class T>
const T& LinkedList<T>::GetData(int index) const {
	if (index < 0 or index > this->length){
		throw std::string("WARNING: Index out of range");
	}
	if (index == 0)
		return this->head->GetData();
	Node* curr = this->FindPrevious(index);
	curr = curr->next;
	return curr->GetData();
}

template <class T>
int LinkedList<T>::GetIndex(T data) const {
	Node* temp = this->head;
	int i = 0;
	while (true){
		if (temp->GetData() == data)
			return i;
		if (temp == nullptr)
			break;
		temp = temp->next;
		i += 1;
	}
	return -1;
}

template <class T>
LinkedList<T>&  LinkedList<T>::operator=(const LinkedList<T>& input){
	if (this != &input){
		this->Clear();
		Node* travel = input.head;
		while (travel != nullptr){
			this->Append(travel->GetData());
			travel = travel->next;
		}
		this->length = input.length;
	}
	return *this;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::FindPrevious(int index) const {
	int i = 0;
	if (index == 0)
		return nullptr;
	Node* temp = this->head;
	while (i != index-1){
		temp = temp->next;
		i += 1;
		if(temp == nullptr)
			break;
	}
	return temp;
}
#endif // LINKED_LIST_H
