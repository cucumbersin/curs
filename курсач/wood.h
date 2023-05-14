#pragma once
#include <iostream>
#include "Flight.h"
#include <string>
#include "check_func.h"

using namespace std;

class Wood {
	int size = 0;
	struct Nood {
		int key;
		Flight* value;
		int height = 0;
		Nood* ptr_right = nullptr;
		Nood* ptr_left = nullptr;
	};
	Nood* ptr = nullptr;
	void print_recursion(Nood* ptr, int l, bool flag);
	int& del_min_elemente(Nood* ptr);	
	void subtraction_rec(Nood* ptr, double key);
	int height(Nood* p) { return p ? p->height : 0;};
	void fixheight(Nood* p);
	int bfactor(Nood* p);
	Nood* rotateright(Nood* p);
	Nood* rotateleft(Nood* q); // левый поворот вокруг q	
	Nood* balance(Nood* p);// балансировка узла p	
	int get_num_flight_number(string flight_number);	
	void zad_rec(Nood* ptr,string str);
	void delete_tree(Nood* curr);
public:
	Wood() = default;
	bool push(Flight& values);
	bool push(Flight&& valuess);
	bool pop(std::string str);
	Flight* search(Flight& values);
	Flight* search(std::string str);
	void print();
	void zad(string str);
	void delete_tree();
};

inline void Wood::print_recursion(Nood* ptr, int l, bool flag) {
	if (ptr->ptr_left != nullptr) {
		//ptr->ptr_left = balance(ptr->ptr_left);
		print_recursion(ptr->ptr_left, l + 1, flag);
	}	
	if (ptr->ptr_right != nullptr) {
		//ptr->ptr_right = balance(ptr->ptr_right);
		print_recursion(ptr->ptr_right, l + 1, flag);
	}
	if (flag) {
		ptr->value->print();
	}
}



inline int& Wood::del_min_elemente(Nood* ptr) {
	Nood* ptr_previous = ptr;
	ptr = ptr->ptr_right;
	while (true) {
		if (ptr->ptr_left != nullptr) {
			ptr_previous = ptr;
			ptr = ptr->ptr_left;//
		}
		else {
			if (ptr->ptr_right != nullptr && ptr_previous->ptr_right != ptr) {
				ptr_previous->ptr_left = ptr->ptr_right;
			}
			else if (ptr_previous->ptr_right == ptr && ptr->ptr_right != nullptr) {
				ptr_previous->ptr_right = ptr->ptr_right;
			}
			int ret_value = ptr->key;
			if (ptr_previous->ptr_left == ptr) {
				ptr_previous->ptr_left = nullptr;
			}
			if (ptr_previous->ptr_right == ptr) {
				ptr_previous->ptr_right = nullptr;
			}
			delete ptr;
			return ret_value;
		}
	}
}

inline void Wood::subtraction_rec(Nood* ptr, double key) {
	if (ptr->ptr_left != nullptr) { subtraction_rec(ptr->ptr_left, key); }
	ptr->key -= key;
	if (ptr->ptr_right != nullptr) { subtraction_rec(ptr->ptr_right, key); }
}

inline int Wood::bfactor(Nood* p) {
	return height(p->ptr_right) - height(p->ptr_left);
}

inline Wood::Nood* Wood::rotateright(Nood* p) {
	Nood* q = p->ptr_left;
	p->ptr_left = q->ptr_right;
	q->ptr_right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

inline Wood::Nood* Wood::rotateleft(Nood* q) {
	Nood* p = q->ptr_right;
	q->ptr_right = p->ptr_left;
	p->ptr_left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

inline void Wood::fixheight(Nood* p) {
	if (p->ptr_left != nullptr) {
		fixheight(p->ptr_left);
	}
	if (p->ptr_right != nullptr) {
		fixheight(p->ptr_right);
	}
	int hl = height(p->ptr_left);
	int hr = height(p->ptr_right);
	p->height = (hl > hr ? hl : hr) + 1;
}

inline Wood::Nood* Wood::balance(Nood* p) {
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->ptr_right) < 0)
			p->ptr_right = rotateright(p->ptr_right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->ptr_left) > 0)
			p->ptr_left = rotateleft(p->ptr_left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

inline bool Wood::push(Flight& values) {
	int add_value = values.get_num_flight_number();
	int height_buf = 1;
	if (!size) {
		ptr = new Nood;
		ptr->key = add_value;
		ptr->height = height_buf;
		++size;
		return true;
	}
	else {
		if (ptr->key == add_value) {
			return false;
		}
		Nood* ptr_buf = ptr;
		for (;;) {
			height_buf++;
			if (ptr_buf->key == add_value) {
				return false;
			}
			if (ptr_buf->key < add_value) {
				if (ptr_buf->ptr_right != nullptr) {
					ptr_buf = ptr_buf->ptr_right;
				}
				else {
					ptr_buf->ptr_right = new Nood;
					ptr_buf->ptr_right->key = add_value;
					ptr_buf->ptr_right->value = &values;
					ptr_buf->ptr_right->height = 1;
					++size;
					ptr = balance(ptr);
					return true;
				}
			}
			else {
				if (ptr_buf->ptr_left != nullptr) {
					ptr_buf = ptr_buf->ptr_left;
				}
				else {
					ptr_buf->ptr_left = new Nood;
					ptr_buf->ptr_left->key = add_value;
					ptr_buf->ptr_left->value = &values;
					ptr_buf->ptr_left->height = 1;
					++size;
					ptr = balance(ptr);
					return true;
				}
			}
		}
	}
}

inline bool Wood::push(Flight&& valuess) {
	Flight* values1 = new Flight(valuess);
	Flight& values = *values1;
	int add_value = values.get_num_flight_number();
	int height_buf = 1;
	if (!size) {
		ptr = new Nood;
		ptr->key = add_value;
		ptr->value = &values;
		ptr->height = height_buf;
		++size;//
		return true;
	}
	else {
		if (ptr->key == add_value) {
			return false;
		}
		Nood* ptr_buf = ptr;
		for (;;) {
			height_buf++;
			if (ptr_buf->key == add_value) {
				return false;
			}
			if (ptr_buf->key < add_value) {
				if (ptr_buf->ptr_right != nullptr) {
					ptr_buf = ptr_buf->ptr_right;
				}
				else {
					ptr_buf->ptr_right = new Nood;
					ptr_buf->ptr_right->key = add_value;
					ptr_buf->ptr_right->value = &values;
					ptr_buf->ptr_right->height = 1;
					++size;
					ptr = balance(ptr);
					return true;
				}
			}
			else {
				if (ptr_buf->ptr_left != nullptr) {
					ptr_buf = ptr_buf->ptr_left;
				}
				else {
					ptr_buf->ptr_left = new Nood;
					ptr_buf->ptr_left->key = add_value;
					ptr_buf->ptr_left->value = &values;
					ptr_buf->ptr_left->height = 1;
					++size;
					ptr = balance(ptr);
					return true;
				}
			}
		}
	}
}




inline bool Wood::pop(std::string str) {
	int delete_value = get_num_flight_number(str);
	if (!size) {
		return false;
	}
	Nood* ptr_buf = ptr;
	Nood* ptr_buf_previous = ptr;	
	while (ptr_buf->key != delete_value) {
		if (ptr_buf->key < delete_value) {
			if (ptr_buf->ptr_right == nullptr) {
				return false;
			}
			ptr_buf_previous = ptr_buf;
			ptr_buf = ptr_buf->ptr_right;
		}
		else {
			if (ptr_buf->ptr_left == nullptr) {
				return false;
			}
			ptr_buf_previous = ptr_buf;
			ptr_buf = ptr_buf->ptr_left;
		}
	}
	if (ptr_buf->ptr_left == nullptr) {
		if (ptr_buf->ptr_right == nullptr) {
			if (ptr_buf_previous->ptr_right == ptr_buf) {
				ptr_buf_previous->ptr_right = nullptr;
			}
			else {
				ptr_buf_previous->ptr_left = nullptr;
			}
			delete ptr_buf;
			--size;
			ptr = balance(ptr);
			return true;//++
		}
		else {
			Nood* delete_Nood = ptr_buf->ptr_right;
			ptr_buf->key = delete_Nood->key;
			ptr_buf->ptr_left = delete_Nood->ptr_left;
			ptr_buf->ptr_right = delete_Nood->ptr_right;
			delete delete_Nood;
			--size;
			ptr = balance(ptr);
			return true;
		}
	}
	else {
		if (ptr_buf->ptr_right == nullptr) {
			Nood* delete_Nood = ptr_buf->ptr_left;
			ptr_buf->key = delete_Nood->key;
			ptr_buf->ptr_left = delete_Nood->ptr_left;
			ptr_buf->ptr_right = delete_Nood->ptr_right;
			delete delete_Nood;
			--size;
			ptr = balance(ptr);
			return true;
		}
		else {
			ptr_buf->key = del_min_elemente(ptr_buf);
			--size;
			ptr = balance(ptr);
			return true;
		}
	}
}


inline Flight* Wood::search(Flight& values) {
	int search_value = values.get_num_flight_number();
	if (!size) {		
		return  nullptr;
	}
	Nood* ptr_buf = ptr;
	for (;;) {
		if (ptr_buf->key == search_value) {
			return  ptr->value;
		}
		if (ptr_buf->key < search_value) {
			if (ptr_buf->ptr_right == nullptr) {
				return  nullptr;
			}
			ptr_buf = ptr_buf->ptr_right;			
		}
		else {
			if (ptr_buf->ptr_left == nullptr) {				
				return  nullptr;
			}
			ptr_buf = ptr_buf->ptr_left;			
		}
	}
}

inline Flight* Wood::search(std::string str) {
	int search_value = get_num_flight_number(str);
	if (!size) {
		return  nullptr;
	}
	Nood* ptr_buf = ptr;
	for (;;) {
		if (ptr_buf->key == search_value) {
			return  ptr_buf->value;
		}
		if (ptr_buf->key < search_value) {
			if (ptr_buf->ptr_right == nullptr) {
				return  nullptr;
			}
			ptr_buf = ptr_buf->ptr_right;
		}
		else {
			if (ptr_buf->ptr_left == nullptr) {
				return  nullptr;
			}
			ptr_buf = ptr_buf->ptr_left;
		}
	}
}

inline int Wood::get_num_flight_number(string flight_number) {
	int buf = flight_number[0] - 'A';
	buf = (buf << 5) + (flight_number[1] - 'A');
	buf = (buf << 5) + (flight_number[2] - 'A');
	buf = (buf * 10) + (flight_number[4] - '0');
	buf = (buf * 10) + (flight_number[5] - '0');
	buf = (buf * 10) + (flight_number[6] - '0');
	return buf;
}

inline void Wood::zad(string str) {
	zad_rec(ptr, str);
}

inline void Wood::delete_tree() {
	size = 0;
	delete_tree(ptr);
}

inline void Wood::zad_rec(Nood* ptr, string str) {
	if (ptr->ptr_left != nullptr) {
		//ptr->ptr_left = balance(ptr->ptr_left);
		zad_rec(ptr->ptr_left, str);
	}
	if (ptr->ptr_right != nullptr) {
		//ptr->ptr_right = balance(ptr->ptr_right);
		zad_rec(ptr->ptr_right, str);
	}	
	vector<int> buf1 = SearchString(ptr->value->get_arrival_airport(),str);
	if (buf1.size()) { 
		cout << ptr->value->get_flight_number() << ' ' << ptr->value->get_arrival_airport() << ' ' << ptr->value->get_departure_date() << ' ' << ptr->value->get_departure_time() << endl;
	}
	
}

inline void Wood::delete_tree(Nood* curr) {
	if (curr) {
		delete_tree(curr->ptr_left);
		delete_tree(curr->ptr_right);
		delete curr;
	}
}


inline void Wood::print() {
	if (size) {
		print_recursion(ptr, 5, false);
		print_recursion(ptr, 5, true);
	}
}
