#include <iostream>
using namespace std;

int main()
{
	int n;
	float a = 0, sa = 0, sar = 0;
	cout << "Introduce el n-esimo termino de las suceciones: ";
	cin >> n;


	cout << "La sucesion #aritmetica# es: ";
	for (int i = 1; i <= n; i++)
	{
		a = i + a;
		cout << a;
		sa = a + sa;
		if (i < n)
		{
			cout << " + ";
		}
	}
	cout << " = " << sa << endl;

	// Sucesión armónica
	cout << "La sucesion #armonica# es: ";
	for (int i = 1; i <= n; i++)
	{
		sar += 1.0 / i;
		cout << "1/" << i;
		if (i < n)
		{
			cout << " + ";
		}
	}
	cout << " = " << sar << endl;

	// Sucesión de Fibonacci
	cout << "La sucesion de #Fibonacci# es: ";
	int x = 0, y = 1, z, sf = 0;
	if (n >= 1)
	{
		cout << x;
		sf = x;
	}
	if (n >= 2)
	{
		cout << " + " << y;
		sf = y + sf;
	}
	for (int i = 3; i <= n; i++)
	{
		z = x + y;
		cout << " + " << z;
		sf = z + sf;
		x = y;
		y = z;
	}
	cout << " = " << sf << endl;


	cout << "La sucesion de #Lucas# es: ";
	int l1 = 2, l2 = 1, l3, sl = 0;
	if (n >= 1)
	{
		cout << l1;
		sl = l1;
	}
	if (n >= 2)
	{
		cout << " + " << l2;
		sl = l2 + sl;
	}
	for (int i = 3; i <= n; i++)
	{
		l3 = l1 + l2;
		cout << " + " << l3;
		sl = l3 + sl;
		l1 = l2;
		l2 = l3;
	}
	cout << " = " << sl << endl;

	return 0;
}
