#include <iostream>
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include "Bedroom.h"
#include <string>


int main() {
	
	Hotel h("Ibis", "Paris", "12");
	std::cout << h.get_roomNumber() << std::endl;
	h.create_room("Simple");
	std::cout << h.get_roomNumber() << std::endl;

	h.delete_room(1);
	std::cout << h.get_roomNumber() << std::endl;

	return 0;
}