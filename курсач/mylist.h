#pragma once
#include <stdexcept>
//#include "Issuance_or_refund_air_ticket.h"
template <class T >
class Mylist {
public:
	Mylist() = default;
	~Mylist();
	void push_back(T);
	size_t size() { return sizes; };
	void push(T);
	T front();
	void pop();
	void pop(T*);
	T& operator[] (size_t index);
private:
	size_t sizes = 0;
	struct Node {
		T val;
		Node* next;
	};
	Node* root = nullptr;
};

template<class T>
inline Mylist<T>::~Mylist() {
	Node* buf = root;
	while (sizes--) {
		Node* buf_next = buf->next;
		delete buf;
		buf = buf_next;
	}
}
//добавление в конец списка (очень медленно работает не использовать)
template<class T>
inline void Mylist<T>::push_back(T elem) {	
	if (sizes == 0) {
		root = new Node;
		root->val = elem;
	}
	else {
		Node* ptr_buf = root;
		for (size_t i = 0; i < sizes - 1; i++) {
			ptr_buf = ptr_buf->next;
		}
		ptr_buf->next = new Node;
		ptr_buf->next->val = elem;
	}
	sizes++;	
}

template<class T>
inline void Mylist<T>::push(T elem) {
	if (sizes == 0) {
		root = new Node;
		root->val = elem;
	}
	else {
		Node* ptr_buf = root;
		Node* ptr = new Node;
		ptr->val = elem;
		ptr->next = ptr_buf;
		root = ptr;
	}
	sizes++;
}

template<class T>
inline T Mylist<T>::front() {
	return root->val;
}

template<class T>
inline void Mylist<T>::pop() {
	if (sizes-- == 0) {		
		throw std::out_of_range("calling pop on null");
	}
	Node* buf = root;
	root = buf->next;
	delete buf;
}

template<class T>
inline void Mylist<T>::pop(T* del_val) {
	
	if (*del_val == root->val) {
		Node* buf = root->next;
		delete root;
		root = buf;
		sizes--;
	}
	else {
		Node* buf = root->next;
		Node* pr_buf = root;
		for (size_t i = 0; i < sizes - 1; i++) {
			if (buf->val == *del_val) {				
				pr_buf->next = buf->next;
				delete buf;
			}
			else {
				pr_buf = pr_buf->next;
				buf = buf->next;
			}
		}
	}
}

template<class T>
inline T& Mylist<T>::operator[](size_t index) {
	Node* buf = root;
	for (size_t i = 0; i < index; i++) {
		buf = buf->next;
	}
	return buf->val;	
}
