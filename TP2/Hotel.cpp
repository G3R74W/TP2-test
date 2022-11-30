#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, int roomNumber){
  _name = name;
  _city = city;
  _idHotel = _name[0] + _city[0] + roomNumber;
}

std::string Hotel::getID(){
  return _idHotel;
}