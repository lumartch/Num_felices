#include "interfaz.h"

Interfaz::Interfaz() {
    // SIGINT -> Señal de macros, SIG_IGN -> Handler para ignorar.
    signal(SIGINT, SIG_IGN);
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
        cout << "| Ingrese su opción: ";
        //cout << "| Ingrese su opción:                             |" << endl;
        //cout << "+------------------------------------------------+" << endl;
        //cout << "\033[8;22H";
        opc = getchar();
        cout << endl;
        if(validarOpc(opc) == false) {
            cout << "| Opción inválida. Intente de nuevo.             |" << endl;
            cout << "+------------------------------------------------+" << endl;
            pausa();
        } else {
            if(opc == 49) {
                capturarNumero();
            } else if(opc == 50) {
                cout << "| Gracias por usar el calculador de Num. Felices.|" << endl;
                cout << "+------------------------------------------------+" << endl;
                break;
            } else {
                cout << "| Opción inválida. Intente de nuevo.             |" << endl;
                cout << "+------------------------------------------------+" << endl;
            }
            pausa();
        }
    }
}

void Interfaz::capturarNumero() {
    system(CLEAR);
    NumeroFeliz nf;
    cout << "+------------------------------------------------+" << endl;
    cout << "|       Cálculo de numero feliz  V 1.0           |" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Los números solo pueden ser enteros positivos, |" << endl;
    cout << "| no introduzca el simbolo '+', el programa los  |" << endl;
    cout << "| detecta inmediatamente.                        |" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Ingrese el número a evaluar (0 al... Inf): ";
    //cout << "| Ingrese el número a evaluar (0 al... Inf): "      << endl;
    //cout << "+------------------------------------------------+" << endl;
    //cout << "\033[8;46H";
    int n = 0;
    n = getchar();
    bool f = true;
    while(n != 10){
        if(!nf.numeroFelizValido(n)){
            f = false;
        }
        n = getchar();
    }
    if(f == true){
        cout << "+---------------------------------------------------+" << endl;
        cout << "| Cálculando el tiempo estimado                     |" << endl;
        sleep(1);
        cout << "." << endl;
        sleep(1);
        cout << "." << endl;
        sleep(1);
        cout << "." << endl;
        cout << "| El tiempo requerido será de: " << endl;
        cout << "+---------------------------------------------------+" << endl;
        if(nf.esFeliz()){
            cout << "El número ingresado es feliz." << endl;
        }
        else{
            cout << "El número ingresado es un maldito infeliz." << endl;
        }
    }
    else{
        cout << "+------------------------------------------------+" << endl;
        cout << "| El número ingresado es inválido.               |" << endl;
        cout << "+------------------------------------------------+" << endl;
    }
}

bool Interfaz::validarOpc(const int & opc) {
    if(opc == 10) {
        return false;
    }
    int x = getchar();
    if(x != 10) {
        cin.ignore();
        return false;
    }
    return true;
}

void Interfaz::pausa() {
    cout << endl << endl << "Presione [Enter] para continuar..." << endl;
    cin.get();
}

