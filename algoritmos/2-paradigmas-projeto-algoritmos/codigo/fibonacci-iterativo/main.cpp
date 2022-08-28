#include<iostream>
using namespace std;

#include "fibonacci.hpp"

int main(){
    int n;
    system("cls || clear");
    cout<<"Leonardo Campos - CEFET-MG"<<endl;
    cout<<"Digite um limite para sequência de Fibonacci: "<<endl;
    cin>>n;
    
    Fibonacci x;

    x.fibIter(n);

    return 0;
}