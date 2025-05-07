#include<iostream>
#include<conio.h>
#define NOEXISTE -12345

using namespace std;
/* Funcion raiz */
double Raiz2(double num){
    double raiz=0;

    if (num<0)
    {
        return NOEXISTE;
    }
    while(raiz*raiz<=num){
        raiz+=0.00001;
    }
    return raiz;  
} 


int main(int argc, char const *argv[])
{
    double n=7;
    cout<<"La raiz de "<<n<<" es:";
    cout<<Raiz2(n);
    getch();
    return 0;
}
