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
  std::string _city, _hotelName;
  Bedroom& _number;
  Hotel& _idHotel;
  Client& _idClient;
  
public:
  Reservation(Date start, int nightNbr, std::string city, std::string hotelName);

};