#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, std::string roomNumber) : _name(name), _city(city), _roomNumber(roomNumber){
  _idHotel = _name+_city+_roomNumber;
  //convert string to int
  int nbr = stoi(_roomNumber);
  for(int i = 0; i<nbr; i++){
    _rooms[i] = 0;
  }
}

std::string Hotel::getID(){
  return _idHotel;
}