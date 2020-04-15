/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de dispersión Módulo
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
