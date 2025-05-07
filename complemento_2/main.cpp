#include <iostream>

using namespace std;

int x; // Variable global


string invertirBits(string binario) {
    for (char& bit : binario) {
        bit = (bit == '0') ? '1' : '0';
    }
    return binario;
}


string sumarUno(string binario) {
    int carry = 1;
    for (int i = binario.size() - 1; i >= 0; i--) {
        if (binario[i] == '1' && carry == 1) { // Si el bit actual es '1' y hay un acarreo pendiente
            binario[i] = '0';
        } else if (binario[i] == '0' && carry == 1) {
            binario[i] = '1';
            carry = 0;
        }
    }
    return binario;
}


string complementoA2Binario(string binario) {

    binario = invertirBits(binario);
    binario = sumarUno(binario);
    return binario;
}


string decimalABinario(int decimal, int bits) {
    string binario = "";
    bool esNegativo = decimal < 0;
    decimal = abs(decimal);

    // Convierte el número decimal a binario
    while (decimal > 0) {
        binario = (decimal % 2 == 0 ? '0' : '1') + binario;
        decimal /= 2;
    }


    while (binario.size() < bits - 1) { // -1 para dejar espacio para el bit de signo
        binario = '0' + binario;
    }

    // Si es negativo, se aplica el complemento a 2
    if (esNegativo) {

        binario = complementoA2Binario(binario);

        binario = '1' + binario;
    } else {

        binario = '0' + binario;
    }

    return binario;
}

int main() {
    int numero1, numero2, bits;
    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;
    cout << "Ingrese el numero de bits: ";
    cin >> bits;


    x = numero1 + numero2;

    string binario1 = decimalABinario(numero1, bits);
    string binario2 = decimalABinario(numero2, bits);

    cout << "Representacion binaria del primer numero: " << binario1 << endl;
    cout << "Representacion binaria del segundo numero: " << binario2 << endl;


    string binarioX = decimalABinario(x, bits);
    cout << "Resultado de la suma en decimal convertida a binario: " << binarioX << endl;

    return 0;
}
