/**********************************************************************
* Project           : Hash table implementation
*
* Class             : DNI
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

#include <cstdlib>
#include <ctime>

class DNI {
 public:

   DNI(void);
   DNI(unsigned long num);
   ~DNI(void) {}

   static unsigned long cmpCount_;


   unsigned long getNum(void) const { return num_; }
   void setNum(unsigned long num) { num_ = num; }

   void operator=(const DNI& A);
   bool operator==(const DNI& A);
   bool operator<(const DNI& A);
   bool operator>(const DNI& A);

   operator unsigned long() const {
     return getNum();
   }


 private:
   unsigned long num_;
};
