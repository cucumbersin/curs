#include "mylist.h"
#include <iostream>
#include <string>
#include <eh.h>
#include "Passenger.h"
#include "Flight.h"
#include "Hash_table.h"
#include "issuance_or_refund_air_ticket.h"
#include "wood.h"

using namespace std;

int main() {
	//srand(time(0));
	Hash_table t(150);
	vector<Flight> a(140);
	for (size_t i = 0; i < a.size(); i++) {
		string str;
		str.push_back(static_cast<char>(rand() % 26 + 'A'));
		str.push_back(static_cast<char>(rand() % 26 + 'A'));
		str.push_back(static_cast<char>(rand() % 26 + 'A'));
		str.push_back('-');
		str.push_back(static_cast<char>(rand() % 10 + '0'));
		str.push_back(static_cast<char>(rand() % 10 + '0'));
		str.push_back(static_cast<char>(rand() % 10 + '0'));
		a[i].set_flight_number(str);
	}
	wood avsd;
	for (size_t i = 0; i < a.size(); i++) {
		avsd.push(a[i]);
	}
	avsd.print();
}