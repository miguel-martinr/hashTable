#pragma once

#include <iostream>

template <class Clave>
class fExploracionBase {
 public:
   virtual int operator()(const Clave&, int i) = 0;
   virtual std::ostream& print(std::ostream& os = std::cout) = 0;
};
