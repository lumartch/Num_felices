#ifndef INTERFAZ_H
#define INTERFAZ_H

#ifdef WIN_32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // WIN_32

#include <iostream>
#include <cstdio>
#include "numerofeliz.h"

using namespace std;

class Interfaz {
public:
    Interfaz();
    virtual ~Interfaz();
    void menuPrincipal();

private:
    void capturarNumero();
    bool validarOpc(const int & opc);
    void pausa();

};

#endif // INTERFAZ_H
