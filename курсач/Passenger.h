#pragma once
#include <string>
class Passenger {
public:
	Passenger(std::string passport_id, std::string place_a_date_passport, std::string full_name, std::string dob);
	inline std::string get_passport_id() { return passport_id; };
	inline void set_passport_id(std::string passport_id) {this->passport_id = passport_id;};
private:
	std::string passport_id;
	std::string place_a_date_passport;
	std::string full_name;
	std::string dob;
};

