/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de exploración Redispersión
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
