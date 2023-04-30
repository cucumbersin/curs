#pragma once
#include <string>
class Issuance_or_refund_air_ticket {
public:
	Issuance_or_refund_air_ticket(std::string passport_id, std::string flight_number, std::string airline_number);
	inline std::string get_passport_id();
	inline std::string get_flight_number();
	inline std::string get_airline_number();
private:
	std::string passport_id;
	std::string flight_number;
	std::string airline_number;
};

