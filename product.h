#pragma once

#include "headers.h"

using namespace std;

struct Product {
  string _name;
  string _description;
  double _price;

  static bool CompareByPrice(const Product& a, const Product& b) {
    return a._price < b._price;
  }
};

ostream& operator<<(ostream& sm, const Product& p); // For cout << product
