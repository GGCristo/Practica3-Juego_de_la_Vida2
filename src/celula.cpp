
#include "../include/celula.h"

Celula::Celula ()
{
  i_ = 0;
  j_ = 0;
  vecinos_ = 0;
  tipo_ = 0;
}

Celula::Celula(unsigned int i, unsigned int j, unsigned int tipo)
{
  i_ = i;
  j_ = j;
  tipo_ = tipo;
}

Celula::Celula(const Celula& celula2)
{
  i_ = celula2.i_;
  j_ = celula2.j_;
  vecinos_ = celula2.vecinos_;
  tipo_ = celula2.tipo_;
}

Celula* Celula::createCelula(unsigned int tipo, unsigned int i_, unsigned int j_)
{
  switch(tipo)
  {
    case 0:
      return new Celula(i_, j_);
    case 1:
      return new Celula1(i_, j_, 1);
    case 2:
      return new Celula2(i_, j_, 2);
    case 3:
      return new Celula3(i_, j_, 3);
    default:
      std::cout << "Se pasó un tipo de celula no programada" << "\n";
      std::cout << tipo << "\n";
      std::cout << "Se ha creado una Celula base en su lugar" << "\n";
      return new Celula(i_, j_);
  }
}

Celula::~Celula()
{
}

unsigned int Celula::get_vecinos() const
{
  return vecinos_;
}

void Celula::contarVecinas(const Tablero& Tablero_)
{
  vecinos_ = 0;
  if (Tablero_.get_celula(i_ - 1, j_).get_tipo() != 0)
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_, j_ - 1).get_tipo() != 0)
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_, j_ + 1).get_tipo() != 0)
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_ + 1,  j_).get_tipo() != 0)
  {
    vecinos_++; 
  }
}

int Celula::actualizarEstado()
{
  if (vecinos_ == 3)
    return 1;
  else if (vecinos_ == 6 || vecinos_ == 8) 
    return 2;
  else if (vecinos_ == 4)
    return 3;
  else 
    return 0;
}

int Celula1::actualizarEstado()
{
  if (vecinos_ == 2 || vecinos_ == 3)
    return 1;
  else 
    return 0;
}

int Celula2::actualizarEstado()
{
  if (vecinos_ == 2 || vecinos_ == 4 || vecinos_ == 5)
    return 2;
  else 
    return 0;
}

int Celula3::actualizarEstado()
{
  if (vecinos_ == 5 || vecinos_ == 1)
    return 3;
  else 
    return 0;
}

std::ostream& Celula::mostrar(std::ostream& os) const
{
  os << " ";
  return os;
}

std::ostream& Celula1::mostrar(std::ostream& os) const
{
  os << "1";
  return os;
}

std::ostream& Celula2::mostrar(std::ostream& os) const
{
  os << "2";
  return os;
}

std::ostream& Celula3::mostrar(std::ostream& os) const
{
  os << "3";
  return os;
}

std::ostream& operator << (std::ostream& os, const Celula* celula)
{
  celula -> mostrar(os);
  return os;
}
