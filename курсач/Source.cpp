#include "Mylist.h"
#include <iostream>
#include <string>
#include <eh.h>
#include <fstream>
#include <vector>
#include "Passenger.h"
#include "Flight.h"
#include "Hash_table.h"
#include "issuance_or_refund_air_ticket.h"
#include "Wood.h"
#include "menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Hash_table t(150);
	cout << "считать изначальные данные? 1-да" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		ifstream file("passanger.txt");
		
		while (!file.eof()) {
			vector<string> buf(4);
			file >> buf[0];

			string buf2;
			file >> buf2;
			buf[1] += buf2;
			buf[1] += ' ';
			file >> buf2;
			buf[1] += buf2;

			file >> buf2;
			buf[2] += buf2;
			buf[2] += ' ';
			file >> buf2;
			buf[2] += buf2;
			buf[2] += ' ';
			file >> buf2;
			buf[2] += buf2;

			file >> buf[3];
			t.add(new Passenger{buf[0], buf[1], buf[2], buf[3]});
		}
	}
	Mylist<Issuance_or_refund_air_ticket> list;
	Wood tree;
	while (true) {
		main_menu(tree, t, list);
	}	
}