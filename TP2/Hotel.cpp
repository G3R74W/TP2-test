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

void Hotel::display_info_bedroom() {
    for (int i = 0; i < _rooms.size(); i++) {
        std::cout << _rooms[i];
    }
}

std::ostream&o operator<<(std::ostream &os, const Hotel &h){
  os << "----------------------";
  os << "\n";
  
  os << "Hotel Name :";
  os << h._name;
  os << "\n";

  os << "Hotel ID :";
  os << h._idHotel;
  os << "\n";

  os << "Location :";
  os << h._city;
  os << "\n";

  os << "Total number of rooms :";
  os << h._roomNumber;
  os << "\n";

  os << "----------------------";
  os << "\n"; 
}