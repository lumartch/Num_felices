#include "numerofeliz.h"

NumeroFeliz::NumeroFeliz() {
    ciclos = 0;
    tamanio = 0;
}

NumeroFeliz::~NumeroFeliz() {
    //dtor
}

bool NumeroFeliz::numeroFelizValido(const int& n) {
    // Todo caracter ingresado entre 0 - 9 se aceptara como número
    // En caso de ingresar un caracter inválido, se regresa un false.
    if(n >= 48 and n <= 57) {
        setDigNumeroFeliz(n - 48);
        tamanio++;
        return true;
    }
    return false;
}

void NumeroFeliz::setDigNumeroFeliz(const int& n) {
    // Todo número mayor a 0 se coloca en la cola.
    if(n != 0) {
        nf.push(n);
        repetidos.push_back(n);
    }
}

unsigned long long int NumeroFeliz::getTamanio() {
    return tamanio;
}

double NumeroFeliz::precalculoTiempo() {
    double tme = 0;
    int l = (tamanio*10)/2;
    srand(time(nullptr));
    for(int j = 0; j < l; j++, l--){
        for(int k = 0; k < 2; k++){
            double x = rand() % 9 - 1;
            for(int j = 0; j < l; j++){
                tme += x/1000000000;
            }
            tme += x/1000000000;
            x = rand() % 7-3;
            tme += x/1000000000;
        }
    }
    return tme;
}


void NumeroFeliz::resultado() {
    // Esta parte del código realiza los cálculos pertinentes para los números felices
    // En caso de que la sumatoria sea igual a 1, quiere decir que es feliz.
    unsigned int nfSize = nf.size();
    unsigned long long int sumatoria = getSumatoria();
    if(sumatoria != 1 and bandera == true) {
        unsigned int lim = 0;
        //Se toman todos los valores introducidos al inicio y se colocan en una segunda cola elevados al cuadrado.
        std::queue<int> aux;
        while(lim < nfSize) {
            int n = nf.front();
            nf.pop();
            aux.push(n*n);
            lim++;
        }
        // Se realiza la suma de los cuadrados dentro de la variable "res"
        unsigned long long int res = 0;
        for(unsigned int i = 0, j = aux.size(); i < j; i++) {
            res += aux.front();
            aux.pop();
        }
        // Ingresamos todo número cáluado tras la suma, si este se encuentra en el vector,
        // quiere decir que no es un número feliz
        for(unsigned int i = 0; i < repetidos.size(); i++) {
            if(repetidos[i] == res) {
                bandera = false;
            }
        }
        repetidos.push_back(res);
        // Se separan los números para la siguiente iteración
        while(res != 0) {
            setDigNumeroFeliz(res%10);
            res = res/10;
        }
        resultado();
    }
}

bool NumeroFeliz::esFeliz() {
    // Hace el cálculo del número felíz y regresa la bandera por si hubo cambio.
    resultado();
    return bandera;
}

unsigned long long int NumeroFeliz::getSumatoria() {
    // Regresa la sumatoria de los valores dentro de la cola en formato unsigned long long int... Por si las dudas!
    unsigned long long int r = 0;
    for(unsigned int i = 0; i < nf.size(); i++) {
        r += nf.front();
        nf.push(nf.front());
        nf.pop();
    }
    return r;
}
