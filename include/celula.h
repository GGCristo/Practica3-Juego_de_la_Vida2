// #pragma once
#ifndef Celul
#define Celul
#include <iostream>
#include <cassert>
#include "tablero.h"
class Tablero;
class Celula {
protected:
  unsigned int i_;
  unsigned int j_;
  unsigned int vecinos_;
  unsigned int tipo_;
public:
  Celula();
  Celula(unsigned int, unsigned int, unsigned int = 0);
  Celula(const Celula&);
  ~Celula();
  unsigned int get_vecinos() const;
  void set_i (int pos) {i_ = pos;}
  void set_j (int pos) {j_ = pos;}
  void set_tipo (unsigned int tipo) {tipo_ = tipo;}
  unsigned int get_tipo() {return tipo_;}
  static Celula* createCelula (unsigned int, unsigned int, unsigned int);
  virtual void contarVecinas(const Tablero&);
  virtual int actualizarEstado(); // Reglas de nacimiento
  virtual std::ostream& mostrar(std::ostream&) const;
  
};

class Celula1: public Celula {
  public:
    Celula1(unsigned int i_, unsigned int j_, unsigned int tipo = 0): Celula(i_, j_, tipo) {}
    int actualizarEstado();  //Reglas de nacimiento;
    std::ostream& mostrar(std::ostream&) const;
};

class Celula2: public Celula {
  public:
    Celula2(unsigned int i_, unsigned int j_, unsigned int tipo = 0): Celula(i_,j_, tipo) {}
    int actualizarEstado();  //Reglas de nacimiento
    std::ostream& mostrar(std::ostream&) const;
};

class Celula3: public Celula {
  public:
    Celula3(unsigned int i_, unsigned int j_, unsigned int tipo = 0): Celula(i_,j_, tipo) {}
    int actualizarEstado(); //Reglas de nacimiento
    std::ostream& mostrar(std::ostream&) const;
};

std::ostream& operator << (std::ostream&, const Celula*);
#endif
