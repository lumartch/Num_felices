#ifndef INTERFAZ_H
#define INTERFAZ_H

// Variable dependiente del OS, para limpiar pantalla.
#ifdef WIN_32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // WIN_32

// Objeto para cálcular el número feliz.
#include "numerofeliz.h"
// Librería para cancelar la señal de CTRL-C
#include <csignal>
// Librería para la función sleep
#include <unistd.h>
//
#include <cstdio>

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
