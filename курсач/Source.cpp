#include "mylist.h"
#include <iostream>
#include <string>
#include <eh.h>
#include "Passenger.h"
#include "Flight.h"
#include "Hash_table.h"
#include "issuance_or_refund_air_ticket.h"

using namespace std;

int main() {
	srand(time(0));
	Hash_table t(150);
	vector<Passenger> a(140,{ "","","","" });
	for (size_t i = 0; i < a.size(); i++) {
		string buf;
		for (size_t i = 0; i < 4; i++) {
			buf.push_back(rand() % 10 + '0');
		}
		buf.push_back('-');
		for (size_t i = 0; i < 6; i++) {
			buf.push_back(rand() % 10 + '0');
		}
		a[i].set_passport_id(buf);
	}
	for (size_t i = 0; i < a.size(); i++) {
		t.add(a[i]);
	}	
	/*for (size_t i = 0; i < 150; i++) {
		if (t[i] == nullptr) {
			cout << i << ' ' << "nullptr" << endl;
		}
		else {
			cout << i << ' ' << (*t[i]).get_passport_id() << endl;
		}
		
	}*/
}