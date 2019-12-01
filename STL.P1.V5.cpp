#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class T>

class Array{
private:
    T *niza;
    int golemina;
public:
    Array(T *nizaIn,int size);
    void pecatiEle(int elM);
    void smestiEle(int elM, T element);
    void print();
};

template <class T>
Array<T>::Array(T *nizaIn,int size){
    golemina=size;
    niza = new T[size];
    for(int i=0;i<size;i++){
        niza[i]=nizaIn[i];
    }

}

template <class T>
void Array<T>::pecatiEle(int elM){
    cout<<niza[elM];
    cout<<endl;
}

template <class T>
void Array<T>::smestiEle(int elM, T element){
    niza[elM] = element;
}

template <class T>
void Array<T>::print(){
    for(int i=0;i<golemina;i++){
        cout<<niza[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int niza[5]= {1,2,3,4,5};
    float nizaF[5] = {1.1,2.2,3.3,4.4,5.5};
    Array<float> arrayF(nizaF,5);
    arrayF.pecatiEle(3);
    arrayF.smestiEle(3,1000);
    arrayF.pecatiEle(3);
    Array<int> array(niza,5);
    array.print();
    arrayF.print();
    return 0;
}
