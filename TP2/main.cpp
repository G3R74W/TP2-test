#include "Hotel.h"
#include "Client.h"

int main() {
  Hotel h("test", "City", 10);
  std::string idHotel = h.getID();
  
	return 0;
}