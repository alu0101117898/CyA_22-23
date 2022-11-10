// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-state.cc: Desarrpllo de las funciones de la clase State.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#include "state.h"

State::State() {
  aceptation_ = false;
  start_ = false;
}

State::State(bool a, int n) {
  std::string aux = "q";
  aceptation_ = a;
  start_ = false;
  name_ = aux + std::to_string(n);
}

void State::SetAceptation() {
  aceptation_ = true;
}

void State::SetStart() {
  start_ = true;
}

void State::SetName(std::string name) {
  name_ = name;
}

void State::SetState(std::string line) {
  std::string aux;
  Transition next;
  aux = line.at(0);
  name_ = "q"  + aux;
  if (line.at(1) == '0') {
    aceptation_ = false;
  } else {
    aceptation_ = true;
  }
  aux = line.at(2);
  trans_num_ = stoi(aux);
  for (int i = 3; i < line.size() - 1; i++) {
    aux = line.at(i);
    next.SetSymbol(aux);
    aux = line.at(i + 1);
    next.SetStateTo(aux);
    transitions.push_back(next);
    i++;
  }
  /*std::cout << "nombre = " << name_ << std::endl;
  std::cout << "acepta? " << aceptation_ << std::endl;
  std::cout << "Transiciones" << std::endl;
  for (unsigned i = 0; i < transitions.size(); i++) {
    std::cout << "Con el simbolo '" << transitions.at(i).GetSymbol() << "' va a ";
    std::cout << transitions.at(i).GetStateTO() << std::endl << std::endl;
  }*/
}

bool State::IsAceptation()  {
  return aceptation_;
}

bool State::IsStart() {
  return start_;
}

std::string State::GetName() {
  return name_;
}

Transition State::GetTransition(std::string ch) {
  for (unsigned i = 0; i < transitions.size(); i++) {
    if (ch == transitions.at(i).GetSymbol()) {
      return transitions.at(i);
    }
  }
  std::cout << "saliendo" << std::endl;
  exit(1);
}

void State::clear() {
  aceptation_ = false;
  start_ = false;
  trans_num_ = 0;
  transitions.clear();
  name_ = "";
}