// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Alfabeto.cc: Definición de la clase Alfabeto.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código

#include "Alfabeto.h"

//Constructor
Alfabeto::Alfabeto() {
  
}

//Constructores de copia
Alfabeto::Alfabeto(std::string word) {
  SetWord(word);
}

Alfabeto::Alfabeto(std::vector<std::string> list) {
  SetAlfabeto(list);
}

//Setters
void Alfabeto::SetWord(std::string Word) {
  List_.push_back(Word);
}

void Alfabeto::SetSymbol(Symbol S) {
  bool Is = true;
  for (unsigned i = 0; i < Alphabet.size(); i++) {
    if (Alphabet.at(i).GetSymbol() == S.GetSymbol()) {
      Is = false;
    }
  }
  if (Is == true) {
    Alphabet.push_back(S);
  }
}

void Alfabeto::SetAlfabeto(std::vector<std::string> list) {
  List_ = list;
}

//Getters
std::vector<std::string> Alfabeto::GetAlfabeto() {
  return List_;
}

std::vector<Symbol> Alfabeto::GetAlphabet() {
  return Alphabet;
}

std::string Alfabeto::GetSymbol(int pos) {
  return List_.at(pos);
}

Symbol Alfabeto::GetWord(int pos) {
  return Alphabet.at(pos);
}

unsigned Alfabeto::GetSize() {
  return List_.size();
}

unsigned Alfabeto::GetSSize() {
  return Alphabet.size();
}

//Destructor
void Alfabeto::Clear() {
  List_.clear();
  Alphabet.clear();
}