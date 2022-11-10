// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-fa.cc: Clase que representa un autómata finito.
// Esta clase representa un autómata finito, con sus estados, alfabeto, 
// estado inicial, estados de aceptación y transiciones, así como sus funciones desarrolladas.  
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#include "fa.h"

Dfa::Dfa(std::ifstream& Filein) {
  State actual;
  int rep = 0;
  std::string line, name, aux;
  Filein >> states_size_;
  Filein >> first_;
  while (getline(Filein, line)) {
    if (rep != 0) {
      actual.SetState(line);
      states_.push_back(actual);
      actual.clear();
    }
    rep++;
  }
  aux = line.at(2);
  rep = stoi(aux);
  for (int i = 3; i < rep * 2 + 2; i++) {
    aux  = line.at(i);
    alphabet_.SetSymbol(aux);
    i++;
  }
}

bool Dfa::IsAlphabet(std::string chain) {
  bool aux = false;
  std::string character;
  for (unsigned i = 0; i < chain.size(); i++) {
    aux = false;
    for (unsigned j = 0; j < alphabet_.GetSSize(); j++) {
      character = chain.at(i);
      if (character == alphabet_.GetWord(j).GetSymbol()) {
        aux = true;
      } 
    }
    if (!aux) {
      return false;
    }
  }
  return true;
}


bool Dfa::Read(std::string line) {
  if (line.at(0) == '&') {
    return states_.at(first_).IsAceptation();
  }
  if(!IsAlphabet(line)) {
    return false;
  }
  State actual = states_.at(first_);
  Transition next;
  std::string aux;
  for (unsigned i = 0; i < line.size(); i++) {
    aux = line.at(i);
    next = actual.GetTransition(aux);
    actual = states_.at(next.GetPos());
  }
  return actual.IsAceptation();
}