#pragma once
#include <string>
class Passenger {
public:
	Passenger(std::string passport_id, std::string place_a_date_passport, std::string full_name, std::string dob);
	inline std::string get_passport_id() const { return passport_id; };
	inline std::string get_place_a_date_passport() const { return place_a_date_passport; };
	inline std::string get_full_name() { return full_name; };
	inline std::string get_dob() { return dob; };

	inline void set_passport_id(std::string passport_id) {this->passport_id = passport_id;};
private:
	std::string passport_id;
	std::string place_a_date_passport;
	std::string full_name;// 3 string which whith min size of 3
	std::string dob;
};