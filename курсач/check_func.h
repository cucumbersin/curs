#pragma once
#include <string>
#include <vector>

bool check_passport_id(std::string str);

bool check_place(std::string str);

bool check_full_name(std::string str);

bool check_dob(std::string str);

bool check_flight_number(std::string str);

bool check_date(std::string str);

bool check_time(std::string str);

bool check_airport_o_airline_name(std::string str);

bool check_airline_number(std::string str);

bool is_number(const std::string& s);

int Max(int a, int b);

void BadCharHeuristic(std::string str, int size, int* badChar);

std::vector<int> SearchString(std::string str, std::string pat);