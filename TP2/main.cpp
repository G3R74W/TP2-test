#include <iostream>
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include "Bedroom.h"
#include "Client.h"
#include "Reservation.h"
#include <string>
#include <vector>

void liste(int j, std::vector<Client> &list) {
	std::string lastname;
	std::string firstname;
	for (int i = 0; i < j; i++) {
		std::cout << "Entrer nom de famille puis prenom" << std::endl;
		std::cin >> lastname >> firstname;
		Client c(lastname, firstname);
		list.push_back(c);
	}
	
}

void liste_reserv(std::vector<Reservation> &list, Hotel h, std::vector<Client> &list_client,) {
		int day, month, year;
		std::cout << "Entrez la date (jour, mois, annee)" << std::endl;
		std::cin >> day >> month >> year;
		std::cout << "Entrez la duree du sejour" << std::endl;
		int night;
		std::cin >> night;
		std::string lastname;
		std::cin >> lastname;
		int a = -1;
		for (int i=0; i < list_client.size(); i++) {
			if (list_client[i].get_lastname() == lastname) {
				a = i;
			}
		}
		if (a == 0) {
			liste(1, list_client);
		}
		std::string type;
		std::cin >> type;
		dispo(); // il faut creer dispo
		Date d(month, day, year);
		Reservation r(d, night, h, list_client[a]); // il faudra ajouter une chambre en fonction des dispos

}

int dispo(std::string type ) {	// Va permettre de verif si une chambre est dispo a une periode donnee ou non

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
	liste(1, list);
	for (int i = 0; i < list.size(); i++){
		std::cout << list[i];
	}
	std::vector<Reservation> list_reserv;
	
	return 0;
}