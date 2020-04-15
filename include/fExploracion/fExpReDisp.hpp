#pragma once
#include "fExploracionBase.hpp"

#include <cstdlib>

template <class Clave>
class fExpReDisp : public fExploracionBase<Clave> {
 public:
   fExpReDisp(int size) : size_(size) {}
   ~fExpReDisp(void) {}

   int operator()(const Clave& x, int i) {
     int seed = static_cast<int>(x);
     srand(seed);
     for (int j = 0; j < i-1; j++)
       rand();
     return rand() % size_; // Es necesario el mod?
   }
   std::ostream& print(std::ostream& os = std::cout) {
     os << "Redisp";
     return os;
   }

 private:
   int size_;
};
