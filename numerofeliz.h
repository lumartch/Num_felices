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
    void setDigNumeroFeliz(const int &n);
    std::string toString();
    bool esFeliz();

private:
    std::queue<int> nf;
    std::vector<unsigned long long int> repetidos;
    bool bandera = true;
    int ciclos;
    unsigned long long int getSumatoria();
    void resultado();
};

#endif // NUMEROFELIZ_H
