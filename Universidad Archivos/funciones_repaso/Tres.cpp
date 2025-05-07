#include<iostream>
#include<conio.h>

using namespace std;

double Sumatoria(int a,int b){
    long r;
    int i;
    int X[100];
    cout<<"Ingreso de datos a la matriz :"<<endl;
    for ( i = 0; i < a+b; i++)
    {
        cout<<"X["<<i+1<<"]=";
        cin>>X[i];

    }
    cout<<"La sumatoria es: ";
    for ( i = 0,r=0;i < a+b;i++)
    {
        r=r+X[i]+a*b;
    }
    return(r/(double)(a+b));
    
    
        
}

int main(int argc, char const *argv[])
{
    int a=4;
    int b=6;
    cout<<Sumatoria(a,b);
    return 0;
}
