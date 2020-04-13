#pragma once

#include <cstdlib>
#include <ctime>

class DNI {
 public:

   DNI(void);
   ~DNI(void) {}


   int getNum(void) const { return num_; }
   void setNum(int num) { num_ = num; }

   void operator=(const DNI& A);
   bool operator==(const DNI& A);
   bool operator<(const DNI& A);
   bool operator>(const DNI& A);

   operator unsigned long(void) { return num_; }

 private:
   int num_;
};

DNI::DNI(void) {
    srand(time(NULL));
    num_ = rand() % 100000000;
}

void DNI::operator=(const DNI& A) {
  setNum(A.getNum());
}

bool DNI::operator==(const DNI& A) {
  return (getNum() == A.getNum());
}

bool DNI::operator<(const DNI& A) {
  return (getNum() < A.getNum());
}

bool DNI::operator>(const DNI& A) {
  return (getNum() > A.getNum());
}
