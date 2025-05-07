#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;
/*Funcion de la formula. */
double Formula(double a ,double b){

    if (a>=30&&b!=0&&a!=0){
        return (sqrt((a+30)/(2*b))*a+b/a);
    }
    
}

int main(int argc, char const *argv[])
{
    cout<<"El resultado es: "<<endl;
    cout<<Formula(32,5);
    getch();
    return 0;
}
