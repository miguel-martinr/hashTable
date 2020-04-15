#pragma once
#include "fExploracionBase.hpp"


template <class Clave>
class fExpLineal : public fExploracionBase<Clave> {
 public:
   fExpLineal(int size) : size_(size) {}
   ~fExpLineal(void) {}

   int operator()(const Clave& x, int i) { return i; }
   std::ostream& print(std::ostream& os = std::cout) {
     os << "Lineal";
     return os;
   }
 private:
   int size_;
};
