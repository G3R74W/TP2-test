/**
 * @Author: Dominique Ginhac <d0m>
 * @Date:   2019-10-15T09:46:41+02:00
 * @Email:  dginhac@u-bourgogne.fr
 * @Project: C++ Programming - ESIREM 3A IT
 * @Summary:  Methods - Helpers functions
*/
#include "date.h"
#include <assert.h> 



Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
    bool status = isDate(month, day, year);
    assert(status && "Date is not valid");
}

int Date::month() const {
    return _month;
}

int Date::day() const {
    return _day;
}

int Date::year() const {
    return _year;
}

void Date::updateMonth(int month) {
    bool status = isDate(month, _day, _year);
    assert(status == true && "New month is not valid");
    _month = month;
}

void Date::updateDay(int day) {
    bool status = isDate(_month, day, _year);
    assert(status == true && "New day is not valid");
    _day = day;
}

void Date::next() {
    if ((_month == 12) && (_day == 31)) {
        _day = 1;
        _month = 1;
        _year++;
    }
    else if (_day == getDaysInMonth(_month)) {
        _day = 1;
        _month++;
    }
    else {
        _day++;
    }
}

void Date::back() {
    if ((_month == 1) && (_day == 1)) {
        _day = 31;
        _month = 12;
    }
    else if (_day == 1) {
        _month--;
        _day = getDaysInMonth(_month);
    }
    else {
        _day--;
    }
}


/**
 *
 * Helper functions
 *
*/

bool isDate(int month, int day, int year) {
    if ((year < 2022) || (year > 2050)) return false;
    if ((day < 1) || (day > 31)) return false;
    if ((month < 1) || (month > 12)) return false;
    if ((month == 2) && (day > 28)) return false;
    if (((month == 4) || (month == 6) ||
        (month == 9) || (month == 11)) && (day > 30)) return false;
    return true;
}

int getDaysInMonth(int month) {
    assert(((month >= 1) && (month <= 12)) && "Month is not valid");
    if (month == 2) return 28;
    if ((month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12)) return 31;
    return 30;
}

int dayOfYear(Date d) {
    auto day = 0;
    for (auto i = 1; i < d.month(); i++) {
        day += getDaysInMonth(i);
    }
    day += d.day();
    return day;
}

std::string toString(Date d) {
    return std::to_string(d.day()) + "/" + std::to_string(d.month());
}
