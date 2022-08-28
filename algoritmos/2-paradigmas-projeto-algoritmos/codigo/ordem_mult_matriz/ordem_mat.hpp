#ifndef ORDEMMAT_H
#define ORDEMMAT_H

#include<iostream>
using namespace std;

class AvaliaMultMatrizes {
    public:
        static void main (int argc, char **argv);
};

void AvaliaMultMatrizes::main(int argc, char **argv){
    int n, maxn = atoi(argv[1]);
    int d[maxn + 1];
    int m[maxn][maxn];
    cout<<"Número de matrizes n:"; cin>>n;
    cout<<"Dimensões das matrizes:"<<endl;
    for(int i=0; i<=n; i++){
        cout<<" d[" << i<< "] = "; cin>>d[i];
    }
    for(int i=0; i<n; i++) m[i][i]=0;
    for(int h=1; h<n; h++){
        for(int i=1; i<= n-h; i++){
            int j=1+h;
            m[i-1][j-1] = INT_MAX;
            for(int k=i; k<j; k++){
                int temp=m[i-1][k-1] + m[k][j-1] + d[i-1]*d[k]*d[j];
                if (temp < m[i-1][j-1]) m[i-1][j-1]=temp;
            }
            cout << " m[" << i << "][" << j << "[="<<m[i-1][j-1];
        }
        cout<<endl;
    }
}

#endif 