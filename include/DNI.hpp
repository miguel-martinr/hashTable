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
