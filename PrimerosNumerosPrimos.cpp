/* Haga un programa que imprima los n primeros # primos */

#include<iostream>

using namespace std;

/* Teoria .
-Los numero primos son aquellos que solo tienen 2 divisores el 1  y ellos mismos
-Para saber si un numero grande es primo, necesitas aplicar el teorema que dice que :
Probar los divisores primos , hasta la raiz cuadrada del numero */



int primo(){
    /*  */
}
int main(int argc, char const *argv[])
{
    /* n numeros */
    long int n=0;
    /* el primer numero primo es 2  */
    long int Nprimo=2;
    /* contador para los primos */
    long int contador=0;
    cin>>n;
    /* condicionamos para que el n no sea 0 */
    if(n>0){
        /* Un bucle para los n primeros numeros primos  */
        for ( int i = 1; i <= n; i++)
        {
            /* Condiciones para que es un numero primo,dividible entre 1 y el mismo */
            if (Nprimo%1==0&&Nprimo%Nprimo==0)
            {
                
            }
            
            
        }
        cout<<Nprimo;
    }
    else{
        cout<<"Ingrese un numero o numero mayor a 0"<<endl;
    }
   
    /* Imprimir los primeros n primos  */
    
    primo();

    /* code */
    return 0;
}
