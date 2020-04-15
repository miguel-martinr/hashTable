#pragma once
#include <vector>


template <class Clave>
class Celda {
 public:
   Celda(int nClaves, int emptyVal = 0);
   ~Celda(void) {};

   bool Buscar(Clave x);
   bool Insertar(Clave x);


   bool estaLlena(void);
   bool estaVacia(void);
   int nClaves(void) { return vClaves_.size(); }

 private:
   std::vector<Clave> vClaves_;
   int occu_;
};

template <class Clave>
Celda<Clave>::Celda(int nClaves, int emptyVal){ //emptyVal es el valor que contienen las celdas vacías
  vClaves_ = std::vector<Clave>(nClaves, emptyVal);
  occu_ = 0;
}

template <class Clave>
bool Celda<Clave>::Buscar(Clave x) {
  for (int i = 0; i < occu_; i++)
    if (vClaves_[i] == x)
      return true;

  return false;
}

template <class Clave>
bool Celda<Clave>::Insertar(Clave x) {
  if (estaLlena() || Buscar(x))
    return false;
  vClaves_[occu_] = x;
  occu_++;
  return true;
}

template <class Clave>
bool Celda<Clave>::estaLlena(void) {
  return occu_ == nClaves();
}

template <class Clave>
bool Celda<Clave>::estaVacia(void) {
  return occu_ == 0;
}
