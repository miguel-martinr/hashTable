/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Función de exploración - Pure abstract
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

#include <iostream>

template <class Clave>
class fExploracionBase {
 public:
   virtual int operator()(const Clave&, int i) = 0;
   virtual std::ostream& print(std::ostream& os = std::cout) = 0;
};
