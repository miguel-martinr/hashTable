#pragma once
#include "fExploracionBase.hpp"


template <class Clave>
class fExpCuad : public fExploracionBase<Clave> {
 public:
   fExpCuad(int size) : size_(size) {}
   ~fExpCuad(void) {}

   int operator()(const Clave& x, int i) { return i*i; }
   std::ostream& print(std::ostream& os = std::cout) {
     os << "Cuadrática";
     return os;
   }
 private:
   int size_;
};
