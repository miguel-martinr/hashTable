#include "../../include/experimento/exp.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int help(string path) {
  ifstream instFile(path, ios::in);
  if (!instFile.is_open()) {
    cout << endl << "Error al cargar instrucciones!" << endl;
    return 1;
  }
  cout << instFile.rdbuf() << endl;
  return 0;
}


int main(int argc, char* argv[]) {

  int celdas, claves, fDisp, fExp, nprueb;
  float carga;

  if (argc > 1) {
    string h = "-help", h2 = "-h", h3 = "--help";
    if (argv[1] == h || argv[1] == h2 || argv[1] == h3)
      return help("doc/help.txt");
  }

  if (argc == 7) {
    celdas = stoi(argv[1]);
    claves = stoi(argv[2]);
    fDisp = stoi(argv[3]);
    fExp = stoi(argv[4]);
    nprueb = stoi(argv[5]);
    carga = stof(argv[6]);
  } else {
    cout << "Estudio de rendimiento de Tabla Hash \n\n";
    cout << "Introduzca los parámetros de la tabla:\n";
    cout << "  - Celdas: "; cin >> celdas;
    cout << "  - Claves: "; cin >> claves;
    cout << "  - Seleccione la función de Dispersión: \n";
    cout << "       1. Módulo\n"
         << "       2. Suma\n"
         << "       3. Pseudoaleatoria\n"; cin >> fDisp;
    cout << "  - Seleccione la función de Exploración: \n";
    cout << "       1. Lineal\n"
         << "       2. Cuadrática\n"
         << "       3. Dispersión doble\n"
         << "       4. Redispersión\n"; cin >> fExp;

    cout << "\n\n Introduzca los parámetros del fExperimento:\n";
    cout << "  - Número de pruebas: "; cin >> nprueb;
    cout << "  - Factor de carga: "; cin >> carga;
    cout << endl << endl;
  }

  Tabla<DNI> myT(celdas,claves,fDisp,fExp);
  exp myExp(carga, nprueb, &myT);
  myExp.run();

  return 0;
}
