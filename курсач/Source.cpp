#include "Mylist.h"
#include <iostream>
#include <string>
#include <eh.h>
#include <fstream>
#include <vector>
#include "Passenger.h"
#include "Flight.h"
#include "Hash_table.h"
#include "Issuance_or_refund_air_ticket.h"
#include "Wood.h"
#include "menu.h"
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Hash_table t(150);
	SetConsoleCP(1251);
	cout << "считать изначальные данные? 1-да" << endl;
	int choice;
	cin >> choice;	
	Mylist<Issuance_or_refund_air_ticket> list;
	Wood tree;
	if (choice == 1) {
		ifstream file1("passanger.txt");

		while (!file1.eof()) {
			vector<string> buf(4);
			file1 >> buf[0];

			string buf2;
			file1 >> buf2;
			buf[1] += buf2;
			buf[1] += ' ';
			file1 >> buf2;
			buf[1] += buf2;

			file1 >> buf2;
			buf[2] += buf2;
			buf[2] += ' ';
			file1 >> buf2;
			buf[2] += buf2;
			buf[2] += ' ';
			file1 >> buf2;
			buf[2] += buf2;

			file1 >> buf[3];
			t.add(new Passenger{ buf[0], buf[1], buf[2], buf[3] });
		}
		file1.close();
		ifstream file2("Flight.txt");
		while (!file2.eof()) {
			string flight_number, airline_name, departure_airport, arrival_airport, departure_date, departure_time;
			int number_seats, Number_free_places;
			file2 >> flight_number >> airline_name >> departure_airport >> arrival_airport >> departure_date >> departure_time;
			file2 >> number_seats >> Number_free_places;
			tree.push(Flight(flight_number, airline_name, departure_airport, arrival_airport, departure_date, departure_time, number_seats, Number_free_places));
		}
		file2.close();
		ifstream file3("Issuance_or_refund_air_ticket.txt");
		while (!file3.eof()) {
			string passport_id, flight_number, airline_number;
			file3 >> passport_id >> flight_number >> airline_number;
			list.push(Issuance_or_refund_air_ticket(passport_id, flight_number, airline_number));
		}
	}
	while (true) {
		main_menu(tree, t, list);
	}	
}