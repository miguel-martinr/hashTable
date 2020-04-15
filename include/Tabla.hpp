#pragma once
#include "Celda.hpp"
#include "fDispersion/fDispersion.hpp"
#include "fExploracion/fExploracion.hpp"

#include <memory>
#include <iostream>
using namespace std;
template <class Clave>
class Tabla {

 public:
   Tabla(int nCeldas, int nClaves, int dispId, int expId);
   ~Tabla(void){}

   bool Buscar(Clave x);
   bool Insertar(Clave x);

   int setDisp(int dispId);
   int setExp(int expId);

   int get_nCeldas(void) { return vCelda_.size(); }
   int get_nClaves(void) { return nClaves_; }


   fDispersionBase<Clave>* fDisp;
   fExploracionBase<Clave>* fExp;
 private:
   std::vector<Celda<Clave>*> vCelda_;
   int nClaves_;

};

template <class Clave>
Tabla<Clave>::Tabla(int nCeldas, int nClaves, int dispId, int expId) {
  vCelda_.resize(nCeldas);
  nClaves_ = nClaves;
  for (int i = 0; i < nCeldas; i++)
    vCelda_[i] = new Celda<Clave>(nClaves_);
  setDisp(dispId);
  setExp(expId);

}

template <class Clave>
bool Tabla<Clave>::Buscar(Clave x) {
  int position = (*fDisp)(x);
  bool found = vCelda_[position]->Buscar(x);
  int i = 0;
  while (!found && (i < get_nCeldas())) {
    i++;
    int desp = (*fExp)(x, i);
    if (desp + position >= get_nCeldas())
      position = (position + desp) % get_nCeldas();
    else
      position += desp;
    // La siguiente condición (!vCelda..->estaLlena()) es válida siempre
    // que no se puedan remover elementos de la tabla ¿
    found = vCelda_[position]->Buscar(x) || !vCelda_[position]->estaLlena();
  }
  return found;
}

template <class Clave>
bool Tabla<Clave>::Insertar(Clave x) {
  int position = (*fDisp)(x);
  bool done = vCelda_[position]->Buscar(x);
  if (!done) {
    int i =0;
    while (!done && i < get_nCeldas()) {
      i++;
      int desp = (*fExp)(x,i);
      if (position + desp >= get_nCeldas())
        position = (position + desp) % get_nCeldas();
      else
        position += desp;
      done = vCelda_[position]->Insertar(x);
    }
    return done;
  }
}



template <class Clave>
int Tabla<Clave>::setDisp(int dispId) {
  switch (dispId) {
    case 1:
      fDisp = new fDispModulo<Clave>(get_nCeldas());
      break;
    case 2:
      fDisp = new fDispSuma<Clave>(get_nCeldas());
      break;
    case 3:
      fDisp = new fDispPsAleat<Clave>(get_nCeldas());
      break;

    default:
      return -1;
  }
  return 0;
}

template <class Clave>
int Tabla<Clave>::setExp(int expId) {
  switch (expId) {
//    case 1:
//      fExp = new fExpLineal<Clave>(nClaves_);
//      break;
    case 2:
      fExp = new fExpCuad<Clave>(nClaves_);
      break;
    case 3:
      fExp = new fExpDispDoble<Clave>(nClaves_);
      break;
    case 4:
      fExp = new fExpReDisp<Clave>(nClaves_);
      break;

    default:
      fExp = new fExpLineal<Clave>(nClaves_);
      break;
  }
  return 0;
}
