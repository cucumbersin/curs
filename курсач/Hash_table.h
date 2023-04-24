#pragma once
#include <string>
#include "Passenger.h"
#include <vector>
#include <array>

class Hash_table {
public:
	Hash_table(size_t size);
	void add(Passenger&);
	void remove();
	Passenger* operator[](size_t);//отладка
private:
	std::vector<Passenger*> table;
	static const  std::array<size_t,60> prime_number;
	size_t capacity;
	size_t size;
	size_t get_hash(std::string);
	size_t get_index(std::string);
	static const size_t D = 3, C = 2;//адрес=h(x)+ci+di2
	size_t collision(size_t);
};

