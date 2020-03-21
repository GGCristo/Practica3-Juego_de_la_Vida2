// #pragma once
#ifndef Celul
#define Celul
#include <iostream>
#include "tablero.h"
class Tablero;
class Celula {
private:
  bool Estado_;
  unsigned int i_;
  unsigned int j_;
  unsigned int vecinos_;
public:
  Celula();
  Celula(unsigned int, unsigned int);
  Celula(const Celula&);
  ~Celula();
  bool get_Estado() const;
  unsigned int get_vecinos() const;
  void set_i (int pos) {i_ = pos;}
  void set_j (int pos) {j_ = pos;}
  void set_Estado(bool);
  static Celula* createCelula (int, int, int);
  virtual void contarVecinas(const Tablero&);
  virtual int actualizarEstado(); // Reglas de nacimiento
  virtual std::ostream& mostrar(std::ostream&) const;
  
};

class Celula1: public Celula {
  public:
    int actualizarEstado() {return 1;} //Reglas de nacimiento
    std::ostream& mostrar(std::ostream&) const;
};

class Celula2: public Celula {
  public:
    int actualizarEstado() {return 2;} //Reglas de nacimiento
    std::ostream& mostrar(std::ostream&) const;
};

class Celula3: public Celula {
  public:
    int actualizarEstado() {return 3;} //Reglas de nacimiento
    std::ostream& mostrar(std::ostream&) const;
};

std::ostream& operator << (std::ostream&, const Celula&);
#endif
