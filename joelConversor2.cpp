#include <iostream>
using namespace std;

int x; // Variable global para almacenar la suma de los números ingresados

// Función para invertir los bits de un número binario
string invertirBits(string binario) {
    for (char& bit : binario) {
        bit = (bit == '0') ? '1' : '0'; // Si el bit es '0', lo cambia a '1'; si es '1', lo cambia a '0'
    }
    return binario;
}

// Función para sumar 1 a un número binario
string sumarUno(string binario) {
    int carry = 1;
    for (int i = binario.size() - 1; i >= 0; i--) {
        if (binario[i] == '1' && carry == 1) { // Si el bit actual es '1' y hay un acarreo pendiente
            binario[i] = '0'; // Cambia el bit a '0'
        } else if (binario[i] == '0' && carry == 1) { // Si el bit actual es '0' y hay un acarreo pendiente
            binario[i] = '1'; // Cambia el bit a '1'
            carry = 0; // Reinicia el acarreo
        }
    }
    return binario;
}

// Función para calcular el complemento a 2 de un número binario
string complementoA2Binario(string binario) {
    // Invertimos los bits del número
    binario = invertirBits(binario);
    // Sumamos 1 al número invertido
    binario = sumarUno(binario);
    return binario;
}

// Función para convertir un número decimal a binario
string decimalABinario(int decimal, int bits) {
    string binario = ""; // Inicializa una cadena para almacenar la representación binaria del número
    bool esNegativo = decimal < 0; // Verifica si el número es negativo
    decimal = abs(decimal); // Convierte el número a su valor absoluto (positivo)
    
    // Convierte el número decimal a binario
    while (decimal > 0) {
        binario = (decimal % 2 == 0 ? '0' : '1') + binario; // Añade el residuo de la división por 2 al inicio de la cadena binaria
        decimal /= 2; // Divide el número decimal por 2
    }
    
    // Rellena con ceros a la izquierda hasta alcanzar el número de bits deseado
    while (binario.size() < bits - 1) {
        binario = '0' + binario;
    }
    
    // Si el número original era negativo y se necesita rellenar con ceros a la izquierda, se aplica el complemento a 2
    if (esNegativo) {
        // Complemento a 2 solo si el número no cabe en los bits especificados
        if (binario.size() < bits - 1) {
            binario = complementoA2Binario(binario);
        }
        // Agrega el bit de signo (1 para negativo, 0 para positivo)
        binario = '1' + binario;
    } else {
        // Agrega el bit de signo (0 para positivo)
        binario = '0' + binario;
    }
    
    return binario;
}

int main() {
    int numero1, numero2, bits;
    cout << "Ingrese el primer número: ";
    cin >> numero1;
    cout << "Ingrese el segundo número: ";
    cin >> numero2;
    cout << "Ingrese el número de bits: ";
    cin >> bits;

    // Asignar la suma de los números ingresados a la variable global x
    x = numero1 + numero2;

    // Convertir los números ingresados y la suma a su representación binaria
    string binario1 = decimalABinario(numero1, bits);
    string binario2 = decimalABinario(numero2, bits);
    
    cout << "Representación binaria del primer número: " << binario1 << endl;
    cout << "Representación binaria del segundo número: " << binario2 << endl;
    
    // Convertir la variable x a binario utilizando la misma función de conversión
    string binarioX = decimalABinario(x, bits);
    cout << "Resultado de la suma en decimal convertida a binario: " << binarioX << endl;

    return 0;
}
