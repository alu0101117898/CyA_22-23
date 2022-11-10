// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-Transition.h: Definición de las funciones de la clase Transition.	
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#pragma once 

#include <iostream>
#include <vector>

class Transition {
  public:
    Transition();
    Transition(std::string, std::string);

    void SetSymbol(const std::string);
    void SetStateTo(const std::string);
    void SetPos(int);

    std::string GetSymbol() const;
    std::string GetStateTO() const;
    int GetPos() const;

  private:
    std::string symbol_;
    int pos_;
    std::string state_to_;
};