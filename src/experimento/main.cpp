#include "../../include/experimento/exp.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main(void) {

  int celdas, claves, fDisp, fExp, nprueb;
  float carga;

  cout << "Estudio de rendimiento de Tabla Hash \n\n";
  cout << "Introduzca los parámetros de la tabla:\n";
  cout << "  - Celdas: "; cin >> celdas;
  cout << "  - Claves: "; cin >> claves;
  cout << "  - Seleccione la función de Dispersión: \n";
  cout << "       1. Módulo\n"
       << "       2. Suma\n"
       << "       3. Pseualeatoria\n"; cin >> fDisp;
  cout << "  - Seleccione la función de Exploración: \n";
  cout << "       1. Lineal\n"
       << "       2. Cuadrática\n"
       << "       3. Dispersión doble\n"
       << "       4. Redispersión\n"; cin >> fExp;

  cout << "\n\n Introduzca los parámetros del fExperimento:\n";
  cout << "  - Número de pruebas: "; cin >> nprueb;
  cout << "  - Factor de carga: "; cin >> carga;
  cout << endl << endl;

  Tabla<DNI> myT(celdas,claves,fDisp,fExp);
  exp myExp(carga, nprueb, &myT);
  myExp.run();

  return 0;
}
