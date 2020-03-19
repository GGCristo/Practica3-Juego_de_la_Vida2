#include <array>
#include "../include/tablero.h"

Tablero::Tablero(unsigned int n, unsigned int m)
{
  n_ = n - 2;
  m_ = m - 2;
  Tablero_ = new Celula*[n];
  for (int i = 0; i < n; i++)
  {
    Tablero_[i] = new Celula[m];
    for (int j = 0; j < m; j++)
    {
      Tablero_[i][j].set_i(i);
      Tablero_[i][j].set_j(j);
    }
  }
}
Tablero::Tablero(const Tablero& oTablero)
{
  this -> destruir_tablero();
  n_ = oTablero.n_;
  m_ = oTablero.m_;
  Tablero_ = new Celula*[n_ + 2];
  for (int i = 0; i < n_ + 2; i++)
  {
    Tablero_[i] = new Celula[m_ + 2];
    for (int j = 0; j < m_ + 2; j++)
    {
      Tablero_[i][j].set_i(i);
      Tablero_[i][j].set_j(j);
      Tablero_[i][j].set_Estado(oTablero.Tablero_[i][j].get_Estado());
    }
  }
}

unsigned int Tablero::get_n()
{
  return n_;
}

unsigned int Tablero::get_m()
{
  return m_;
}

Celula** Tablero::get_tablero()
 {
   return Tablero_;
 }

Celula** Tablero::get_tablero() const
{
  return Tablero_;
}

void Tablero::actualizar()
{
  for (int i = 1; i <= n_; i++)
  {
    for (int j = 1; j <= m_ ; j++)
    {
      Tablero_[i][j].guardar_vecinos(*this);
    }
  }

  for (int i = 1; i <= n_; i++)
  {
    for (int j = 1; j <= m_ ; j++)
    {
      Tablero_[i][j].actualizar ();
    }
  }
}

Celula& Tablero::get_celula (unsigned int n, unsigned int m)
{
  return Tablero_[n][m];
}

Celula& Tablero::get_celula (unsigned int n, unsigned int m) const
{
  return Tablero_[n][m];
}

std::ostream& Tablero::write(std::ostream& os) const
{
  for (int k = 0; k < m_; k++)
  {
    os << " -";
  }
  os << "\n";

  for (int i = 1; i <= n_; i++)
  {
    for (int j = 1; j <= m_; j++)
    {
      os << "|" << Tablero_[i][j];
    }
    
    os << "|\n";
    
    for (int k = 0; k < m_; k++)
    {
      os << " -";
    }
    
    os << "\n";
  }
  os << "\n";
  return os;
}

void Tablero::destruir_tablero()
{
  for (int i = 0; i < n_ + 2; ++i)
    delete [] Tablero_[i];
  delete [] Tablero_;

  n_ = 0;
  m_ = 0;
}

std::ostream& operator << (std::ostream& os, const Tablero& tablero)
{
  tablero.write(os);
  return os;
}