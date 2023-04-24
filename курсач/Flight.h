#pragma once
#include <string>
class Flight {
public:
	int get_num_flight_number();
	Flight() = default;
	Flight(
		std::string flight_number,
		std::string airline_name,
		std::string departure_airport,
		std::string arrival_airport,
		std::string departure_date,
		std::string departure_time,
		int number_seats,
		int Number_free_places
	);
	inline void set_flight_number(std::string flight_number) { this->flight_number = flight_number; };
	inline std::string get_flight_number() { return flight_number; };
private:
	std::string flight_number;//AAA-NNN
	std::string airline_name;
	std::string departure_airport;
	std::string arrival_airport;
	std::string departure_date;
	std::string departure_time;
	int number_seats = 0;
	int Number_free_places = 0;
};

