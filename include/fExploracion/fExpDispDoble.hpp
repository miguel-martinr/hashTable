#pragma once
#include "fExploracionBase.hpp"
#include "../fDispersion/fDispPsAleat.hpp"

template <class Clave>
class fExpDispDoble : public fExploracionBase<Clave> {
 public:
   fExpDispDoble(int size) : size_(size) {}
   ~fExpDispDoble(void) {}

   int operator()(const Clave& x, int i) {
     fDispersionBase<Clave>* ptr = new fDispPsAleat<Clave>(size_);
     return i * (*ptr)(x);
   }
   std::ostream& print(std::ostream& os = std::cout) {
     os << "Disp.Doble";
     return os;
   }
 private:
   int size_;
};
