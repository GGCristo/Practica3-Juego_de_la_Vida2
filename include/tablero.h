// #pragma once
#ifndef Tab
#define Tab
#include <array>
#include "celula.h"
class Celula;
class Tablero {
  private:
    Celula** Tablero_;
    // Tamaño falso del tablero
    unsigned int n_;
    unsigned int m_;
  public:
    Tablero(unsigned int = 20, unsigned int = 20);
    Tablero(const Tablero&);
    unsigned int get_n();
    unsigned int get_m();
    Celula** get_tablero();
    Celula** get_tablero() const;
    void actualizar();
    Celula& get_celula (unsigned int, unsigned int);
    Celula& get_celula (unsigned int, unsigned int) const;
    std::ostream& write(std::ostream&) const;
    void destruir_tablero();
};
std::ostream& operator << (std::ostream&, const Tablero&);
#endif