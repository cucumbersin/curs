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
		clean_all_passengers(table,list);
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
		delete_flight(tree,list);
		break;
	}
	case(9): {
		show_all_flights(tree);
		break;
	}
	case(10): {
		clean_all_flights(tree,list);
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
		del_issuance_or_refund_air_ticket(tree, table, list);
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
	string buf;
	cin >> buf;//
	place_a_date_passport += buf;
	place_a_date_passport += ' ';
	cin >> buf;//
	place_a_date_passport += buf;
	cout << "Введите ФИО" << endl;
	cin >> buf;
	full_name = buf;
	full_name.push_back(' ');
	cin >> buf;
	full_name += buf;
	full_name.push_back(' ');
	cin >> buf;
	full_name += buf;
	if(!check_full_name(full_name)) {
		cout << "Не корректный ввод" << endl;
		cout << full_name;
		return;
	}
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

void clean_all_passengers(Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	table.clear();
	list.clear();
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
			bool first_enter = true;
			for (size_t i = 0; i < list.size(); i++) {
				if (list[i].get_passport_id() == pasport_id) {
					if (first_enter) {
						cout << "номера авиарейсов на которые куплины билеты этим человеком" << endl;
						first_enter = false;
					}
					cout << list[i].get_flight_number() << endl;
				}
			}
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
	std::vector<Passenger*> mas = table.secret();
	string full_name,buf;
	cout << "Введите ФИО" << endl;
	cin >> buf;
	full_name = buf;
	full_name.push_back(' ');
	cin >> buf;
	full_name += buf;
	full_name.push_back(' ');
	cin >> buf;
	full_name += buf;
	if (check_full_name(full_name)) {
		for (size_t i = 0; i < mas.size(); i++) {		
			if (mas[i] != nullptr && mas[i]->get_full_name() == full_name) {
				cout << mas[i]->get_passport_id() << ' ' << mas[i]->get_full_name();
			}
		}
	}
	else {
		cout << "Не корректный ввод" << endl;
		return;
	}
}

void registration_new_flight(Wood& tree) {
	cout << "Введите новый номер авиорейса" << endl;
	string flight_number;
	cin >> flight_number;
	if (!check_flight_number(flight_number)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите название авиакомпании" << endl;
	string airline_name;
	cin >> airline_name;
	if (!check_airport_o_airline_name(airline_name)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите аэропорт отправления" << endl;
	string departure_airport;
	cin >> departure_airport;
	if (!check_airport_o_airline_name(departure_airport)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите аэропорт прибытия" << endl;
	string arrival_airport;
	cin >> arrival_airport;
	if (!check_airport_o_airline_name(arrival_airport)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите дату отправления " << endl;
	string departure_date;
	cin >> departure_date;
	if (!check_date(departure_date)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите время отправления " << endl;
	string departure_time;
	cin >> departure_time;
	if (!check_time(departure_time)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	cout << "Введите количество мест" << endl;
	string number_seats_str;	
	cin >> number_seats_str;
	if (!is_number(number_seats_str)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	int number_seats_num = atoi(number_seats_str.c_str());
	cout << "Введите количество свободных мест" << endl;
	string Number_free_places_str;
	cin >> Number_free_places_str;
	if (!is_number(Number_free_places_str)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	int Number_free_places_num = atoi(Number_free_places_str.c_str());
	if (Number_free_places_num > number_seats_num) {
		cout << "Не корректный ввод количество свободных мест превышает общее число мест" << endl;
		return;
	}
	tree.push(Flight(flight_number, airline_name, departure_airport, arrival_airport, departure_date, departure_time, number_seats_num, Number_free_places_num));
}

void delete_flight(Wood& tree, Mylist<Issuance_or_refund_air_ticket>& list) {
	cout << "Введите номер удаляемого авиорейса" << endl;
	string flight_number;
	cin >> flight_number;
	if (!check_flight_number(flight_number)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	if (!tree.pop(flight_number)) {
		cout << "Такого авиорейса не сушествует" << endl;
		return;
	}
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i].get_flight_number() == flight_number) {
			list.pop(&list[i]);
		}
		
	}	
}

void show_all_flights(Wood& tree) {
	tree.print();
}

void clean_all_flights(Wood& tree, Mylist<Issuance_or_refund_air_ticket>& list) {
	tree.delete_tree();	
	list.clear();
}

void search_flight_on_flight_number(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	cout << "Введите номер авиорейса" << endl;
	string flight_number;
	cin >> flight_number;
	if (!check_flight_number(flight_number)) {
		cout << "Не корректный ввод" << endl;
		return;
	}
	Flight* buf = tree.search(flight_number);
	buf->print();
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i].get_flight_number() == flight_number) {
			cout << list[i].get_passport_id() << ' ' << table.search(list[i].get_passport_id())->get_full_name() << endl;
		}
		break;
	}
}

void searh_flight_on_arrival_airoport(Wood& tree) {
	cout << "фрагментам названия аэропорта прибытия" << endl;
	string str;
	cin >> str;
	tree.zad(str);
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
	if (tree.search(flight_number)->new_seats()) {
		list.push(Issuance_or_refund_air_ticket(pasport_id, flight_number, airline_number));
		vector<Issuance_or_refund_air_ticket> mas;
		for (int i = 0; i < list.size(); i++)
		{
			mas.push_back(list[i]);
		}
		quickSort(mas, 0, mas.size() - 1);
		list.clear();
		for (size_t i = 0; i < mas.size(); i++)
		{
			list.push_back(mas[i]);
		}		
	}
	else {
		cout << "Свободных мест нет" << endl;
	}
}

void del_issuance_or_refund_air_ticket(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list) {
	cout << "Введите номер паспорта человека белет которого хотите вернуть" << endl;
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
	cout << "Введите номер авиорейса белет которого хотите вернуть" << endl;
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
	bool exist = false;
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i].get_passport_id() == pasport_id) {
			if (list[i].get_flight_number() == flight_number) {
				list.pop(&list[i]);
				exist = true;
				tree.search(flight_number)->del_seats();
				break;
			}
		}
	}
	if (!exist) {
		cout << "такого билета не существует" << endl;
	}
}

void quickSort(vector<Issuance_or_refund_air_ticket>& arr, int left, int right)
{
	int i = left, j = right;
	Issuance_or_refund_air_ticket tmp;
	Issuance_or_refund_air_ticket pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

