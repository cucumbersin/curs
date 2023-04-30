#include "menu.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

void main_menu(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	system("cls");
	cout << "1 - регистрацию нового пассажира" << endl
		<< "2 - удаление данных о пассажире" << endl
		<< "3 - просмотр всех зарегистрированных пассажиров" << endl
		<< "4 - очистку данных о пассажирах" << endl
		<< "5 - поиск пассажира по Ђномеру паспортаї.\n –езультаты поиска Ц все сведени€ о найденном пассажире и номерах авиарейсов, на который он купил билет" << endl
		<< "6 - поиск пассажира по его ‘»ќ. –езультаты поиска Ц список найденных пассажиров с указанием номера паспорта и ‘»ќ" << endl
		<< "7 - добавление нового авиарейса" << endl
		<< "8 - удаление сведений об авиарейсе" << endl
		<< "9 - просмотр всех авиарейсов" << endl
		<< "10 - очистку данных об авиарейсах" << endl
		<< "11 - поиск авиарейса по Ђномеру авиарейсаї.\n –езультаты поиска Ц все сведени€ о найденном авиарейсе, а также ‘»ќ и номера паспортов пассажиров,\n которые купили билет на этот авиарейс" << endl
		<< "12 - поиск авиарейса по фрагментам названи€ аэропорта прибыти€" << endl
		<< "13 - регистрацию продажи пассажиру авиабилета" << endl
		<< "14 - регистрацию возврата пассажиром авиабилета" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case(1): {
		registration_new_passenger(table);
		break;
	}
	case(2): {
		delete_passenger(table);
		break;
	}
	case(3): {
		show_all_passengers(table);
		break;
	}
	case(4): {
		clean_all_passengers(table);
		break;
	}
	case(5): {
		search_passenger_on_pasport_id(table,list);
		break;
	}
	case(6): {
		search_passenger_on_full_name(table);
		break;
	}
	case(7): {
		registration_new_flight(tree);
		break;
	}
	case(8): {
		delete_flight(tree);
		break;
	}
	case(9): {
		show_all_flights(tree);
		break;
	}
	case(10): {
		clean_all_flights(tree);
		break;
	}
	case(11): {
		search_flight_on_flight_number(tree,table,list);
		break;
	}
	case(12): {
		searh_flight_on_arrival_airoport(tree);
		break;
	}
	case(13): {
		registration_new_issuance_or_refund_air_ticket(list);
		break;
	}
	case(14): {
		//?
		break;
	}
	default:
		break;
	}
	system("pause");
}
//добавить проверки
void registration_new_passenger(Hash_table &table) {
	cout << "¬ведите номер паспорта нового пасажира" << endl;
	string pasport_id, place_a_date_passport, full_name, dob;
	cin >> pasport_id;
	cout << "¬ведите место и дата выдачи паспорта" << endl;	
	cin >> place_a_date_passport;
	cout << "¬ведите ‘»ќ" << endl;
	cin >> full_name;
	cout << "¬ведите дату рождени€" << endl;
	cin >> dob;
	Passenger a(pasport_id, place_a_date_passport, full_name, dob);
	table.add(new Passenger(pasport_id, place_a_date_passport, full_name, dob));
}

void delete_passenger(Hash_table& table) {
	cout << "¬ведите номер паспорта удал€емого пасажира пасажира" << endl;
	string pasport_id;
	cin >> pasport_id;
	table.remove(pasport_id);
}

void show_all_passengers(Hash_table& table) {
	table.print_all();
}

void clean_all_passengers(Hash_table& table) {
	table.clear();
	cout << "все данные о пасажирах удалены" << endl;
}

void search_passenger_on_pasport_id(Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	string pasport_id;
	cout << "¬ведите номер паспорта пасажира данные которого хотите получить" << endl;
	cin >> pasport_id;
	Passenger* found_passenger =  table.search(pasport_id);
	if (found_passenger != nullptr) {
		cout << found_passenger->get_passport_id() << '\t'
			<< found_passenger->get_place_a_date_passport() << '\t'
			<< found_passenger->get_full_name() << '\t'
			<< found_passenger->get_dob() << std::endl;

	}
	else {
		cout << "пасажира с таким номером пасспорта нет" << endl;
	}
}

void search_passenger_on_full_name(Hash_table& table) {

}

void registration_new_flight(Wood& tree) {
}

void delete_flight(Wood& tree) {
}

void show_all_flights(Wood& tree) {
}

void clean_all_flights(Wood& tree) {
}

void search_flight_on_flight_number(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
}

void searh_flight_on_arrival_airoport(Wood& tree) {
}

void registration_new_issuance_or_refund_air_ticket(Mylist<Issuance_or_refund_air_ticket>& list) {
}

