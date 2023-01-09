#include "Bedroom.h"

Bedroom::Bedroom(std::string type, int number)
    : _type(type), _reserve(false), _price(0), _number(0) {
  if (type == "Double") {
    _price = 360;
  } else if (type == "Simple") {
    _price = 160;
  } else if (type == "Suite") {
    _price = 1200;
  }
  _number = number +
            1; // Permet de donner le premier numero de chambre non attribueee
}

Bedroom::~Bedroom() {}

std::vector<Date> Bedroom::get_reserve() { return _reserve; }

int Bedroom::get_number() { return _number; }

void Bedroom::edit_price(
    int price) { // permet de modifier le prix d'une chambre (setter)
  _price = price;
}

int Bedroom::get_price() { return _price; }

std::string Bedroom::get_type() { return _type; }

void Bedroom::reserve(Date a) { _reserve.push_back(a); }

std::ostream &operator<<(std::ostream &os, const Bedroom &b) {
  std::string stat;
  os << "----------------------";
  os << "\n";
  os << "Room number :";
  os << b._number;
  os << "\n";

  os << "Room type :";
  os << b._type;
  os << "\n";

  os << "Price per night :";
  os << b._price;
  os << "\n";

  os << "----------------------";
  os << "\n";
  return os;
}
