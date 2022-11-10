#pragma once
// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-fa.h: Clase que representa un autómata finito.
// Esta clase representa un autómata finito, con sus estados, alfabeto, 
// estado inicial, estados de aceptación y transiciones, y deminimos sus funciones.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#include <iostream>
#include <vector>
#include <fstream>

#include "state.h"
#include "Alfabeto.h"

class Dfa {
  public:
    Dfa(std::ifstream&);

    bool Read(std::string);
    bool IsAlphabet(std::string);

  private:
    int states_size_;
    int first_;
    std::vector<State> states_;
    Alfabeto alphabet_;
};