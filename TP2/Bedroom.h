#pragma once
#include <iostream>
#include <string>
#include "Hotel.h"


class Bedroom
{
private :
	int _number;
	std::string _type;
	int _price;
	bool _reserve;

public :
	Bedroom(std::string type, Hotel &h);
	~Bedroom();
	int get_number();
	void edit_price(int price);
};

