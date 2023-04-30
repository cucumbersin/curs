#include "Issuance_or_refund_air_ticket.h"

Issuance_or_refund_air_ticket::Issuance_or_refund_air_ticket(std::string passport_id, std::string flight_number, std::string airline_number) {
	this->airline_number = airline_number;
	this->flight_number = flight_number;
	this->passport_id = passport_id;
}

inline std::string Issuance_or_refund_air_ticket::get_passport_id() {
	return passport_id;
}

inline std::string Issuance_or_refund_air_ticket::get_flight_number() {
	return flight_number;
}

inline std::string Issuance_or_refund_air_ticket::get_airline_number() {
	return airline_number;
}
