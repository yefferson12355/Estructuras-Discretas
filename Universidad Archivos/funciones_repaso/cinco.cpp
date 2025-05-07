#include<iostream>
#include<conio.h>


using namespace std;

long Factorial(int n){
    long fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int main(int argc, char const *argv[])
{
    int n=10;
    cout<<"El factorial de "<<n<<"es: ";
    cout<<Factorial(n);
    getch();
    return 0;
}
