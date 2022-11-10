// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Symbol.cc: Desarrollo de las funciones de la clase State.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#include "Symbol.h"

Symbol::Symbol() {

}

Symbol::Symbol(std::string S) {
  SetSymbol(S);
}

void Symbol::SetSymbol(std::string S) {
  Symbol_ = S;
}

std::string Symbol::GetSymbol() {
  return Symbol_;
}
unsigned Symbol::GetSize() {
  return Symbol_.size();
}

Symbol Symbol::operator+(Symbol word) {
  Symbol aux;
  std::string conc = Symbol_ + word.GetSymbol();
  aux.SetSymbol(conc); 
  return aux;
}