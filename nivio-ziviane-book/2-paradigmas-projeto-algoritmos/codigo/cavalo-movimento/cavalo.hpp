#ifndef PASSEIOCAVALO_H
#define PASSEIOCAVALO_H

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
    //continua...
}

#endif