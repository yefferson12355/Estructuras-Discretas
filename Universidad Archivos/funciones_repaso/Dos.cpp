#include<iostream>
#include<conio.h>

using namespace std;

long Sumatoria(int n){
    long r;
    int i;
    for ( r=0,i = 1; i <=n; i++)
    {
        r=r+10*i+2;
    }
    return r;
    
}

int main(int argc, char const *argv[])
{
    cout<<Sumatoria(3);
    getch();
    return 0;
}
