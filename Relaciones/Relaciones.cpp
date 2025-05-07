#include <iostream>
using namespace std;

// Inicializa la matriz con valores de los datos proporcionados
void InicializarMatriz(int** matriz, int tamano, int datos[][2], int cantidadDatos, int encendido) {
    // Llena la matriz con ceros
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Coloca los valores de encendido según los datos proporcionados
    for (int k = 0; k < cantidadDatos; k++) {
        int i = datos[k][0] - 1; // Ajusta índice para empezar desde 0
        int j = datos[k][1] - 1; // Ajusta índice para empezar desde 0
        matriz[i][j] = encendido;
    }
}

// Muestra la matriz en consola
void ImprimirMatriz(int** matriz, int tamano) {
    cout << "Matriz:" << endl;
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl; 
    }
}

// Verifica si la matriz es reflexiva
bool EsReflexiva(int** matriz, int tamano, int encendido) {
    for (int i = 0; i < tamano; i++) {
        if (matriz[i][i] != encendido) {
            return false;
        }
    }
    return true;
}

// Verifica si la matriz es irreflexiva
bool EsIrreflexiva(int** matriz, int tamano, int apagado) {
    for (int i = 0; i < tamano; i++) {
        if (matriz[i][i] != apagado) {
            return false;
        }
    }
    return true;
}

// Verifica si la matriz es simétrica
bool EsSimetrica(int** matriz, int tamano) {
    bool soloCeros = true;
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            if (i != j && matriz[i][j] != 0) {
                soloCeros = false;
            }
            if (matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }
    return !soloCeros;
}

// Verifica si la matriz es asimétrica
bool EsAsimetrica(int** matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        if (matriz[i][i] != 0) { // Verifica irreflexividad
            return false;
        }
        for (int j = 0; j < tamano; j++) {
            if (i != j && matriz[i][j] == 1 && matriz[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool EsAntisimetrica(int** matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            // Ignorar la diagonal principal
            if (i != j) {
                // Si ambos elementos matriz[i][j] y matriz[j][i] son ceros, no es antisimétrica
                if (matriz[i][j] == 0 && matriz[j][i] == 0) {
                    return false;
                }
                // Si ambos elementos matriz[i][j] y matriz[j][i] no son 0 y son iguales, no es antisimétrica
                if (matriz[i][j] != 0 && matriz[j][i] != 0 && matriz[i][j] == matriz[j][i]) {
                    return false;
                }
            }
        }
    }
    // Si no hay violaciones encontradas, la matriz es antisimétrica
    return true;
}



// Verifica si la matriz es transitiva
bool EsTransitiva(int** matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            if (matriz[i][j] == 1) {
                for (int k = 0; k < tamano; k++) {
                    if (matriz[j][k] == 1 && matriz[i][k] != 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// Verifica si la matriz es una relación de equivalencia
bool EsEquivalencia(int** matriz, int tamano, int encendido) {
    return EsReflexiva(matriz, tamano, encendido) &&
           EsSimetrica(matriz, tamano) &&
           EsTransitiva(matriz, tamano);
}

// Maneja la creación, impresión y verificación de la matriz
void ManejarMatriz() {
    int encendido = 1;
    int apagado = 0;
    int tamano;

    cout << "Ingrese el tamano de la matriz: ";
    cin >> tamano;

    cout << "Ingrese el numero de pares encendidos para la matriz: ";
    int cantidadDatos;
    cin >> cantidadDatos;

    int datos[cantidadDatos][2];
    cout << "Ingrese los pares de datos (formato: i j):" << endl;
    for (int k = 0; k < cantidadDatos; k++) {
        cin >> datos[k][0] >> datos[k][1];
    }
    
    // Crear la matriz de tamaño tamano x tamano
    int** matriz = new int*[tamano];
    for (int i = 0; i < tamano; i++) {
        matriz[i] = new int[tamano];
    }
    
    // Inicializar la matriz con los datos
    InicializarMatriz(matriz, tamano, datos, cantidadDatos, encendido);
    
    // Imprimir la matriz
    ImprimirMatriz(matriz, tamano);

    // Verificar y mostrar propiedades
    cout << "---------------------" << endl;
    cout << "| Es Reflexiva: " << (EsReflexiva(matriz, tamano, encendido) ? "Si" : "No") << "   |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Irreflexiva: " << (EsIrreflexiva(matriz, tamano, apagado) ? "Si" : "No") << " |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Simetrica: " << (EsSimetrica(matriz, tamano) ? "Si" : "No") << "   |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Asimetrica: " << (EsAsimetrica(matriz, tamano) ? "Si" : "No") << "  |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Antisimetrica: " << (EsAntisimetrica(matriz, tamano) ? "Si" : "No") << " |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Transitiva: " << (EsTransitiva(matriz, tamano) ? "Si" : "No") << "  |" << endl;
    cout << "---------------------" << endl;
    cout << "| Es Relacion de Equivalencia: " << (EsEquivalencia(matriz, tamano, encendido) ? "Si" : "No") << "  |" << endl;
    cout << "---------------------" << endl;

    // Liberar la memoria
    for (int i = 0; i < tamano; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Muestra el menú principal
void Menu() {
    ManejarMatriz();
}

int main() {
    Menu();
    return 0;
}
