#include "../../include/DNI.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {

  cout << "Test DNI" << endl << endl;

  DNI* ptr;
  for (int i = 0; i < 5; i++) {
    ptr = new DNI();
    cout <<  "DNI [" << i << "]: " << ptr->getNum() << endl;
    usleep(800000);
  }

  return 0;
}
