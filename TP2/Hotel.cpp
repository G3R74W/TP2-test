#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, std::string roomNumber){
  _name = name;
  _city = city;
  _idHotel = _name[0] + _city[0] + roomNumber[0];
}

std::string Hotel::getID(){
  return _idHotel;
}