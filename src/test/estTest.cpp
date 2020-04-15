/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Testeo de la clase estadística
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
