#pragma once
#include <iostream>
#include <string>

class Client
{
private :
	std::string _id_client;
	std::string _lastname;
	std::string _firstname;

public :
	Client(std::string lastname, std::string firstname);
	std::string get_id_client();
	std::string get_lastname();
	friend std::ostream& operator<<(std::ostream& os, const Client& c);
};

