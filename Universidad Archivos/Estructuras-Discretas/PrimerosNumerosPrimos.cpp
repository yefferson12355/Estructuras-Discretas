/* Haga un programa que imprima los n primeros # primos */

#include<iostream>

using namespace std;

/* Teoria .
-Los numero primos son aquellos que solo tienen 2 divisores el 1  y ellos mismos
-Para saber si un numero grande es primo, necesitas aplicar el teorema que dice que :
Probar los divisores primos , hasta la raiz cuadrada del numero */


/* funcion si es primo queremos que valga verdad, si es verdad se imprime , si es falso nose ejeculta con el if de la funcion principal.*/
bool primo(int p){
    /* la condicion es verdadera,por ahora por eso continia */
    bool condicion;
    /* no tiene que ser 1 ni 0 */
    if (p !=1 && p!=0)
    {
        /* comenzamos con el 2 por que, los numeros 1 y 0 ya estan descartados, no son  primos*/
       for (int  i = 2; i <=p; i++)
       {
            /* si la variable n es divisible con i  */
            if (p % i ==0)
            {
                /* si p es igual al mismo el dibisible entonce es verdad  */
                if(p == i)
                {
                    
                    condicion = true;
                }
                /* */
                else
                {
                    condicion = false;
                    return condicion;
                }
            }
       }
    }
    /* si es uno o cero vamos a pedirle que nos mande un falso y no se imprimira el numero , */ 
    else condicion = false;

    return condicion;
    
}
int main()
{
    /* n numeros */
    int n;
    /* ingrese hasta que numero buscar  */
    cin>>n;
    /* para ir recorriendo todos los numeros , si es un numero primo, o no lo es */
    for ( int i = 1; i <= n; i++)
    {
       /* llamamo funcion primo. Imprimir en pantalla un numero, en caso que sea primo , mande a imprimir i ...si es numero primo imprime  */
        if (primo(i)){
            cout<<i<<endl;  
        }  
    }
    return 0;
}
