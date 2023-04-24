#include "Hash_table.h"
#include "Passenger.h"
#include <iostream>

const std::array<size_t, 60> Hash_table::prime_number = { 2, 3, 5, 7, 11, 13, 17,
19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281 };

Hash_table::Hash_table(size_t size) {
	//должн быть поиск ближайшего натурального числа
	size_t raz = abs(static_cast<int>(size) - static_cast<int>(prime_number[0]));
	size_t num = prime_number[0];
	for (size_t i = 1; i < prime_number.size(); i++) {//гавнокод
		size_t buf = abs(static_cast<int>(size) - static_cast<int>(prime_number[i]));
		if (buf > raz) {
			break;
		}
		else {
			raz = buf;
			num = prime_number[i];
		}
	}
	table.resize(num, nullptr);
	capacity = num;
	this->size = 0;
}

void Hash_table::add(Passenger& obj) {
	double filling_rate = static_cast<double>(size++) / static_cast<double>(capacity);
	if (filling_rate > 0.75) {
		//релокация таблицы
		for (size_t i = 0; i < prime_number.size() - 1; i++) {
			if (capacity == prime_number[i]) {
				capacity = prime_number[i + 1];
				break;
			}
		}
		std::vector<Passenger*> table_buf(capacity);
		for (size_t i = 0; i < table.size(); i++) {
			if (table[i] != nullptr) {
				table_buf[get_index(table[i]->get_passport_id())] = table[i];
			}
		}
		table = table_buf;
	}
	else {
		if (table[get_index(obj.get_passport_id())] == nullptr) {
			//std::cout << get_index(obj.get_passport_id()) << ' ' << obj.get_passport_id() << std::endl;
			table[get_index(obj.get_passport_id())] = &obj;//отсутствие колизии
		}
		else {
			//решаем колизию
			//std::cout << collision(get_hash(obj.get_passport_id())) << ' ' << obj.get_passport_id() << ' ' << "col" << std::endl;
			table[collision(get_hash(obj.get_passport_id()))] = &obj;
		}		
	}
}

void Hash_table::remove() {//Fucking Magic
}

Passenger* Hash_table::operator[](size_t index) {
	return table[index];
}

size_t Hash_table::collision(size_t hash) {
	int ha = 0;
	for (size_t i = 0; ; i++) {
		size_t new_hash = (hash + C * i + D * (i * i)) % capacity;
		if (table[new_hash] == nullptr) {
			return new_hash;
		}
	}
}

size_t Hash_table::get_hash(std::string str) {
	int hash = 0;
	for (size_t i = 0; i < str.size(); i++) {
		hash = (hash << 5) - hash + str[i];
	}
	return abs(hash);
}

size_t Hash_table::get_index(std::string str) {
	return get_hash(str) % capacity;
}
