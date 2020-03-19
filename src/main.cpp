#include <iostream>
#include <cassert>
#include "../include/tablero.h"

void El_juego_de_la_vida(Tablero&, const unsigned int&);

int main (){
  
  std::cout << "Juego de la vida: " << std::endl;

  std::cout << "Numero de filas: " << "\n";
  unsigned int x;
  std::cin >> x;

  std::cout << "Numero de columnas: " << "\n";
  unsigned int y;
  std::cin >> y;

  std::cout << "¿Cuantas celulas vas a meter?" << "\n";
  unsigned int n_celulas;
  std::cin >> n_celulas;
  
  assert(x*y >= n_celulas);

  Tablero Tablero0(x + 2, y + 2);

  for (int i = 0; i < n_celulas; i++)
  {
    std::cout << "Celula número: " << i+1 << "\n";
    std::cout << "¿Valor de la fila?" << "\n";
    std::cin >> x;
    if (x < 1 || x > Tablero0.get_n())
    {
      i--;
      std::cout << "Eso esta fuera de los límites. Intentelo otra vez\n";
      continue;
    }
    std::cout << "¿Valor de la columna?" << "\n";
    std::cin >> y;
    if (y < 1 || y > Tablero0.get_m())
    {
      i--;
      std::cout << "Eso esta fuera de los límites. Intentelo otra vez\n";
      continue;
    }
    Tablero0.get_celula(x, y).set_Estado(true);
  }

  std::cout << "¿Numero de turnos?\n";
  unsigned int n_turnos;
  std::cin >> n_turnos;

  std::cout << "\nTurno 0: " << "\n";
  std::cout << Tablero0;

  El_juego_de_la_vida(Tablero0, n_turnos);

  Tablero0.destruir_tablero();
  return 0;
}

void El_juego_de_la_vida (Tablero& Tablero0, const unsigned int &n_turnos)
{
  for (int i = 0; i < n_turnos; i++)
  {
    Tablero0.actualizar();
    std::cout << "Turno " << i + 1 << ": " << "\n";
    std::cout << Tablero0;
  }
}