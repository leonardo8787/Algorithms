#include<iostream>
using namespace std;

#include "fibonacci.hpp"

int main(){
    system("cls||clear");
    cout<<"Método recursivo para calcular a sequência de Fibonacci"<<endl;
    cout<<"Leonardo Campos - CEFET"<<endl;
    int n;
    cout<<"\nDigite um limite para a sequência de Fibonacci"<<endl;
    cin>>n;
    Fibonacci x;
    cout<<x.fibRec(n)<<endl;
    return 0;
}