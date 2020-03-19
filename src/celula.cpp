
#include "../include/celula.h"

Celula::Celula ()
{
  Estado_ = false;
  i_ = 0;
  j_ = 0;
  vecinos_ = 0;
}

Celula::Celula(unsigned int i, unsigned int j)
{
  Estado_ = false;
  i_ = i;
  j_ = j;
}

Celula::Celula(const Celula& celula2)
{
  Estado_ = celula2.Estado_;
  i_ = celula2.i_;
  j_ = celula2.j_;
  vecinos_ = celula2.vecinos_;
}

Celula::~Celula()
{
}

bool Celula::get_Estado() const
{
  return Estado_;
}

unsigned int Celula::get_vecinos() const
{
  return vecinos_;
}

void Celula::set_Estado(bool valor)
{
  Estado_ = valor;
}

void Celula::guardar_vecinos(const Tablero& Tablero_)
{
  vecinos_ = 0;
  if (Tablero_.get_celula(i_ - 1, j_ - 1).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_ - 1, j_).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_ - 1, j_+ 1).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_, j_ - 1).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_, j_ + 1).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_+ 1, j_- 1).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_ + 1,  j_).get_Estado())
  {
    vecinos_++; 
  }
  if (Tablero_.get_celula(i_ + 1, j_ + 1).get_Estado())
  {
    vecinos_++; 
  }
}

void Celula::actualizar()
{
  if ((!Estado_ && vecinos_ == 3) || (Estado_ && (vecinos_ == 2 || vecinos_ == 3)))
    Estado_ = true;
  else 
    Estado_ = false;
}

std::ostream& Celula::write(std::ostream& os) const
{
  if (Estado_ == true)
    os << "x";
  else
    os << " ";
  return os;
}

std::ostream& operator << (std::ostream& os, const Celula& celula)
{
  celula.write(os);
  return os;
}