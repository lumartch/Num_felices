#ifndef INTERFAZ_H
#define INTERFAZ_H

// Variable dependiente del OS, para limpiar pantalla.
#ifdef WIN_32
#define CLEAR "cls"
#define NOLIMIT "stty cbreak"
#else
#define CLEAR "clear"
#define NOLIMIT "stty cbreak"
#endif // WIN_32

// Objeto para cálcular el número feliz.
#include "numerofeliz.h"
// Librería para cancelar la señal de CTRL-C
#include <csignal>
// Librería para la función sleep
#include <unistd.h>
// Librería para impresion con Printf
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
