#include "Bedroom.h"
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include "Reservation.h"
#include <iostream>
#include <string>
#include <vector>

void liste(int j, std::vector<Client> &list) {
  // permet de creer la liste de tous les clients
  std::string lastname;
  std::string firstname;
  for (int i = 0; i < j; i++) {
    std::cout << "Entrer nom de famille puis prenom" << std::endl;
    std::cin >> lastname >> firstname;
    Client c(lastname, firstname);
    list.push_back(c);
  }
}

int dispo(std::string type, Hotel &h, Date d,
          int night) { // Va permettre de verif si une chambre est dispo aux
                       // dates voulues
  std::vector<Bedroom> r =
      h.get_room(); // recup le vecteur contenant la liste des chambre
  Date e = d;
  for (int i = 0; i < r.size();
       i++) { // permet de parcourir la totalite des chambre de l'hotel jusqu' a
              // en trouver du type voulu
    if (r[i].get_type() == type) {
      int libre = night;

      std::vector<Date> c = r[i].get_reserve();
      std::cout << c.size() << std::endl;
      for (int z = 0; z < night;
           z++) { // verifie que la chambre est disponible durant toute la duree
                  // du séjour voulue a partir de la date d'entree
        for (int j = 0; j < c.size(); j++) {
          if (c[j] == d) {
            libre = libre - 1;
          }
        }
        d.next();
      }
      if (libre == night) { // si la chambre est libre toutes les nuits, on
                            // affiche les infos de celle ci, on bloque la date
                            // et on retourne le numero de la chambre dispo
        std::cout << "Le numéro de la chambre reservee est " << i + 1
                  << " et son prix est de " << r[i].get_price() << std::endl;
        for (int q = 0; q < night; q++) {
          r[i].reserve(e);
          e.next();
        }
        h.set_room(r);
        return i;
      }
    }
  }
  return -1;
}

bool reserv(std::vector<Reservation> &list, Hotel &h,
                  std::vector<Client> &list_client, int numreserv) {
  // permet de creer une reservation
  int day, month, year;
  int rsvNbr;
  std::cout << "Entrez la date (jour, mois, annee)" << std::endl;
  std::cin >> day >> month >> year;
  std::cout << "Entrez la duree du sejour" << std::endl;
  int night;
  std::cin >> night;
  std::string lastname;
  std::cout << " Entrez le nom de famille associe a la reservation :"
            << std::endl;
  std::cin >> lastname;
  int a = -1;
  for (int i = 0; i < list_client.size(); i++) { // parcourt le vecteur de client
    if (list_client[i].get_lastname() == lastname) { // pour vérifier si il existe
      a = i;
    }
  }
  if (a == -1) {
    liste(1, list_client); // si il n'existe pas le cree
    for (int i = 0; i < list_client.size(); i++) {  
      if (list_client[i].get_lastname() == lastname) {
        a = i;
      }
    }
  }
  std::string type;
  std::cout
      << " Entrez le type de chambre voulue parmis : Double , Simple , Suite ."
      << std::endl;
  std::cin >> type;
  Date d(month, day, year);
  int i = dispo(type, h, d,
                night); // recup le numero de la chambre libre si il y en a une
  if (i != -1) {        // si une chambre est dispo, cree la reservation
    std::vector<Bedroom> r = h.get_room();
    Bedroom available = r[i];
    numreserv += 1;
    Reservation entry(d, night, h, list_client[a], available, numreserv);
    list.push_back(entry);
    std::cout << "Votre reservation a été prise en compte" << std::endl;
    std::cout << "Numero de reservation :" << entry.getNumReserv() << std::endl;
    return true;
  } else {
    std::cout << "Aucune chambre de ce type n'est disponible dans notre hotel "
                 "a ces dates."
              << std::endl;
    return false;
  }
}

void display_all_reserv(std::vector<Reservation> listReserv) {
  // permet d'afficher toutes les reservations
  std::cout << "Displaying all reservations :" << std::endl;
  for (int i = 0; i < listReserv.size(); i++) {
    std::cout << listReserv[i] << std::endl;
  }
}

void display_reserv(std::vector<Reservation> listReserv, int reservNbr) {
  // permet d'afficher une reservation specifique a partir d'un numero de
  // reservation
  int nbr = reservNbr - 1;

  // on verifie que le numero de reservation entre par l'utilisateur est valide
  // grace a une fct recursive
  while (nbr > listReserv.size() || nbr < 0) {
    std::cout << "Reservation number deos not exist...\n type new reservation "
                 "number :"
              << std::endl;
    std::cin >> nbr;
    display_reserv(listReserv, reservNbr);
  }

  std::cout << listReserv[nbr];
}

std::vector<int> look_for_reserv(std::string firstname, std::string lastname,
                                 std::vector<Reservation> listReserv) {
  // permet de trouver les reservations d'un client
  // on reconstruit l'id
  std::string idRebuild = firstname[0] + lastname;
  std::vector<int> save;
  // on ajoute la position de reservation dans un vector
  for (int l = 0; l < listReserv.size(); l++) {
    Client c = listReserv[l].get_Client();
    if (c.get_id_client() == idRebuild) {
      save.push_back(l);
    }
  }
  // on return un vector contenant les positions de reservation d'un client dans
  // le vector reserv
  return save;
}

void display_client_reserv(std::string firstname, std::string lastname,
                           std::vector<Reservation> listReserv) {
  // permet d'afficher les reservations d'un client
  int l;
  std::vector<int> save = look_for_reserv(firstname, lastname, listReserv);
  std::cout << "Reservations du client :" << std::endl;
  for (int k = 0; k < save.size(); k++) {
    l = save[k];
    std::cout << listReserv[l] << std::endl;
  }
}

void modif_reserv(std::vector<Reservation> &listReserv, std::string rsvLastname,
                  std::string rsvFirstname, Hotel &h) {
  // permet de modifier une reservation
  std::vector<int> save =
      look_for_reserv(rsvFirstname, rsvLastname, listReserv);
  for (int h = 0; h < save.size(); h++) {
    std::cout << save[h] << std::endl;
  }
  std::cout << " Entrez le numéro de réservation" << std::endl;
  int number_reserv;
  int entrer;
  std::cin >> number_reserv;
  number_reserv = number_reserv - 1;
  for (int i = 0; i < save.size(); i++) {
    if ((number_reserv) == save[i]) { // permet de rechercher la reservation grâce au 
      int position = save[i]; // numéro de réservartion
      Bedroom b = listReserv[position].get_Bedroom();
      Hotel h = listReserv[position].get_Hotel();
      std::string type1 = b.get_type();
      std::cout << "Pour modifier la date de debut de sejour, entrer 1. \n "
                   "Pour modifier le nombre de nuit, taper 2. "
                << std::endl;
      std::cin >> entrer;
      if (entrer == 1) {
        std::cout << "Entrez la nouvelle date de debut de sejour "
                     "(jour/mois/annee) \n";
        int jour, mois, annee;
        std::cin >> jour >> mois >> annee;
        Date new1(mois, jour, annee);
        int nbr1 = listReserv[position].getNightNbr();
        int nbrBed = dispo(type1, h, new1, nbr1);
        if (nbrBed == b.get_number()) {
          listReserv[position].setNewDate(new1);
        } else {
          std::vector<Bedroom> r = h.get_room();
          Bedroom newBedroom = r[nbrBed - 1];
          listReserv[position].setNewBedroom(newBedroom);
          listReserv[position].setNewDate(new1);
          for (int q = 0; q < nbr1; q++) {
            r[nbrBed - 1].reserve(new1);
            new1.next();
          }
        }
        display_client_reserv(rsvFirstname, rsvLastname, listReserv);
      } else if (entrer == 2) {
        std::cout << "Entrez la nouvelle duree de votre sejour. \n";
        int nbr;
        std::cin >> nbr;
        Date recup = listReserv[position].get_Date();
        int nbrBed = dispo(type1, h, recup, nbr);
        if (nbrBed == b.get_number()) {
          listReserv[position].setNightNbr(nbr);
        } else {
          std::vector<Bedroom> r = h.get_room();
          Bedroom newBedroom = r[nbrBed - 1];
          listReserv[position].setNewBedroom(newBedroom);
          listReserv[position].setNightNbr(nbr);
          for (int k = 0; k < nbr; k++) {
            r[nbrBed - 1].reserve(recup);
            recup.next();
          }
          display_client_reserv(rsvFirstname, rsvLastname, listReserv);
        }
      }
    }
  }
}

void cancel_reserv(std::vector<Reservation> &listReserv, int rsvNumber) {
  // permet d'annuler une reservation
  int nbr = rsvNumber;
  listReserv.erase(listReserv.begin() + nbr);
}

int main() {
  // creation d'un hotel test
  Hotel h("TobiasHotel", "Dijon", "10");

  // creation de plusieurs chambres de types differents
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

  // affichage des informations de l'hotel
  std::cout << h;

  // creation du vector contenant la liste des clients
  std::vector<Client> list;
  liste(1, list);
  for (int i = 0; i < list.size(); i++) {
    std::cout << list[i];
  }
  int numreserv = 0;
  // vector contenant toutes les reservations
  std::vector<Reservation> list_reserv;
  bool valide;
  valide = reserv(list_reserv, h, list, numreserv);
  if (valide == true) {
    numreserv++;
  }
  valide = reserv(list_reserv, h, list, numreserv);
  if (valide == true) {
    numreserv++;
  }

  // on affiche toutes les reservations
  display_all_reserv(list_reserv);

  /*on affiche une reservation a partir de son numero de reservation.
Il est a note que les reservation n'ont pas d'attribut "numero de reservation".
Afin d'afficher une reservation a partir de son numero, on utilise sa position
dans le vector contenant toutes les reservations. Ceci rend chaque numero de
reservation unique.
*/
  int reservNbr;
  std::cout << "Entrez numero de reservation : " << std::endl;
  std::cin >> reservNbr;
  display_reserv(list_reserv, reservNbr);

  // Affichage des reservations d'un client a partir de son nom
  std::string firstName, lastName;

  std::cout << "Entrez nom et prenom du client pour afficher ses reservations :"
            << std::endl;
  std::cin >> lastName;
  std::cin >> firstName;

  display_client_reserv(firstName, lastName, list_reserv);

  std::cout << "Entrez nom et prenom du client modifier votre réservation :"
            << std::endl;
  std::cin >> lastName;
  std::cin >> firstName;

  modif_reserv(list_reserv, lastName, firstName, h);

  // annulation d'un reservation (on utilise ici le numero de reservation entre
  // par l'utilisateur plus tet)
  std::cout << "entrez numero de reservation a annuler : " << std::endl;
  std::cin >> reservNbr;
  std::cout << "\n\nannulation de la reservation numero :" << reservNbr
            << std::endl;
  cancel_reserv(list_reserv, reservNbr);

  // on affiche toutes les reservations pour verifier
  display_all_reserv(list_reserv);

  return 0;
}