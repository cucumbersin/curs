#include "menu.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Passenger.h"
#include <iomanip>
#include "Mylist.h"
#include "Hash_table.h"
#include "Wood.h"
#include "Issuance_or_refund_air_ticket.h"
#include "Flight.h"
#include "check_func.h"


using namespace std;

void main_menu(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	system("cls");
	cout << "1 - регистрацию нового пассажира" << endl
		<< "2 - удаление данных о пассажире" << endl
		<< "3 - просмотр всех зарегистрированных пассажиров" << endl
		<< "4 - очистку данных о пассажирах" << endl
		<< "5 - поиск пассажира по «номеру паспорта».\n Результаты поиска – все сведения о найденном пассажире и номерах авиарейсов, на который он купил билет" << endl
		<< "6 - поиск пассажира по его ФИО. Результаты поиска – список найденных пассажиров с указанием номера паспорта и ФИО" << endl
		<< "7 - добавление нового авиарейса" << endl
		<< "8 - удаление сведений об авиарейсе" << endl
		<< "9 - просмотр всех авиарейсов" << endl
		<< "10 - очистку данных об авиарейсах" << endl
		<< "11 - поиск авиарейса по «номеру авиарейса».\n Результаты поиска – все сведения о найденном авиарейсе, а также ФИО и номера паспортов пассажиров,\n которые купили билет на этот авиарейс" << endl
		<< "12 - поиск авиарейса по фрагментам названия аэропорта прибытия" << endl
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
		delete_passenger(table, list);
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
		registration_new_issuance_or_refund_air_ticket(tree, table, list);
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
	cout << "Введите номер паспорта нового пасажира" << endl;
	string pasport_id, place_a_date_passport, full_name, dob;
	cin >> pasport_id;
	if (!check_passport_id(pasport_id)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите место и дата выдачи паспорта" << endl;	
	cin >> place_a_date_passport;
	cout << "Введите ФИО" << endl;
	cin >> full_name;
	cout << "Введите дату рождения" << endl;
	cin >> dob;
	if (!check_date(dob)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	Passenger a(pasport_id, place_a_date_passport, full_name, dob);
	table.add(new Passenger(pasport_id, place_a_date_passport, full_name, dob));
}

void delete_passenger(Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	cout << "Введите номер паспорта удаляемого пасажира пасажира" << endl;
	string pasport_id;
	cin >> pasport_id;
	if (check_passport_id(pasport_id)) {
		if (table.search(pasport_id) != nullptr) {
			for (size_t i = 0; i < list.size(); i++) {
				if (list[i].get_flight_number() == pasport_id) {
					list.pop(&list[i]);
				}
			}
			table.remove(pasport_id);
		}
	}
	else {
		cout << "Не корректный ввод" << endl;
		return;
	}
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
	cout << "Введите номер паспорта пасажира данные которого хотите получить" << endl;
	cin >> pasport_id;
	if (check_passport_id(pasport_id)) {
		Passenger* found_passenger = table.search(pasport_id);
		if (found_passenger != nullptr) {
			cout << found_passenger->get_passport_id() << std::setw(40)
				<< found_passenger->get_place_a_date_passport() << std::setw(40)
				<< found_passenger->get_full_name() << std::setw(40)
				<< found_passenger->get_dob() << std::endl;
		}
		else {
			cout << "пасажира с таким номером пасспорта нет" << endl;
		}
	}
	else {
		cout << "Не корректный ввод" << endl;
		return;
	}
}

void search_passenger_on_full_name(Hash_table& table) {
	
}

void registration_new_flight(Wood& tree) {

}

void delete_flight(Wood& tree) {
}

void show_all_flights(Wood& tree) {
	tree.print();
}

void clean_all_flights(Wood& tree) {
}

void search_flight_on_flight_number(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
}

void searh_flight_on_arrival_airoport(Wood& tree) {
}

void registration_new_issuance_or_refund_air_ticket(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	cout << "Введите номер паспорта человека на которого хотите зарегестрировать билет" << endl;
	string pasport_id;
	cin >> pasport_id;
	if (check_passport_id(pasport_id)) {
		if (table.search(pasport_id) == nullptr) {
			cout << "Такого пасажира нет в базе" << endl;
			return;
		}
	}
	else {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите номер авиорейса на который хотите зарегестрировать билет" << endl;
	string flight_number;
	cin >> flight_number;
	if (check_flight_number(flight_number)) {
		if (tree.search(flight_number) == nullptr) {
			cout << "Такого авиорейса нет в базе" << endl;
			return;
		}
	}
	else {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите номер билета" << endl;
	string airline_number;
	cin >> airline_number;
	if (!check_airline_number(airline_number)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	list.push(Issuance_or_refund_air_ticket(pasport_id, flight_number, airline_number));
}

