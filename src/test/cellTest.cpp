/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Testeo de la clase celda
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
#include "../../include/Celda.hpp"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

  cout << "Test Celda" << endl << endl;
  Celda<int> myC(5);
  myC.Insertar(3);
  myC.Insertar(4);
  myC.Insertar(3);
  int id;
  cout << "asd";
  return 0;
}
