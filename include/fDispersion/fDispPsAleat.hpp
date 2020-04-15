#pragma once
#include "fDispersionBase.hpp"

#include <cstdlib>
#include <iostream>
using namespace std;

template <class Clave>
class fDispPsAleat : public fDispersionBase<Clave> {
 public:
   fDispPsAleat(int size) : size_(size) {}
   ~fDispPsAleat(void) {}

   int operator()(const Clave& x) {
     int seed = static_cast<int>(x);
//     cout << "\nSEED: " << seed << endl;
     srand(seed);
     return rand() % size_;
   }
   std::ostream& print(std::ostream& os) {
     os << "Pseudoaleatoria";
     return os;
   }

 private:
   int size_;
};
