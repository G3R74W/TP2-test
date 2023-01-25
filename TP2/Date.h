/**
 * @File:     date.h
 * @Author:   D. Ginhac (dginhac@u-bourgogne.fr)
 * @Date:     Fall 2021
 * @Course:   C++ Programming / Esirem 3A Informatique Electronique Robotique
 * @Summary:  Methods - Helpers functions
 */

#include <iostream>
#include <string>

#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date(int month = 1, int day = 1, int year = 2022);
  int month() const;
  int day() const;
  int year() const;
  void updateMonth(int month);
  void updateDay(int day);
  void next();
  void back();
  bool operator==(const Date &d) const;

  // ajout d'une surcharge de l'operateur "<<"
  friend std::ostream &operator<<(std::ostream &os, const Date &d);

private:
  int _month;
  int _day;
  int _year;
};

bool isDate(int month, int day, int year);
int getDaysInMonth(int month);
int dayOfYear(Date d);
std::string toString(Date d);

#endif // DATE_H

