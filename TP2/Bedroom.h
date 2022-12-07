#pragma once
#include <iostream>
#include <string>


class Bedroom
{
private:
	int _number;
	std::string _type;
	int _price;
	bool _reserve;

public:
	Bedroom(std::string type, int number);
	~Bedroom();
	int get_number();
	void edit_price(int price);
	int get_price();

};
