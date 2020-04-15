/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Testeo de la clasa Tabla
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
#include "../../include/Tabla.hpp"
#include "../../include/DNI.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main(void) {

  cout << "Test Tabla" << endl << endl;
  Tabla<DNI> myT(5, 3, 3, 1);
  vector<DNI> myV = {DNI(90056591), DNI(30208151), DNI(11176526), DNI(51776891)};

  for (unsigned int i = 0; i < myV.size(); i++) {
    cout << "dni: " << myV[i].getNum() << endl;
    cout << "mod: " << myV[i].getNum() % 5 << endl;
    cout << "insertar: " << (myT.Insertar(myV[i]) ? "si" : "no") << endl;
    cout << "busqueda: " << (myT.Buscar(myV[i]) ? "si" : "no") << endl;
  }

  cout << "stop";
  return 0;
}
