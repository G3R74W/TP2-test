#pragma once
#include "Date.h"
#include <iostream>
#include <string>
#include <vector>

class Bedroom {
private:
  int _number;
  std::string _type;
  int _price;
  std::vector<Date> _reserve; // ajouter le fait de voir a quelle date la
                              // chambre est occupe/dispo

public:
  Bedroom(std::string type, int number);
  ~Bedroom();
  std::vector<Date> get_reserve();
  int get_number();
  void edit_price(int price);
  int get_price();
  void reserve(Date);
  std::string get_type();
  friend std::ostream &operator<<(std::ostream &os, const Bedroom &b);
};
