#include "maxMin.hpp"

int main(){
    system("cls || clear");
    cout<<"Melhor algoritmo para encontrar máximos e mínimos"<<endl;
    cout<<"Leonardo Campos - CEFET-MG"<<endl;
    int v[]={8,2,6,5,2}, n=5;

    MaxMin3 x;

    x.maxMin3(v,n);

    return 0;
}