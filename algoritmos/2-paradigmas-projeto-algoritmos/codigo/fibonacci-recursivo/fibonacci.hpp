#ifndef FIBONACCI_H
#define FIBONACCI_H

class Fibonacci {
    public:
        static int fibRec (int n);
};
int Fibonacci::fibRec(int n){
    if(n<2) return n;
    else return fibRec(n-1)+fibRec(n-2);
}

#endif