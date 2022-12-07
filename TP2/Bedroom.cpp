#include "Bedroom.h"

Bedroom::Bedroom(std::string type, int test):_type(type), _reserve(false), _price(0), _number(0) {
	if (type == "Double") {
		_price = 360;
	}
	else if (type == "Simple") {
		_price = 160;
	}
	else if (type == "Suite") {
		_price = 1200;
	}
	_number = test + 1; // Permet de donner le premier numero de chambre non attribuee
}

int Bedroom::get_number() {
	return _number;
}