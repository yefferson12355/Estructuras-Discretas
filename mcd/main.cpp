#include <iostream>

using namespace std;

// Función para encontrar el MCD y los coeficientes s y t, y además guardar los pasos de igualaciones
int mcdExtendido(int x, int y, int &s, int &t, int &r, int &q) {
    if (y == 0) {
        s = 1;
        t = 0;
        return x;
    }
    int s1, t1, r1, q1;
    int mcd = mcdExtendido(y, x % y, s1, t1, r1, q1);
    s = t1;
    t = s1 - (x / y) * t1;
    r = r1;
    q = q1 - (x / y) * r1;
    return mcd;
}

// Función para calcular el MCM
int mcm(int x, int y) {
    int s, t, r, q;
    int mcd = mcdExtendido(x, y, s, t, r, q);
    return (x * y) / mcd;
}

int main() {

    int x ;
    int y ;
    cout<<"Ingrese x e y "<<endl;
    cin>>x>>y;
    int s, t, r, q;

    int mcd = mcdExtendido(x, y, s, t, r, q);
    int valorMCM = mcm(x, y);

    cout << "MCD(" << x << ", " << y << ") = " << mcd << endl;
    cout << "s = " << s << ", t = " << t << endl;

    cout << "MCM(" << x << ", " << y << ") = " << valorMCM << endl;

    return 0;
}
