#pragma once
#include <string>
class Issuance_or_refund_air_ticket {
public:
	Issuance_or_refund_air_ticket(std::string passport_id, std::string flight_number, std::string airline_number);
	Issuance_or_refund_air_ticket() = default;
	 std::string get_passport_id();
	 std::string get_flight_number();
	 std::string get_airline_number();
	 bool operator== (Issuance_or_refund_air_ticket &right);
private:
	std::string passport_id;
	std::string flight_number;
	std::string airline_number;
};