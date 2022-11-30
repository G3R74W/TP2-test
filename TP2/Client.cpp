#include "Client.h"

Client::Client(std::string lastname, std::string firstname) :_lastname(lastname), _firstname(firstname) {
	_id_client = firstname[0]+lastname;
}
std::string Client::get_id_client() {
	return _id_client;
}