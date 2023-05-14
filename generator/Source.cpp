#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ofstream pas("Passenger.txt");
	for (size_t i = 0; i < 50; i++) {
		string pasport_id;
		for (size_t i = 0; i < 4; i++) {
			pasport_id.push_back(rand() % 10 + '0');
		}
		pasport_id.push_back('-');
		for (size_t i = 0; i < 6; i++) {
			pasport_id.push_back(rand() % 10 + '0');
		}
		string place_a_date_passport;
		int place_size = rand() % 30;
		for (size_t i = 0; i < place_size; i++) {
			place_a_date_passport.push_back(rand() % 32 + 'à');
		}
		place_a_date_passport.push_back(' ');
		int day = rand() % 30 + 1;
		if (day > 9) {
			place_a_date_passport.push_back(day / 10 + '0');
			place_a_date_passport.push_back(day % 10 + '0');
		}
		else {
			place_a_date_passport.push_back(day + '0');
		}
		place_a_date_passport.push_back('.');
		
		int month = rand() % 11 + 1;
		if (month > 9) {
			place_a_date_passport.push_back(month / 10 + '0');
			place_a_date_passport.push_back(month % 10 + '0');
		}
		else {
			place_a_date_passport.push_back(month + '0');
		}
		place_a_date_passport += ".20";
		int year = rand() % 21;
		if (year > 9) {
			place_a_date_passport.push_back(year / 10 + '0');
			place_a_date_passport.push_back(year % 10 + '0');
		}
		else {
			place_a_date_passport.push_back('0');
			place_a_date_passport.push_back(year + '0');
		}
		string full_name;
		for (size_t i = 0; i < 3; i++) {
			int size = rand() % 5 + 5;
			for (size_t i = 0; i < size; i++) {
				if (i == 0) {
					full_name.push_back(rand() % 32 + 'À');
				}
				else {
					full_name.push_back(rand() % 32 + 'à');
				}
			}
			if (i != 2) {
				full_name.push_back(' ');
			}
		}

		string date;
		day = rand() % 30 + 1;
		if (day > 9) {
			date.push_back(day / 10 + '0');
			date.push_back(day % 10 + '0');
		}
		else {
			date.push_back(day + '0');
		}
		date.push_back('.');
		month = rand() % 11 + 1;
		if (month > 9) {
			date.push_back(month / 10 + '0');
			date.push_back(month % 10 + '0');
		}
		else {
			date.push_back(month + '0');
		}
		date += ".20";
		year = rand() % 21;
		if (year > 9) {
			date.push_back(year / 10 + '0');
			date.push_back(year % 10 + '0');
		}
		else {
			date.push_back('0');
			date.push_back(year + '0');
		}
		pas << pasport_id << ' ' << place_a_date_passport << ' ' << full_name << ' ' << date << endl;
	}
}