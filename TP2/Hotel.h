#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hotel {
private:
  std::string _name, _id, _city;
  std::vector<int> _rooms;

public:
  Hotel(std::string name, std::string city);
  std::string getID();
};