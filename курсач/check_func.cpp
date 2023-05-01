#include "check_func.h"
#include <string>

using namespace std;

bool check_passport_id(std::string str) {
	if (str.size() != 11) {
		return false;
	}
	for (size_t i = 0; i < 4; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	if (str[4] != '-') {
		return false;
	}
	for (size_t i = 5; i < 11; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
//дописать проверку символов 
bool check_full_name(std::string str) {
	if (str.size() < 12) {
		return false;
	}
	string buf1, buf2, buf3;
	bool space1 = false, space2 = false;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] >= '0'  && str[i] <= '9') {
			return false;
		}
		if (str[i] == ' ') {
			if (!space1) {
				space1 = true;
				continue;
			}
			else if(!space2) {
				space2 = true;
				continue;
			}
			else {
				return false;
			}
		}
		if (!space1) {
			buf1.push_back(str[i]);
		}
		else if (!space2) {
			buf2.push_back(str[i]);
		}
		else {
			buf3.push_back(str[i]);
		}
	}
	if (buf1.size() < 3 || buf2.size() < 3 || buf3.size() < 3) {
		return false;
	}
	return true;
}

bool check_dob(std::string str) {
	return false;
}

bool check_flight_number(std::string str) {
	if (str.size() != 7) {
		return false;
	}
	for (size_t i = 0; i < 3; i++) {
		if (str[i] < 'A' || str[i] > 'Z') {
			return false;
		}
	}
	if (str[3] != '-') {
		return false;
	}
	for (size_t i = 4; i < 7; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

bool check_date(std::string str) {
	if (str.size() < 8) {
		return false;
	}
	int count_dot = 0;
	string day, month, year;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			count_dot++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			if (count_dot == 0) {
				day.push_back(str[i]);
			}
			else if (count_dot == 1) {
				month.push_back(str[i]);
			}
			else if (count_dot == 2) {
				year.push_back(str[i]);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	if (day.size() > 2 || month.size() > 2 || year.size() != 4) {
		return false;
	}
	int day_num = 0;
	if (day.size() == 2) {
		day_num += (day[0] - '0') * 10;
		day_num += day[1] - '0';
	}
	else {
		day_num += day[0] - '0';
	}
	int month_num = 0;
	if (month.size() == 2) {
		month_num += (month[0] - '0') * 10;
		month_num += month[1] - '0';
	}
	else {
		month_num += month[0] - '0';
	}
	int year_num = 0;
	for (size_t i = 0; i < 4; i++) {
		year_num = year_num * 10;
		year_num += year[i] - '0';
	}
	if (!(year_num > 1950 && year_num < 2100)) {
		return false;
	}
	if (!(month_num >= 1 && month_num <= 12)) {
		return false;
	}
	if (month_num == 1 || month_num == 3 || month_num == 5 || month_num == 7 || month_num == 8 || month_num == 10 || month_num == 12) {
		if (day_num >= 1 && day_num <= 31) {
			return true;
		}
		else {
			return false;
		}
	}
	else if(month_num == 4 || month_num == 6 || month_num == 9 || month_num == 11) {
		if (day_num >= 1 && day_num <= 30) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if ((year_num - 1920) % 4) {
			//невысокосный
			if (day_num >= 1 && day_num <= 28) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (day_num >= 1 && day_num <= 29) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool check_airline_number(std::string str) {
	if (str.size() != 9) {
		return false;
	}
	for (size_t i = 0; i < 9; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
