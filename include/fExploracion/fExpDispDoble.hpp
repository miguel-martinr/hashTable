/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de exploración Dispersión Doble
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200415
*
* References  :
*    https://campusvirtual.ull.es/1920/pluginfile.php/209080/mod_resource/content/10/AEDA-pract04.pdf
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200415    miguel-martinr      1      ...
*
**********************************************************************/
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
