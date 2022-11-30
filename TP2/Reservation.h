#pragma once
#include <iostream>
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
  Bedroom& _number;
  Hotel& _idHotel;
  Client& _idClient;
  
public:
  Reservation();

};