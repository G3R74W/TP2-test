#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Bedroom.h"
#include "Client.h"
#include "Hotel.h"

class Reservation{
private:
  //date of the begining of the reservation
  Date _start;
  //Number of nights spent at the hotel
  int _nightNbr;
  //total price of the reservation
  float _totalPrice;

  //bedroom - Hotel & client objects
  Bedroom _bdroom;
  Hotel _htl;
  Client _touriste;
  
public:
  Reservation(Date start, int nightNbr, Hotel htl, Client touriste);
  

};