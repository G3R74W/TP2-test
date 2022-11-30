#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, std::string roomNumber) : _name(name), _city(city){
  _idHotel = _name+_city+roomNumber;
  _roomNumber = stoi(roomNumber);
  for(int i = 0; i<_roomNumber; i++){
      _rooms.push_back(0);
  }
  std::cout << "constructor rnb: " << _roomNumber << std::endl;
}

std::string Hotel::getID(){
  return _idHotel;
}

// Fonction qui permet de détecter la première chambre non créée
int Hotel::room() {
    std::cout << "size: " <<_rooms.size() << std::endl;
    std::cout << "rnb: " << _roomNumber << std::endl;
    for (int i = 0; i < _roomNumber; i++) {
        if (_rooms[i] == 0) {
            _rooms[i] = 1;
            std::cout << "i: " << i << std::endl;
            return i;
        }
    }
}