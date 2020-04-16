/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de dispersión Suma2 (Modificación Sesión Práctica)
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200416
*
* References  :
*    https://campusvirtual.ull.es/1920/pluginfile.php/209080/mod_resource/content/10/AEDA-pract04.pdf
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200416    miguel-martinr      1      ...
*
**********************************************************************/
#pragma once
#include "fDispersionBase.hpp"

template <class Clave>
class FDSuma2 : public fDispersionBase<Clave> {
 public:
   FDSuma2(int size): size_(size) {}
   ~FDSuma2(void) {}

   int operator()(const Clave& x);
   std::ostream& print(std::ostream& os) {
     os << "Suma2";
     return os;
   }
 private:
   int size_;
};

template <class Clave>
int FDSuma2<Clave>::operator()(const Clave& x) {
  int d = 0, v = x, y;
  while (v > 0) {
    y = v % 100;
    d += y;
    v = v / 100;
  }
  return (d % size_);
}
