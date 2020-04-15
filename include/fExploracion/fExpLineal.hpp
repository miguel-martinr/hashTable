/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de exploración Lineal
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
