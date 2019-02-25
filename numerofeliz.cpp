#include "numerofeliz.h"

NumeroFeliz::NumeroFeliz() {

}

NumeroFeliz::~NumeroFeliz() {
    //dtor
}

bool NumeroFeliz::numeroFelizValido(const int& n) {
    // Todo caracter ingresado entre 0 - 9 se aceptara como número
    // En caso de ingresar un caracter inválido, se regresa un false.
    if(n >= 48 and n <= 57) {
        setDigNumeroFeliz(n);
        return true;
    }
    return false;
}

void NumeroFeliz::setDigNumeroFeliz(const int& n) {
    // Todo número mayor a 0 se coloca en la cola.
    if((n - 48) != 0) {
        nf.push(n - 48);
    }
}

void NumeroFeliz::resultado() {
    // Esta parte del código realiza los cálculos pertinentes para los números felices
    // En caso de que la sumatoria sea igual a 1, quiere decir que es feliz.
    unsigned int nfSize = nf.size();
    unsigned long long int sumatoria = getSumatoria();
    if(sumatoria != 1){
        unsigned int lim = 0;
        //Se toman todos los valores introducidos al inicio y se colocan en una segunda cola elevados al cuadrado.
        std::queue<int> aux;
        while(lim < nfSize) {
            int n = nf.front();
            //nf.push(nf.front());
            nf.pop();
            aux.push(n*n);
            lim++;
        }
        // Se realiza la suma de los cuadrados dentro de la variable "res"
        unsigned long long int res = 0;
        for(unsigned int i = 0, j = aux.size(); i < j; i++){
            res += aux.front();
            aux.pop();
        }
        // Se separan los números para la siguiente iteración
        while(res != 0){
            nf.push(res%10);
            res = res/10;
        }
        /*std::cout << "AuxSize: "<< aux.size() << " ; nfSize: " << nf.size() << std::endl;
        std::cout << "nf Contenido: " << toString() << std::endl;
        std::cin.get();*/
        resultado();
    } else {
        /*std::cout << "El número es feliz." << std::endl;
        std::cin.get();*/
    }
}

std::string NumeroFeliz::toString() {
    // Regresa el número dentro de la cola en formato string
    std::string r = "";
    for(unsigned int i = 0; i < nf.size() ; i++) {
        r += std::to_string(nf.front());
        nf.push(nf.front());
        nf.pop();
    }
    return r;
}

unsigned long long int NumeroFeliz::getSumatoria() {
    // Regresa la sumatoria de los valores dentro de la cola en formato unsigned long long int... Por si las dudas!
    unsigned long long int r = 0;
    for(unsigned int i = 0; i < nf.size(); i++){
        r += nf.front();
        nf.push(nf.front());
        nf.pop();
    }
    return r;
}
