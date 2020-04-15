#pragma once
#include "fDispersionBase.hpp"


template <class Clave>
class fDispSuma : public fDispersionBase<Clave> {
 public:
   fDispSuma(int size): size_(size) {}
   ~fDispSuma(void) {}

   int operator()(const Clave& x);
   std::ostream& print(std::ostream& os) {
     os << "Suma";
     return os;
   }
 private:
   int size_;
};

template <class Clave>
int fDispSuma<Clave>::operator()(const Clave& x) {
  int d = 0, v = x, y;
  while (v > 0) {
    y = v % 10;
    d += y;
    v = v / 10;
  }
  return (d % size_);
}
