#include "../../include/experimento/Estadistica.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

  cout << "Test Estadística" << endl << endl;
  Estadistica myE;


  int comps = 0;
  int busquedas = 10000;
  int maxCmp = 20;
  int min = 0;
  int max = 0;

  for (int i = 0; i < busquedas; i++) {
    srand(time(NULL));
    comps = rand() % maxCmp+1;
    myE.update(comps);
    usleep(500);
    min == 0 || comps < min ? min = comps : true;
    comps > max ? max = comps : true;
    comps = 0;
  }


  myE.print(cout, "Prueba");
  cout << " " << min << "  " << max << endl;
  return 0;
}
