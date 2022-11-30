#pragma once
#include <iostream>
#include <string>


class Bedroom
{
private :
	int _number;
	std::string _type;
	int _price;
	bool _reserve;

public :
	Bedroom(std::string type, int test);
	int get_number();
};

