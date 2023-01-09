#include "Reservation.h"
#include "Date.h"

Reservation::Reservation(Date start, int nightNbr, Hotel htl, Client touriste,
                         Bedroom bdroom, int numreserv)
    : _start(start), _nightNbr(nightNbr), _htl(htl), _touriste(touriste),
      _bdroom(bdroom), _rsvNbr(numreserv) {
  // works out the total price of the reservation
  int price = _bdroom.get_price();
  _totalPrice = _nightNbr * price;
}

// getters

// returns the date of the start of the reservation
Date Reservation::getStartDate() { return _start; }

// returns the numbers of nights the clients wants to stay at the hotel
int Reservation::getNightNbr() { return _nightNbr; }

// returns the total price of the reservation
float Reservation::getTotalPrice() { return _totalPrice; }

int Reservation::getNumReserv() { return _rsvNbr; }

Client Reservation::get_Client() {
  return _touriste;
}

Bedroom Reservation::get_Bedroom(){
  return _bdroom;
}

Hotel Reservation::get_Hotel(){
  return _htl;
}

Date Reservation::get_Date(){
  return _start;
}

// setters

void Reservation::setNightNbr(int night){
  _nightNbr = night;
}

// changes the number of nights the clients wants to stay
void Reservation::chngeNightNbr(int nightNbr) { _nightNbr = nightNbr; }

// changes the date of the biginning of the reservation
void Reservation::setNewDate(Date newStart) { _start = newStart; }

void Reservation::price() {
  int price = _bdroom.get_price();
  _totalPrice = _nightNbr * price;
}

void Reservation::setNewBedroom(Bedroom newBedroom){
  _bdroom = newBedroom;
}

//surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &os, const Reservation &r) {
  os << "----------------------";
  os << "\n";

  os << "Hotel info :\n";
  os << r._htl;
  os << "\n";

  os << "Arrival date :\n";
  os << r._start;
  os << "\n";

  os << "Number of nigths :";
  os << r._nightNbr;
  os << "\n";

  os << "----------------------";
  os << "\n";

  os << "Client info :\n";
  os << r._touriste;
  os << "\n";

  os << "Total price :";
  os << r._totalPrice;
  os << " euros\n";
  os << "----------------------";
  os << "\n";
  return os;
}