#include "Passenger.h"

Passenger::Passenger(std::string passport_id, std::string place_a_date_passport, std::string full_name, std::string dob) {
	this->passport_id = passport_id;
	this->place_a_date_passport = place_a_date_passport;
	this->full_name = full_name;
	this->dob = dob;
}
