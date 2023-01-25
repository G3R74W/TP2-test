#pragma once
#include "Bedroom.h"
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include <iostream>
#include <string>

class Reservation {
private:
  // reservation number
  int _rsvNbr;
  // date of the begining of the reservation
  Date _start;
  // Number of nights spent at the hotel
  int _nightNbr;
  // total price of the reservation
  float _totalPrice;

  // bedroom - Hotel & client objects
  Bedroom _bdroom;
  Hotel _htl;
  Client _touriste;

public:
  Reservation(Date start, int nightNbr, Hotel htl, Client touriste,
              Bedroom bdroom, int numreserv);
  void price();
  // getters

  // returns the date of the start of the reservation
  Date getStartDate();

  // returns the numbers of nights the clients wants to stay at the hotel
  int getNightNbr();

  // returns the total price of the reservation
  float getTotalPrice();

  int getNumReserv();

  Bedroom get_Bedroom();

  Hotel get_Hotel();

  Date get_Date();

  // setters
  void setNightNbr(int night);

  // changes the number of nights the clients wants to stay
  void chngeNightNbr(int nightNbr);

  // changes the date of the biginning of the reservation
  void setNewDate(Date newStart);

  void setNewBedroom(Bedroom newBedroom);

  Client get_Client();
  // surcharge d'operateur pour pouvoir afficher les reservations
  friend std::ostream &operator<<(std::ostream &os, const Reservation &r);
};