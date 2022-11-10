// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Symbol.h: Definición de las funciones de la clase Symbol.	
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#pragma once

#include <iostream>

class Symbol {
  public:
    Symbol();
    Symbol(std::string);

    void SetSymbol(std::string);
    std::string GetSymbol();
    unsigned GetSize();

    Symbol operator+(Symbol);
  private:
    std::string Symbol_;
};