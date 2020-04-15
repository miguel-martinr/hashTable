#pragma once
#include "fDispersionBase.hpp"

template <class Clave>
class fDispModulo : public fDispersionBase<Clave> {
 public:
   fDispModulo(int size) : size_(size) {}
   ~fDispModulo(void) {}

   int operator()(const Clave& x) { return x % size_; }
   std::ostream& print(std::ostream& os) {
     os << "Módulo";
     return os;
   }

 private:
   int size_;
};
