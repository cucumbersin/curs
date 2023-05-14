#include "Issuance_or_refund_air_ticket.h"
#include <string>

Issuance_or_refund_air_ticket::Issuance_or_refund_air_ticket(std::string passport_id, std::string flight_number, std::string airline_number) {
	this->airline_number = airline_number;
	this->flight_number = flight_number;
	this->passport_id = passport_id;
}

 std::string Issuance_or_refund_air_ticket::get_passport_id() {
	return passport_id;
}

 std::string Issuance_or_refund_air_ticket::get_flight_number() {
	return flight_number;
}

 std::string Issuance_or_refund_air_ticket::get_airline_number() {
	return airline_number;
}

 bool Issuance_or_refund_air_ticket::operator==(Issuance_or_refund_air_ticket& right) {
	if (passport_id == right.passport_id && flight_number == right.flight_number && airline_number == right.airline_number) {
		return true;
	}
	return false;
}

 bool Issuance_or_refund_air_ticket::operator<(Issuance_or_refund_air_ticket& right)
 {
	 return this->get_airline_number() < right.airline_number;
 }

 bool Issuance_or_refund_air_ticket::operator>(Issuance_or_refund_air_ticket& right)
 {
	 return this->get_airline_number() > right.airline_number;
 }
