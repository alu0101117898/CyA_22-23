// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Transition.cc: Desarrollo de las funciones de la clase Transition.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#include "Transition.h"

Transition::Transition() {

}

Transition::Transition(std::string s, std::string n) {
  symbol_ = s;
  state_to_ = n;
}

void Transition::SetSymbol(const std::string sy) {
  symbol_ = sy;
}

void Transition::SetStateTo(const std::string st) {
  state_to_ = "q" + st;
  pos_ = stoi(st);
}

void Transition::SetPos(int i) {
  pos_ = i;
}

std::string Transition::GetStateTO() const {
  return state_to_;
}

std::string Transition::GetSymbol() const {
  return symbol_;
}

int Transition::GetPos() const{
  return pos_;
}