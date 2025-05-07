
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int opcion;
	cout << "   SISTEMA DE CONVERSION DE BASE 2-10" << endl;
	cout << "1. Convertir de base 10 a n base" << endl;
	cout << "2. Convertir de base n  a base 10" << endl;
	cout<< "----Seleccione una opcion:" << endl;
	cout<<"=> ";
	cin >> opcion;
	cout<<""<<endl<<endl;

	switch (opcion)
	{
	case 1:
	{
		int decimal, base;
		cout << "Ingrese el decimal: ";
		cin >> decimal;
		cout << "Ingrese la base: ";
		cin >> base;

		// condicion, mayor que 2
		if (base < 2 || base > 10)
		{
			cout << "La base debe estar en el rango de 2 a 10." << endl;
			return 1;
		}
		// Crear un arreglo para almacenar los residuos
		int residuos[100];
		int cont = 0;

		while (decimal > 0)
		{
			int cociente = decimal / base;
			int residuo = decimal % base;

			// Almacenar el residuo en el arreglo
			residuos[cont] = residuo;
			cont++;

			// Actualizar el dividendo para la siguiente iteración
			decimal = cociente;
		}

		// Imprimir los residuos en orden inverso
		cout << "El numero en base " << base << " es: ";
		for (int i = cont - 1; i >= 0; i--)
		{
			cout << residuos[i];
		}
		cout << endl;

		break;
	}



	case 2:
	{
		int numero, resultado = 0, base, posicion = 0;
		cout << "Ingrese la base: ";
		cin>>base;
		cout << "Ingrese el numero: ";
		cin >> numero;
		// Verificar que el divisor esté en el rango correcto
		if (base < 2 || base > 10)
		{
			cout << "La base debe estar en el rango de 2 a 10." << endl;
			return 1;
		}
		// Separar los dígitos para poder operar
		while (numero > 0)
		{
			// Módulo
			int digito = numero % 10;

			if (digito >= base){
				cout<<"Error los digitos no deven ser mayor o igual a la base";
				return 1;
			}

			// Operación
			resultado += digito * pow(base, posicion);


			numero /= 10;

			posicion++;
		}
		cout << "El numero en base "<< base<< " a decimal es: "<< resultado << endl;

		break;
	}

	default:
		cout << "Opción no válida, escoja entre la opcion 1 o 2" << endl;
		break;
	}

	return 0;
}
