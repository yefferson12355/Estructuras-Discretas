#include <iostream>

using namespace std;

/*Programa(s) de unión, intersección,
diferencia y diferencia simétrica de 2 conjuntos cuyos
 elementos son los números enteros positivos.*/

void leerConjunto(int conjunto[], int& n, const string& nombre) {
    cout << "Ingrese el numero de elementos para el conjunto " << nombre << ": ";
    cin >> n;

    cout << "Ingrese los elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < n; ++i) {

        cin >> conjunto[i];

        if(conjunto[i]<0){
            cout<<"El numero es negativo";
            break;

        }
    }
}

// Función para imprimir un conjunto
void imprimirConjunto(const int conjunto[], int n, const string& nombre) {
    cout<<endl;
    cout << "Elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < n; ++i) {
        if(conjunto[i]<0){
        cout<<"El numero es negativo";
        }
        else{
        cout << conjunto[i] << " ";
        }
    }
    cout << endl;
}

// Función para realizar la unión de dos conjuntos
void unionConjuntos(const int A[], int nA, const int B[], int nB, int unionSet[], int& nUnion) {

    nUnion = 0;

    // Copiar todos los elementos de A a unionSet
    for (int i = 0; i < nA; ++i) {
        unionSet[nUnion++] = A[i];
    }

    // Copiar los elementos de B que no están en A
    for (int i = 0; i < nB; ++i) {
        if(B[i]<0){
            cout<<"El numero es negativo";
            break;
        }
        else{
            bool duplicado = false;
            for (int j = 0; j < nA; ++j) {
                if(A[j]<0){
                cout<<"El numero es negativo";
                break;
                }
                else{
                    if (B[i] == A[j]) {
                        duplicado = true;
                        break;
                    }
                }
            }
            //ocurre si el duplicado sigue siendo false
            if (!duplicado) {
            unionSet[nUnion++] = B[i];
            }

        }
    }
}
//Funcion para realizar la interseccion de dos conjuntos
void interseccionConjuntos(const int A[], int nA, const int B[], int nB, int interseccionSet[], int& nInterseccion) {
    nInterseccion = 0;

    // Buscar elementos de A que también están en B
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) {
                // Verificar si ya está en el conjunto de intersección
                bool duplicado = false;
                for (int k = 0; k < nInterseccion; ++k) {
                    if (interseccionSet[k] == A[i]) {
                        duplicado = true;
                        break;
                    }
                }
                if (!duplicado) {
                    interseccionSet[nInterseccion++] = A[i];
                }
            }
        }
    }
}

// Función para realizar la diferencia de dos conjuntos
void diferenciaConjuntos(const int A[], int nA, const int B[], int nB, int diferenciaSet[], int& nDiferencia) {
    nDiferencia = 0;
    // Buscar elementos de A que no están en B
    for (int i = 0; i < nA; ++i) {
        bool encontrado = false;
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            diferenciaSet[nDiferencia++] = A[i];
        }
    }
}

// Función para realizar la diferencia inversa de dos conjuntos
void diferenciaConjuntosInverso(const int A[], int nA, const int B[], int nB, int diferenciaSet[], int& nDiferenciaInverso) {
    nDiferenciaInverso = 0;
    // Buscar elementos de B que no están en A
    for (int i = 0; i < nB; ++i) {
        bool encontrado = false;
        for (int j = 0; j < nA; ++j) {
            if (B[i] == A[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            diferenciaSet[nDiferenciaInverso++] = B[i];
        }
    }
}

// Función para realizar la diferencia simétrica de dos conjuntos
void diferenciaSimetrica(const int A[], int nA, const int B[], int nB, int diferenciaSimetricaSet[], int& nDiferenciaSimetrica) {
    int diferenciaSetA[TAMANO_MAX], diferenciaSetB[TAMANO_MAX];
    int nDiferenciaA = 0, nDiferenciaB = 0;

    diferenciaConjuntos(A, nA, B, nB, diferenciaSetA, nDiferenciaA);
    diferenciaConjuntosInverso(A, nA, B, nB, diferenciaSetB, nDiferenciaB);

    nDiferenciaSimetrica = 0;
    for (int i = 0; i < nDiferenciaA; ++i) {
        diferenciaSimetricaSet[nDiferenciaSimetrica++] = diferenciaSetA[i];
    }
    for (int i = 0; i < nDiferenciaB; ++i) {
        diferenciaSimetricaSet[nDiferenciaSimetrica++] = diferenciaSetB[i];
    }
}
int main() {
// Tamaño máximo para los conjuntos
    const int TAMANO_MAX = 100;

    //arrays de conjuntos.

    int conjuntoA[TAMANO_MAX], conjuntoB[TAMANO_MAX], unionSet[TAMANO_MAX]
    ,interseccionSet[TAMANO_MAX],diferenciaSet[TAMANO_MAX]
    ,diferenciaSetInverso[TAMANO_MAX],diferenciaSimetricaSet;


    //numeros de elementos de A,B...operados en funcion.
    int nA, nB, nUnion,ninterseccion,ndiferencia,ndiferenciaInverso,nDifereciaSimetrica;


    //ENTRADA DE DATOS A Y B
    leerConjunto(conjuntoA, nA, "A");
    leerConjunto(conjuntoB, nB, "B");
    //IMPRIMIR DATOS A Y B
    imprimirConjunto(conjuntoA, nA, "A");
    imprimirConjunto(conjuntoB, nB, "B");
    //UNION
    unionConjuntos(conjuntoA, nA, conjuntoB, nB, unionSet, nUnion);
    imprimirConjunto(unionSet, nUnion, "Union");
    //INTERSECCION
    interseccionConjuntos(conjuntoA,nA,conjuntoB,nB,interseccionSet,ninterseccion);
    imprimirConjunto(interseccionSet,ninterseccion,"Interseccion");
    //DIFERENCIA A-B
    diferenciaConjuntos(conjuntoA,nA,conjuntoB,nB,diferenciaSet,ndiferencia)
    imprimirConjunto(diferenciaSet,ndiferencia,"Diferencia de A-B");
    //DIFERENCIA B-A
    diferenciaConjuntosInverso(conjuntoA,nA,conjuntoB,nB,diferenciaSetInverso,ndiferenciaInverso)
    imprimirConjunto(diferenciaSetInverso,ndiferenciaInverso,"Diferencia de B-A");
    //DIFERENCIA SIMETRICA
    difereciaSimetrica(conjuntoA,nA,conjuntoB,nBdiferenciaSimetricaSet,nDifereciaSimetrica)
    imprimirConjunto(diferenciaSimetricaSet,nDifereciaSimetrica,"Diferencia simetrica");
    return 0;
}
