#ifndef NUMEROFELIZ_H
#define NUMEROFELIZ_H

#include <queue>
#include <vector>
#include <string>
#include <iostream>

class NumeroFeliz {
public:
    NumeroFeliz();
    virtual ~NumeroFeliz();
    bool numeroFelizValido(const int &n);
    unsigned long long int getTamanio();
    bool esFeliz();

private:
    std::queue<int> nf;
    std::vector<unsigned long long int> repetidos;
    bool bandera = true;
    unsigned long long int tamanio;
    int ciclos;
    void setDigNumeroFeliz(const int &n);
    unsigned long long int getSumatoria();
    void resultado();
};

#endif // NUMEROFELIZ_H
