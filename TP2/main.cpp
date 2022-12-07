#include <iostream>
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include "Bedroom.h"
#include "Client.h"
#include <string>
#include <vector>

void liste(int j, std::vector<Client> list) {
	std::string lastname;
	std::string firstname;
	for (int i = 0; i < j; i++) {
		std::cout << "Entrer nom de famille puis prenom" << std::endl;
		std::cin >> lastname >> firstname;
		Client c(lastname, firstname);
		list.push_back(c);
	}
}

int main() {
	
	Hotel h("TobiasHotel", "Dijon", "10");
	h.create_room("Simple");
	h.create_room("Simple");
	h.create_room("Simple");
	h.create_room("Double");
	h.create_room("Double");
	h.create_room("Double");
	h.create_room("Double");
	h.create_room("Double");
	h.create_room("Suite");
	h.create_room("Suite");
	std::cout << h;
	std::vector<Client> list;
	liste(3, list);
	return 0;
}