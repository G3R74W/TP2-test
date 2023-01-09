#pragma once
#include "Bedroom.h"
#include "Client.h"
#include "Date.h"
#include "Hotel.h"
#include <iostream>
#include <string>

class Reservation {
private:
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
              Bedroom bdroom);
  void price();
  // getters

  // returns the date of the start of the reservation
  Date getStartDate();

  // returns the numbers of nights the clients wants to stay at the hotel
  int getNightNbr();

  // returns the total price of the reservation
  float getTotalPrice();

  // setters

  // changes the number of nights the clients wants to stay
  void chngeNightNbr(int nightNbr);

  // changes the date of the biginning of the reservation
  void setNewDate(Date newStart);
};