#include <iostream>
using namespace std;

// Función para ordenar un arreglo usando el algoritmo de Bubble Sort
void ordenamientoBurbuja(int arr[], int tamano, bool ascendente, int &ciclos)
{
    for (int i = 0; i < tamano - 1; ++i)
    {
        for (int j = 0; j < tamano - i - 1; ++j)
        {
            if ((ascendente && arr[j] > arr[j + 1]) || (!ascendente && arr[j] < arr[j + 1]))
            {
                // Intercambiar arr[j] y arr[j + 1] sin usar swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            ciclos++;
        }
    }
}

int main()
{

   int tamano;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tamano;

    int arr[tamano];
    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < tamano; ++i)
    {
        cin >> arr[i];
    }

    bool ascendente;
    cout << "Ordenar en forma ascendente (1) o descendente (0): ";
    cin >> ascendente;

    int ciclos = 0;
    ordenamientoBurbuja(arr, tamano, ascendente, ciclos);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < tamano; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Ciclos: " << ciclos << endl;

    return 0;

}
