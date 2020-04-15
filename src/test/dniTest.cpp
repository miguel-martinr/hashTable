/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Testeo de la clase DNI
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
