#include "Hotel.h"

Hotel::Hotel(std::string name, std::string city, std::string roomNumber) : _name(name), _city(city){
  _idHotel = _name+_city+roomNumber;
  _roomNumber = stoi(roomNumber);
}

std::string Hotel::getID(){
  return _idHotel;
}

void Hotel::create_room(std::string type) {
    int i = _rooms.size();
    if (i > _roomNumber) {
        _roomNumber++;
    }
    Bedroom c(type, i);
    _rooms.push_back(c);
}

void Hotel::delete_room(int number) {
    //remove(_rooms.begin(), _rooms.end(), _rooms[number-1]);
    //_rooms.resize(_rooms.size() - 1);
}

int Hotel::get_roomNumber() {
    return _roomNumber;
}