#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hotel {
private:
  std::string _name, _idHotel, _city;
  int _roomNumber; //number of rooms in the Hotel
  std::vector<int> _rooms;

public:
  Hotel(std::string name, std::string city, std::string roomNumber);
  std::string getID();
  int room(std::string type);
  void create_room();
  void delete_room();
  int get_roomNumber();

};