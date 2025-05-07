#include <iostream>
using namespace std;

// Función que calcula el factorial de un número
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // El factorial de 0 y 1 es 1
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

// Función que imprime el triángulo de Pascal hasta una cantidad de filas dada
void trianguloPascal(int filas) {
    //Para calcular las lineas del triangulo
    for (int line = 1; line <= filas; line++) {
        int C = 1; // valor inicial para cada línea
        //Para hallar los coeficientes
        for (int i = 1; i <= line; i++) {
            cout << C << " "; // Imprime el coeficiente binomial
            C = C * (line - i) / i;
        }
        cout << endl;
    }
}

// Función que imprime el binomio de Newton para (a + b)^n
void binomioDeNewton(int n) {
    for (int k = 0; k <= n; k++) {
        int coef = factorial(n) / (factorial(k) * factorial(n - k));
        cout << coef << " ";
    }
    cout << endl;
}

// Función que calcula la permutación sin repetición
int PermutacionSinRepeticion(int n, int r) {
    if (n < r) {
        return 0; // No es posible calcular permutaciones si n < r
    } else {
        return factorial(n) / factorial(n - r);
    }
}

// Función que calcula la permutación con repetición
int PermutacionConRepeticion(int n, int r) {
    int resultado = 1;
    for (int i = 0; i < r; i++) {
        resultado *= n; // Multiplica n por sí mismo r veces
    }
    return resultado;
}

// Función que calcula la combinación sin repetición
int Combinacion(int n, int r) {
    if (n < r) {
        return 0; // No es posible calcular combinaciones si n < r
    } else {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
}

// Función que calcula la combinación con repetición
int CombinacionConRepeticion(int n, int r) {
    return factorial(n + r - 1) / (factorial(r) * factorial(n - 1));
}

int main() {
    // Ejemplo de uso de las funciones
    cout<<"Ponga n>r, para mas resultados"<<endl;
    int n,r;
    cout<<"ingrese n y r "<<endl;
    cin>>n;
    cin>>r;
    int permSinRep = PermutacionSinRepeticion(n, r);
    int permConRep = PermutacionConRepeticion(n, r);
    int combinacion = Combinacion(n, r);
    int combinacionConRep = CombinacionConRepeticion(n, r);

    cout << "Permutacion sin repeticion("<<n<<","<<r<<") = " << permSinRep << endl;
    cout << "Permutacion con repeticion ("<<n<<","<<r<<") = " << permConRep << endl;
    cout << "Combinacion sin repeticion ("<<n<<","<<r<<") = " << combinacion << endl;
    cout << "Combinacion con repeticion ("<<n<<","<<r<<") = " << combinacionConRep << endl;
    cout << "Ingrese el numero de filas para el triangulo pascal:" << endl;
    int t;
    cin>>t;
    trianguloPascal(t);
    cout<<"Ingrese la potencia para calcular los coeficientes del binomio (a + b)^n:"<<endl;
    int p;
    cin >>p;
    binomioDeNewton(p);

    return 0;
}
