#ifndef MAXMIMREF_H
#define MAXMIMREF_H

#include<iostream>
using namespace std;

class MaxMin4 {
    public:
        static int *maxMin4(int v[], int linf, int lsup);
};

int* MaxMin4::maxMin4(int v[], int linf, int lsup){
    int *maxMin = new int[2];
    if(lsup-linf <= 1){
        if(v[linf]<v[lsup]) { maxMin[0]=v[lsup]; maxMin[1]=v[linf];}
        else {maxMin[0]=v[linf]; maxMin[1]=v[lsup];}
    }
    else {
        int meio = (linf + lsup)/2;
        if (maxMin) delete []maxMin;
        maxMin = maxMin4(v, linf, meio);
        int max1=maxMin[0], min1=maxMin[1];
        delete []maxMin;
        maxMin = maxMin4(v, meio + 1, lsup);
        int max2 = maxMin[0], min2=maxMin[1];
        if(max1 > max2) maxMin[0] = max1; else maxMin[0] = max2;
        if(min1 < min2) maxMin[1] = min1; else maxMin[1] = min2;
    }

    return maxMin;
}

#endif 