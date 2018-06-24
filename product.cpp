#include "headers.h"
#include "product.h"

// For cout << product
ostream& operator<<(ostream& sm, const Product& p) {
  const size_t MAX_DESCIPTION_LEN = 50;
  sm << "Name: " << p._name << endl;
  if (p._description.length() > MAX_DESCIPTION_LEN) {
    sm << "Description: " << p._description.substr(0, MAX_DESCIPTION_LEN - 1) << "..." << endl;
  } else {
    sm << "Description: " << p._description << endl;
  }
  sm << "Price: " << p._price << endl;
  return sm;
}
