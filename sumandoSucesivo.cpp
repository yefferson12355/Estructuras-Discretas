#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Ingrese un numero n: ";
    cin >> n;

    int suma = 0;
    for (int i = 1; i <= n; i++) {
        cout << i;
        if (i < n) {
            cout << "+";
        }
        suma += i;
    }

    cout << " = " << suma << endl;

    return 0;
}
