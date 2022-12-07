#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Bedroom.h"

class Hotel {
private:
  std::string _name, _idHotel, _city;
  int _roomNumber; //number of rooms in the Hotel
  std::vector<Bedroom> _rooms;

public:
  Hotel(std::string name, std::string city, std::string roomNumber);
  std::string getID();
  void create_room(std::string type);
  void delete_room(int number);
  int get_roomNumber();
  void display_info_bedroom();
  friend std::ostream& operator<<(std::ostream &os, const Hotel &h);
};