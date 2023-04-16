#pragma once
#include <stdexcept>
template <class T = int>
class Mylist {
public:
	Mylist() = default;
	~Mylist();
	void push_back(T);
	size_t size() { return sizes; };
	void push(T);
	T front();
	void pop();
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
