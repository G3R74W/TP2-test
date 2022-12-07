#include "Bedroom.h"

Bedroom::Bedroom(std::string type, Hotel h):_type(type), _reserve(false), _price(0), _number(0) {
	if (type == "Double") {
		_price = 360;
	}
	else if (type == "Simple") {
		_price = 160;
	}
	else if (type == "Suite") {
		_price = 1200;
	}
	_number = h.room(_type) + 1; // Permet de donner le premier numéro de chambre non attribuée
}

Bedroom::~Bedroom() {

}

int Bedroom::get_number() {
	return _number;
}

void Bedroom::edit_price(int price) { // permet de modifier le prix d'une chambre (setter)
	_price = price;
}

int Bedroom::get_price() {
	return _price;
}