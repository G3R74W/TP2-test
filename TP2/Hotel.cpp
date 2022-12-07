#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, std::string roomNumber) : _name(name), _city(city){
  _idHotel = _name+_city+roomNumber;
  _roomNumber = stoi(roomNumber);
  for(int i = 0; i<_roomNumber; i++){
      _rooms.push_back(0);
  }
}

std::string Hotel::getID(){
  return _idHotel;
}

// Fonction qui permet de détecter la première chambre non créée
int Hotel::room(std::string type) {
    for (int i = 0; i < _roomNumber; i++) {
        if (_rooms[i] == 0) {
            if (type == "Simple")
                _rooms[i] = 1;
                return i;
             if (type == "Double")
                _rooms[i] = 2;
                return i;
             if (type == "Suite")
                _rooms[i] = 3;
                return i;
        }
    }
}

void Hotel::create_room() {
    _roomNumber++;
    _rooms.push_back(0);
}

void Hotel::delete_room() {
    for (int i = _roomNumber; i > 0; i--) {
        if (_rooms[i] == 0) {
            remove(_rooms.begin(), _rooms.end(), _rooms[i]);
            _rooms.resize(_rooms.size() - 1);
        }
        break;
    }
    _roomNumber --;
}

int Hotel::get_roomNumber() {
    return _roomNumber;
}