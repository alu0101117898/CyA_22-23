// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Alfabeto.h: Definición de las funciones de la clase Alfabeto.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <cstring>
#include <vector>

#include "Symbol.h"

class Alfabeto {
  public:
    Alfabeto();
    Alfabeto(std::string);
    Alfabeto(std::vector<std::string>);
    void Clear();

    void SetWord(std::string);
    void SetSymbol(Symbol);
    void SetAlfabeto(std::vector<std::string>);

    std::string GetSymbol(int);
    std::vector<Symbol> GetAlphabet();
    Symbol GetWord(int);
    std::vector<std::string> GetAlfabeto();
    unsigned GetSize();
    unsigned GetSSize();

  private:
    std::vector<std::string> List_;
    std::vector<Symbol> Alphabet;
};