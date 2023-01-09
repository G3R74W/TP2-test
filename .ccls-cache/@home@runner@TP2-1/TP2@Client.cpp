#include "Client.h"

Client::Client(std::string lastname, std::string firstname) :_lastname(lastname), _firstname(firstname) {
	_id_client = firstname[0]+lastname;
}
std::string Client::get_id_client() {
	return _id_client;
}

std::string Client::get_lastname() {
	return _lastname;
}

std::ostream& operator<<(std::ostream& os, const Client& c){
  os << "----------------------";
  os << "\n";

  os << "Client's last name :";
  os << c._lastname;
  os << "\n";

  os << "Client's first name :";
  os << c._firstname;
  os << "\n";

  os << "Client's ID :";
  os << c._id_client;
  os << "\n";
  
  os << "----------------------";
  os << "\n";
  return os;
}