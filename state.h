// Autor: Ricardo Fariña Mesa
// Correo: alu0101117898@ull.es
// Fecha: 08/11/2022
// Archivo cya-P06-state.h: Definición de las funciones de la clase State.
// se encarga de definir los estados de aceptación del autómata.
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 08/11/2022 - Creación (primera versión) del código
#pragma once

#include <iostream>
#include "transition.h"

class State {
  public:
    State();
    State(bool, int);

    void SetAceptation();
    void SetStart();
    void SetName(std::string);
    void SetState(std::string);

    bool IsAceptation();
    bool IsStart();
    std::string GetName();
    Transition GetTransition(std::string);

    void clear();
    
  private:
    bool start_;
    bool aceptation_;
    std::string name_;
    int trans_num_;
    std::vector<Transition> transitions;
};