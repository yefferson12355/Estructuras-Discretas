#include <iostream>
#include <string>

using namespace std;

/* Menu de Bases: */
void Menu (){
    // Muestra el menú de opciones
    cout << "**********************" << endl;
    cout << "________Menu:__________" << endl;
    cout << "1.-Decimal a Binario." << endl;
    cout << "2.-Binario a Decimal." << endl;
    cout << "3.-Binario a Octal." << endl;
    cout << "4.-Binario a Hexadecimal." << endl;
    cout << "5.-Salir." << endl;
    cout << "**********************" << endl;
}

// Función para convertir un número decimal a binario
long int DecimalABinario(int Decimal) {
    long int Binario = 0;
    int Base = 1;
    while (Decimal > 0) {
        Binario += (Decimal % 2) * Base; // Obtiene el bit menos significativo y lo agrega al número binario
        Decimal /= 2; // Divide el número decimal por 2
        Base *= 10; // Incrementa la base para el siguiente bit binario
    }
    return Binario;
}

// Función para convertir un número binario a decimal
int BinarioADecimal(long int Binario) {
    int Decimal = 0, Base = 1, Resto;
    while (Binario > 0) {
        Resto = Binario % 10; // Obtiene el dígito menos significativo del número binario
        Decimal += Resto * Base; // Multiplica el dígito por la base y lo agrega al número decimal
        Base *= 2; // Incrementa la base para el siguiente dígito binario
        Binario /= 10; // Elimina el dígito menos significativo del número binario
    }
    return Decimal;
}

// Función para convertir un número binario a octal
string BinarioAOctal(long int Binario) {
    string Octal = "";
    int Decimal = BinarioADecimal(Binario);
    while (Decimal > 0) {
        Octal = to_string(Decimal % 8) + Octal; // Obtiene el dígito menos significativo en base 8 y lo agrega al número octal
        Decimal /= 8; // Divide el número decimal por 8
    }
    return Octal;
}

// Función para convertir un número binario a hexadecimal
string BinarioAHexadecimal(long int Binario) {
    string Hexadecimal = "";
    int Decimal = BinarioADecimal(Binario);
    while (Decimal > 0) {
        int Rem = Decimal % 16; // Obtiene el dígito menos significativo en base 16
        if (Rem < 10) {
            Hexadecimal = char('0' + Rem) + Hexadecimal; // Si el dígito es menor que 10, se agrega al número hexadecimal como un dígito
        } else {
            Hexadecimal = char('A' + Rem - 10) + Hexadecimal; // Si el dígito es mayor o igual que 10, se agrega al número hexadecimal como una letra de la A a la F
        }
        Decimal /= 16; // Divide el número decimal por 16
    }
    return Hexadecimal;
}

int main(int argc, char const *argv[]) {
    int Opcion;
    long int Numero;
    do {
        Menu(); // Muestra el menú de opciones
        cin >> Opcion; // Lee la opción seleccionada por el usuario
        switch (Opcion) {
            case 1:
                cout << "Ingrese el número en base DECIMAL: ";
                cin >> Numero; // Lee el número decimal ingresado por el usuario
                cout << "Binario: " << DecimalABinario(Numero) << endl; // Convierte el número a binario y lo muestra
                break;
            case 2:
                cout << "Ingrese el número en base BINARIO: ";
                cin >> Numero; // Lee el número binario ingresado por el usuario
                cout << "Decimal: " << BinarioADecimal(Numero) << endl; // Convierte el número a decimal y lo muestra
                break;
            case 3:
                cout << "Ingrese el número en base BINARIO: ";
                cin >> Numero; // Lee el número binario ingresado por el usuario
                cout << "Octal: " << BinarioAOctal(Numero) << endl; // Convierte el número a octal y lo muestra
                break;
            case 4:
                cout << "Ingrese el número en base BINARIO: ";
                cin >> Numero; // Lee el número binario ingresado por el usuario
                cout << "Hexadecimal: " << BinarioAHexadecimal(Numero) << endl; // Convierte el número a hexadecimal y lo muestra
                break;
            case 5:
                cout << "Saliendo del programa..." << endl; // Muestra un mensaje de salida
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione nuevamente." << endl; // Muestra un mensaje de error si la opción seleccionada no es válida
                break;
        }
    } while (Opcion != 5); // Repite el menú hasta que el usuario seleccione la opción de salida
    
    return 0; // Retorna 0 para indicar que el programa se ejecutó correctamente
}
