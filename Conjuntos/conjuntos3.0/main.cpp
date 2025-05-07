#include <iostream>
#include <math.h>

using namespace std;


/*Programa(s) de unión, intersección, diferencia y diferencia simétrica de 2 conjuntos cuyos elementos son los números enteros positivos.*/
array conjuntoA(){
        int n1;
        cout << "Ingrese el numero de elementos para el conjunto A (con espacion):" << endl;
        cin >> n1;
        int num1[n1];

        for (int i = 0; i < n1; i++)
        {
        cin >> num1[i];
        }

        for (int i = 0; i < n1; i++)
        {
            cout << num1[i]<<endl;
        }
    return num1[n1],num2[n2];
    }

void conjuntoB(){
        int n2;
        cout << "Ingrese el numero de elementos para el conjunto A (con espacios):" << endl;
        cin >> n2;
        int num2[n2];

        for (int i = 0; i < n2; i++)
        {
        cin >> num2[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cout << num2[i]<<endl;
        }
    }
void darvalor(int X,int Y){
    n1=X;
    n2=Y;

}
int Union(int x,int y) {
    //array vector;
    int unionn[x+y];
    for(int i=0;i<x+y;i++{

    }

}
int Interseccion() {

}
int diferencia() {

}
int diferenciaSimetrica() {


}




int main() {
    conjuntoA();
    conjuntoB();


return 0;
}




/*
#include <iostream>
using namespace std;

void sumarArrays(int arr1[], int arr2[], int resultado[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        resultado[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {6, 7, 8, 9, 10};
    int sumaArray[5];

    sumarArrays(array1, array2, sumaArray, 5);

    for (int i = 0; i < 5; i++) {
        cout << sumaArray[i] << " ";  // Imprime el resultado de la suma
    }

    return 0;
}
*/
