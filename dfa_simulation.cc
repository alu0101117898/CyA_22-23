// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-fa_simulation.cc: Programa cliente.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código

#include <iostream>
#include <fstream>
#include <cstring>


#include "fa.h"
#include "state.h"

int main(int argc, char* argv[]) {
  if (argc == 2){
    if (std::strncmp(argv[1], "--help", 7) == 0) {
      std::cout << "Para la ejecuion de este programa, se necesitan 2 parametros:" << std::endl;
      std::cout << std::endl;
      std::cout << "1.-   Un fichero en el que esté contenido el fa, ";
      std::cout << "por ejemplo: example.fa"  << std::endl;
      std::cout << "2.-   Un fichero de entrada que  contendra las cadenas";
      std::cout << " a probar en el fa, por ejemplo: input.txt";
      std::cout << std::endl;
      std::cout << "La ejecucion debera ser algo como: ";
      std::cout << "./" << argv[0] << " example.dfa input.txt";
      std::cout << std::endl;
      return 0;
    }
  }
  if (argc != 4) {
    std::cout << "Parametros erroneos, para mas ayuda pruebe la opcion '--help'";
    std::cout << std::endl;
    return -1;
  }
  std::string chain;
  std::ifstream Dfain;
  std::ifstream Filein;

  Dfain.open(argv[1], std::ios::in);
  if (Dfain.fail()) {
    std::cout << "fallo al abrir " << argv[1] << std::endl;
    return -1;
  }
  Dfa dfa(Dfain);
  Filein.open(argv[2], std::ios::in);
  if (Filein.fail()) {
    std::cout << "fallo al abrir " << argv[2] << std::endl;
    return -1;
  }
  do {
    //getline(Filein, chain);
    Filein >> chain;
    std::cout << chain;
    if (dfa.Read(chain)) {
      std::cout << chain << " -- Accepted" << std::endl;
    } else {
      std::cout << chain << " -- Rejected" << std::endl;
    }
    chain.clear();
  } while (!Filein.eof());
  Dfain.close();
  Filein.close();
}