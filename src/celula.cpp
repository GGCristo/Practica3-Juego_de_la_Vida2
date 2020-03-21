
#include "../include/celula.h"

Celula::Celula ()
{
  Estado_ = false;
  i_ = 0;
  j_ = 0;
  vecinos_ = 0;
  tipo_ = 0;
}

Celula::Celula(unsigned int i, unsigned int j, unsigned int tipo)
{
  Estado_ = false;
  i_ = i;
  j_ = j;
  tipo_ = tipo;
}

Celula::Celula(const Celula& celula2)
{
  Estado_ = celula2.Estado_;
  i_ = celula2.i_;
  j_ = celula2.j_;
  vecinos_ = celula2.vecinos_;
  tipo_ = celula2.tipo_;
}

Celula* Celula::createCelula(unsigned int tipo_, unsigned int i_, unsigned int j_)
{
  switch(tipo_)
  {
    case 0:
      return new Celula(i_, j_, 0);
    case 1:
      return new Celula1::Celula(i_, j_, 1);
    case 2:
      return new Celula2::Celula(i_, j_, 2);
    case 3:
      return new Celula3::Celula(i_, j_, 3);
    default:
      std::cout << "Se pasó un tipo de celula no programada" << "\n";
      std::cout << tipo_ << "\n";
      std::cout << "Se ha creado una Celula base en su lugar" << "\n";
      return new Celula(i_, j_);
  }
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

void Celula::contarVecinas(const Tablero& Tablero_)
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

int Celula::actualizarEstado()
{
  if (vecinos_ == 3 || (Estado_ && vecinos_ == 2 ))
    Estado_ = true;
  else 
    Estado_ = false;
}

std::ostream& Celula::mostrar(std::ostream& os) const
{
  if (Estado_ == true)
    os << "x";
  else
    os << " ";
  return os;
}

std::ostream& operator << (std::ostream& os, const Celula& celula)
{
  celula.mostrar(os);
  return os;
}
