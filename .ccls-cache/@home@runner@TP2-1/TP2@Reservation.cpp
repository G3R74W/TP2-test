#include "Reservation.h"
#include "Date.h"

Reservation::Reservation(Date start, int nightNbr, Hotel htl, Client touriste, Bedroom bdroom)
    : _start(start), _nightNbr(nightNbr), _htl(htl), _touriste(touriste),
      _bdroom(bdroom) {
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

// setters

// changes the number of nights the clients wants to stay
void Reservation::chngeNightNbr(int nightNbr) { _nightNbr = nightNbr; }

// changes the date of the biginning of the reservation
void Reservation::setNewDate(Date newStart) { _start = newStart; }

void Reservation::price() {
  int price = _bdroom.get_price();
  _totalPrice = _nightNbr * price;
}