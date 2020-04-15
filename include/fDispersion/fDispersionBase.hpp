#pragma once

#include <iostream>

template <class Clave>
class fDispersionBase {
 public:

   virtual int operator()(const Clave& x) = 0;
   virtual std::ostream& print(std::ostream& os) = 0;
};
