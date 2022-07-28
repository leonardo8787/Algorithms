#ifndef FIBONACCI_H
#define FIBONACCI_H

class Fibonacci {
    public:
        static int fibIter(int n);
};    
int Fibonacci::fibIter(int n){
    int i=1, f=0;
    for(int k=1;k<=n;k++){
        f=i+f;
        i=f-i;
        cout<<f<<" ";
    }
    return f;
}

#endif