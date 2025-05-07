#include<iostream>
#include<conio.h>
#include<math.h>


using namespace std;

double Formula(int a,int b){
    double x;
    if(a+20<0||b==0)
        return -1;
    x=(sqrt(a+20)/(2*b))*a;
    return x;
}

int main(int argc, char const *argv[])
{
    cout<<Formula(5,8);
    getch();
    return 0;
}

