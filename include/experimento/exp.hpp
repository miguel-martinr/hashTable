/**********************************************************************
* Project           : Hash table implementation
*
* Class             : Experimento
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
#pragma once
#include "Estadistica.hpp"
#include "../DNI.hpp"
#include "../Tabla.hpp"

#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class exp {
 public:
   exp(float loadF, int nPruebas, Tabla<DNI>* hashTable);
   ~exp(void) { delete testRepo_; }

   int resizeRepo(void);
   int initRepo(void);
   int loadTab(void);
   int run(ostream& os = cout);

   int search(void);
   int insert(void);

   ostream& print(ostream& os = cout);

   float get_loadF(void) { return loadF_; }

   Estadistica srch_;
   Estadistica insrt_;


 private:
   float loadF_;
   int nPruebas_;
   vector<DNI>* testRepo_;
   Tabla<DNI>* hashTable_;

};


int exp::run(ostream& os) {
  search();
  insert();
  print(os);
  return 0;
}


int exp::insert(void) {
  insrt_.reset();
  for (int i = 0; i < nPruebas_; i++) {
    DNI::cmpCount_ = 0;
    int mid = testRepo_->size()/2;
    hashTable_->Buscar((*testRepo_)[(i % mid) + mid]); //Posiciones en el rango [mid, size()-1]
    insrt_.update(DNI::cmpCount_);
  }
  return 0;
}


int exp::search(void) {
  srch_.reset();
  for (int i = 0; i < nPruebas_; i++) {
    DNI::cmpCount_ = 0;
    hashTable_->Buscar((*testRepo_)[i % (testRepo_->size()/2)+1]);
    srch_.update(DNI::cmpCount_);
  }
  return 0;
}

exp::exp(float loadF, int nPruebas, Tabla<DNI>* hashTable) {  nPruebas_ = nPruebas;
  assert((loadF >= 0 && loadF <= 1) && "Factor de carga no permitido!");
  nPruebas_ = nPruebas;
  loadF_ = loadF;
  hashTable_ = hashTable;
  resizeRepo();
  initRepo();
  loadTab();
}

int exp::loadTab(void) {
  DNI::cmpCount_ = 0;
  for (int i = 0; i < testRepo_->size()/2; i++)
    hashTable_->Insertar((*testRepo_)[i]);

  return 0;
}


int exp::initRepo(void) {
  if (testRepo_->size() == 0)
    return 0;
  srand(time(NULL));
  (*testRepo_)[0] = DNI(rand() % 100000000);
  for (int i = 1; i < testRepo_->size(); i++) {
    srand((*testRepo_)[i-1]);
    (*testRepo_)[i] = DNI(rand() % 100000000);
  }
  return 0;
}



int exp::resizeRepo(void) {
  int sizeRepo = 2*(loadF_*hashTable_->get_nCeldas()*hashTable_->get_nClaves());
  testRepo_ = new vector<DNI>((int)(sizeRepo));
  return 0;
}


ostream& exp::print(ostream& os) {
  string dispName, expName;
  stringstream names;
  hashTable_->fDisp->print(names);
  names << "  ";
  hashTable_->fExp->print(names);
  names >> dispName >> expName;

  os << "Celdas     nClaves     Dispersión      Exploración   Carga   Pruebas"
     << endl;

  os << setw(11) << left
     << hashTable_->get_nCeldas()
     << setw(12) << left
     << hashTable_->get_nClaves()
     << setw(17) << left
     << dispName
     << setw(14) << left
     << expName
     << setw(14) << left
     << loadF_
     << setw(8) << left
     << nPruebas_ << endl << endl;

  os << "               Mínimo    Medio     Máximo" << endl;
  os << ' ';
  srch_.print(os, "Búsquedas");
  cout << endl;
  insrt_.print(os, "Inserciones");
  cout << endl;
  return os;
}
