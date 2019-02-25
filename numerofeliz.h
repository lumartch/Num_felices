#ifndef NUMEROFELIZ_H
#define NUMEROFELIZ_H

#include <queue>
#include <string>
#include <cstring>
#include <iostream>

class NumeroFeliz {
public:
    NumeroFeliz();
    virtual ~NumeroFeliz();
    bool numeroFelizValido(const int &n);
    void setDigNumeroFeliz(const int &n);
    std::string toString();
    void resultado();

private:
    std::queue<int> nf;
    unsigned long long int getSumatoria();
};

#endif // NUMEROFELIZ_H
