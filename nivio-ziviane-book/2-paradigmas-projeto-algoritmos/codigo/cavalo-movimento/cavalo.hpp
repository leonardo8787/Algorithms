#ifndef PASSEIOCAVALO_H
#define PASSEIOCAVALO_H

#include<iostream>
using namespace std;

class PasseioCavalo {
    private: 
        int n;
        int *a, *b, **t;
    public:
        PasseioCavalo(int n);
        bool tenta(int i, int x, int y);
        void imprimePasseio() const;
        static void main();
        ~PasseioCavalo();
};

PasseioCavalo::PasseioCavalo(int n){
    this->n=n;
    this->t=new int *[n];
    for(int i=0; i<n; i++) this->t[i]= new int[n];
    this->a=new int[n]; this->b=new int[n];
    a[0]=2; a[1]=1; a[2]=-1; a[3]=-2;
    a[0]=1; b[1]=2; b[2]=2; b[3]=1;
    a[4]=-2; a[5]=-1; a[6]=1; a[7]=2;
    a[4]=-1; a[5]=-2; b[6]=-2; b[7]=-1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) t[i][j]=0;
    t[0][0]=1;
}

PasseioCavalo::~PasseioCavalo(){
    delete []a; delete []b;
    for(int i=0; i<n; i++) delete []this->t[i];
    delete []this->t;
}

bool PasseioCavalo::tenta(int i, int x, int y){
    int u, v, k; bool q;
    k=-1;
    do{
        k=k+1; q=false;
        u=x+a[k]; v=y+b[k];
        if((u>=0)&&(u<=7)&&(v>=0)&&(v<=7))
            if(t[u][v]==0){
                t[u][v]=i;
                if(i<n*n){
                    q=tenta(i+1,u,v);
                    if(!q) t[u][v]=0;
                }
                else q=true;
            }
    } while (!q && (k!=7));
    return q;
}

void PasseioCavalo::imprimePasseio() const {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "\t" << this->t[i][j];
        } 
        cout<<endl;
    }
}

void PasseioCavalo::main(){
    PasseioCavalo PasseioCavalo(8);
    bool q=PasseioCavalo.tenta(2,0,0);
    if (q) PasseioCavalo.imprimePasseio();
    else cout<<"Sem solucao"<<endl;
}

#endif