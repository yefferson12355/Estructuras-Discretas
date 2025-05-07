#include<iostream>
#include<conio.h>
#include<math.h>


using namespace std;

long Sumatoria(int n){
    
    long s=0;

    for (int i = 1; i <=n ; i++)
    {
        s=s+(n+i*10+2);
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int n=3;
    cout<<"La suma es:"<<endl;
    cout<<Sumatoria(n);
    getch();
    return 0;
}
