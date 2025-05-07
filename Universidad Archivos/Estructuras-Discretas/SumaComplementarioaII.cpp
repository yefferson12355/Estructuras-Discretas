#include <iostream>
#include <string>

using namespace std;

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
    
    // Si el número original era negativo y se necesita rellenar con ceros a la izquierda, se aplica el complemento a 2
    if (esNegativo && binario.size() < bits) {
        binario = complementoA2Binario(binario);
    }
    
    // Si se necesita rellenar con ceros a la izquierda, se añaden
    while (binario.size() < bits) {
        binario = '0' + binario;
    }
    
    return binario;
}

// Función para sumar dos números en complemento a 2 en formato binario
string sumaComplementoA2Binario(string binario1, string binario2, int bits) {
    string resultado = ""; // Inicializa una cadena para almacenar el resultado de la suma
    
    int carry = 0; // Inicializa el acarreo en cero
    
    // Itera desde el bit menos significativo hasta el bit más significativo
    for (int i = binario1.size() - 1; i >= 0; i--) {
        int bit1 = binario1[i] - '0'; // Convierte el carácter en el bit correspondiente
        int bit2 = binario2[i] - '0'; // Convierte el carácter en el bit correspondiente
        
        int suma = bit1 + bit2 + carry; // Calcula la suma de los bits más el acarreo
        
        // Si la suma es 0 o 1, el resultado es el mismo valor
        if (suma == 0 || suma == 1) {
            /* to_string: para comvertilo en formato cadena. */
            resultado = to_string(suma) + resultado;
            carry = 0; // No hay acarreo
        } else if (suma == 2) {
            resultado = '0' + resultado; // Suma igual a 10 (binario), se agrega 0 al resultado
            carry = 1; // Hay acarreo
        } else if (suma == 3) {
            resultado = '1' + resultado; // Suma igual a 11 (binario), se agrega 1 al resultado
            carry = 1; // Hay acarreo
        }
    }
    
    // Si hay acarreo al final de la suma y se necesita un bit extra, se añade
    if (carry && resultado.size() < bits) {
        resultado = '1' + resultado;
    }
    
    // Determina si el resultado es negativo (si el bit más significativo es 1)
if (resultado[0] == '1') {
    // Inserta un '1' en la parte más izquierda del resultado
    resultado.insert(0, "1");
}
    return resultado;
}

int main() {
    int numero1 = 0; // Primer número
    int numero2 = 0; // Segundo número
    int bits = 0; // Número de bits para representar los números

    cout<<"Ingrese un el primer numero:"<<endl;
    cin>>numero1;
    
    cout<<"Ingrese un el segundo numero:"<<endl;
    cin>>numero2;

    cout<<"Ingrese el numero de bits para la suma"<<endl;
    cin>>bits;


    // Convierte los números a su representación en complemento a 2 en binario
    string binario1 = decimalABinario(numero1, bits);
    string binario2 = decimalABinario(numero2, bits);
    
    // Muestra los números en binario y su suma en binario
    cout << "Numero 1 en binario (complemento a 2): " << binario1 << endl;
    cout << "Numero 2 en binario (complemento a 2): " << binario2 << endl;
    
    // Calcula la suma de los números en complemento a 2
    string sumaBinaria = sumaComplementoA2Binario(binario1, binario2, bits);
    
    // Muestra la suma en binario y su equivalente en decimal
    cout<<endl;
    cout << "Suma en binario: " << sumaBinaria << endl;
    cout << "Suma en decimal: " << (numero1)+(numero2)<< endl;

    return 0;
}
