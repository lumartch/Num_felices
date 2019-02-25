#include "interfaz.h"

Interfaz::Interfaz() {
    menuPrincipal();
}

Interfaz::~Interfaz() {
    //dtor
}

void Interfaz::menuPrincipal() {
    int opc = 0;
    while(true) {
        system(CLEAR);
        cout << "+------------------------------------------------+" << endl;
        cout << "|       Cálculo de numero feliz  V 1.0           |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| ¿Qué desea hacer?                              |" << endl;
        cout << "|    1: Ingresar nuevo número.                   |" << endl;
        cout << "|    2: Salir.                                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| Ingrese su opción:                             |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "\033[8;22H";
        opc = getchar();
        cout << endl << endl;
        if(!validarOpc(opc)) {
            cout << "| Opción inválida. Intente de nuevo.             |" << endl;
            cout << "+------------------------------------------------+" << endl;
            pausa();
        }
        else{
            if(opc == 49) {
                capturarNumero();
            } else if(opc == 50) {
                cout << "| Gracias por usar el calculador de Num. Felices.|" << endl;
                cout << "+------------------------------------------------+" << endl;
                break;
            } else {

            }
            pausa();
        }
    }
}

void Interfaz::capturarNumero() {
    system(CLEAR);
    cout << "+------------------------------------------------+" << endl;
    cout << "|       Cálculo de numero feliz  V 1.0           |" << endl;
    cout << "+------------------------------------------------+" << endl;

}

bool Interfaz::validarOpc(const int & opc) {
    if(opc == 10){
        return false;
    }
    int x = getchar();
    if(x != 10){
        cin.ignore();
        ungetc(10, stdin);
        return false;
    }
    ungetc(10, stdin);
    return true;
}

void Interfaz::pausa() {
    cout << endl << endl << "Presione [Enter] para continuar..." << endl;
}

