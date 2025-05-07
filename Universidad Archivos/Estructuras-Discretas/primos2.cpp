#include<iostream>
#include<cmath>

using namespace std;

/// Función para verificar si un número es primo
bool esPrimo(int numero) {
    // Si el número es 1 o menor, no es primo
    if (numero <= 1) {
        return false;
    }

    // Comenzamos a verificar divisores desde 2 hasta la raíz cuadrada del número
    // Por teorema basta con probar hasta la raiz cuadrada del numero   
    for (int divisor = 2; divisor <= sqrt(numero); ++divisor) {
        // Si el número es divisible por el divisor actual, no es primo
        if (numero % divisor == 0) {
            return false;
        }
    }

    // Si no se encontraron divisores, el número es primo
    return true;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros primos que desea mostrar: ";
    cin >> n;

    int contador = 0;
    int numero = 2; // Comenzamos desde el primer número primo

    while (contador < n) {
        if (esPrimo(numero)) {
            cout << numero << " ";
            contador++;
        }
        numero++;
    }

    return 0;
}