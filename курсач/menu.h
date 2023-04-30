#pragma once
#include "Hash_table.h"
#include "Mylist.h"
#include "issuance_or_refund_air_ticket.h"
#include "Wood.h"

void main_menu(Wood& tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket>& list);

void registration_new_passenger(Hash_table &table);

void delete_passenger(Hash_table& table);

void show_all_passengers(Hash_table& table);

void clean_all_passengers(Hash_table& table);

void search_passenger_on_pasport_id(Hash_table& table, Mylist<Issuance_or_refund_air_ticket> &list);

void search_passenger_on_full_name(Hash_table& table);

void registration_new_flight(Wood &tree);

void delete_flight(Wood &tree);

void show_all_flights(Wood &tree);

void clean_all_flights(Wood &tree);

void search_flight_on_flight_number(Wood &tree, Hash_table& table, Mylist<Issuance_or_refund_air_ticket> &list);
//поиска по сегменту названия аэропорта прибытия
void searh_flight_on_arrival_airoport(Wood& tree);

void registration_new_issuance_or_refund_air_ticket(Mylist<Issuance_or_refund_air_ticket>& list);