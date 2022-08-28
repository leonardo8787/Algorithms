#ifndef LISTA_H_
#define LISTA_H_

#include<iostream>
#include<stdexcept>
using namespace std;
using std::logic_error;
using std::endl;

template <class T> class Lista {
    private:
        T **item;
        int primeiro, ultimo, pos, maxTam;
    public:
        Lista(int maxTam);
        T *pesquisa(const T& chave) const;
        void insere(const T& x) throw (logic_error);
        T *retira(const T& chave) throw (logic_error);
        T *retiraPrimeiro() throw (logic_error);
        T *_primeiro();
        T *proximo();
        bool vazia() const;
        void imprime() const;
        ~Lista();
};

template<class T> Lista<T>::Lista(int maxTam){
    this->item= new T*[maxTam];
    this->maxTam=maxTam;
    this->pos=-1;
    this->primeiro=0;
    this->ultimo=this->primeiro;
}

template<class T>T *Lista<T>::pesquisa(const T& chave) const {
    if(this->vazia()) return 0;
    for(int p=0; p<this->ultimo; p++)
        if(*(this->item[p]==chave) return this->item[p]);
    return 0;
}

template<class T> void Lista<T>::insere(const T& x) throw (logic_error){
    if(this->ultimo >= this->maxTam)
        throw logic_error("Erro: A lista esta cheia");
    this->item[this->ultimo]= new T(x);
    this->ultimo = this->ultimo + 1;
}

template<class T> T *Lista<T>::retira(const T& chave) throw (logic_error){
    if (this->vazia()) throw logic_error("Erro: A lista esta vazia");
    int p=0;
    while (p<this->ultimo && !(*(this->item[p]) == chave)) p++;
    if (p >= this->ultimo) return 0;
    T *item = this->item[p];
    this->item[p]=0;
    this->ultimo=this->ultimo-1;
    for(int aux=p; aux<this->ultimo; aux++)
        this->item[aux]=this->item[aux+1];
    return item;
}

template<class T> T *Lista<T>::retiraPrimeiro () throw (logic_error) {
    if (this->vazia()) throw logic_error("Erro: A lista esta vazia");
    T *item = this->item[p];
    this->item[p]=0;
    this->ultimo=this->ultimo-1;
    for(int aux=p; aux<this->ultimo; aux++)
        this->item[aux]=this->item[aux+1];
    return item;
}

template<class T> T *Lista<T>::_primeiro(){
    this->pos=-1;
    return this->proximo();
}

template<class T>T *Lista<T>::proximo(){
    this->pos++;
    if(this->pos>=this->ultimo) return NULL;
    else return this->item[this->pos];
}

template<class T>bool Lista<T>::vazia() const {
    return (this->primeiro == this->ultimo);
}

template<class T> void Lista<T>::imprime() const {
    for(int i=this->primeiro; i<this->ultimo; i++)
        cout<<*(this->item[i])<<endl;
}

template<class T> Lista<T>::~Lista() {
    for (int i= this->primeiro; i<this->ultimo; i++) delete item[i];
    delete[] item;
}

#endif 