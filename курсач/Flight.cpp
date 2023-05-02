#include "Flight.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Flight::get_num_flight_number() {
	int buf = flight_number[0] - 'A';
	buf = (buf << 5) + (flight_number[1] - 'A');
	buf = (buf << 5) + (flight_number[2] - 'A');
	buf = (buf * 10) + (flight_number[4] - '0');
	buf = (buf * 10) + (flight_number[5] - '0');
	buf = (buf * 10) + (flight_number[6] - '0');
	return buf;
}

Flight::Flight(
	std::string flight_number,
	std::string airline_name,
	std::string departure_airport,
	std::string arrival_airport,
	std::string departure_date,
	std::string departure_time,
	int number_seats,	int Number_free_places)
{
	this->flight_number = flight_number;//AAA-NNN
	this->airline_name = airline_name;
	this->departure_airport = departure_airport;
	this->arrival_airport = arrival_airport;
	this->departure_date = departure_date;
	this->departure_time = departure_time;
	this->number_seats = number_seats;
	this->Number_free_places = Number_free_places;

}

void Flight::print() {
	cout << flight_number << ' '		  ;
	cout	<< airline_name << setw(20)	  ;
	cout	<< departure_airport << setw(20);
	cout	<< arrival_airport << setw(12);
	cout	<< departure_date << setw(12) ;
	cout	<< departure_time << setw(5)  ;
	cout	<< number_seats << setw(5)	  ;
	cout	<< Number_free_places << endl;
}

bool Flight::new_seats() {
	if (Number_free_places - 1 < 0) {
		return false;
	}
	else {
		Number_free_places--;
		return true;
	}
}
