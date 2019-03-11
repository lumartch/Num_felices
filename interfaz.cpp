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
        cout << "|       Cálculo de numero feliz  V 1.2           |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| ¿Qué desea hacer?                              |" << endl;
        cout << "|    1: Ingresar nuevo número.                   |" << endl;
        cout << "|    2: Salir.                                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| Ingrese su opción:                             |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "\033[8;22H";
        //cout << "| Ingrese su opción: ";
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
                pausa();
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
    // Comando para desbloquear el límite de caracteres dentro de la consola.
    system(NOLIMIT);
    system(CLEAR);
    NumeroFeliz nf;
    cout << "+---------------------------------------------------+" << endl;
    cout << "|       Cálculo de numero feliz  V 1.2              |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "| Los números solo pueden ser enteros positivos,    |" << endl;
    cout << "| no introduzca el simbolo '+', el programa los     |" << endl;
    cout << "| detecta inmediatamente.                           |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "| Ingrese el número a evaluar (0 al... Inf): "      << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "\033[8;46H";
    //cout << "| Ingrese el número a evaluar (0 al... Inf): ";
    int n = 0;
    n = getchar();
    bool f = true;
    while(n != 10){
        if(!nf.numeroFelizValido(n)){
            f = false;
        }
        n = getchar();
    }
    if(f == true and nf.getTamanio() > 0){
        cout << "+---------------------------------------------------+" << endl;
        cout << "| Cálculando el tiempo estimado                     |" << endl;
        cout << "| El tiempo requerido será de: ";
        //printf("%.12fs \n", nf.precalculoTiempo());
        cout << "+---------------------------------------------------+" << endl;
        sleep(1);
        cout << "| El tamaño del número ingresado es de: " << nf.getTamanio() << endl;
        cout << "+---------------------------------------------------+" << endl;
        if(nf.esFeliz()){
            cout << "|         El número ingresado es feliz. c:          |" << endl;
        }
        else{
            cout << "|    El número ingresado es un maldito infeliz. :'c |" << endl;
        }
    }
    else{
        cout << "+---------------------------------------------------+" << endl;
        cout << "|    El número ingresado es inválido.               |" << endl;
    }
    cout << "+---------------------------------------------------+" << endl;
    // Comando para regresar a sus valores predefinidos la terminal
    system(SANE);
}

// Función para solo válidar los caracteres dentro de las opciones actuales
bool Interfaz::validarOpc(const int & opc) {
    // Válida  si la entrada viene vacía
    if(opc == 10){
        return false;
    }
    // Valida si la entrada viene con mas de un caracter
    int chSobrantes = 0;
    while(getchar() != 10){
        chSobrantes++;
    }
    if(chSobrantes > 0){
        return false;
    }
    // Válida si la entrada esta dentro de las opciones
    if(opc == 49 or opc == 50){
        return true;
    }
    return false;
}

void Interfaz::pausa() {
    cout << endl << endl << "Presione [Enter] para continuar..." << endl;
    while(getchar() != 10);
}

