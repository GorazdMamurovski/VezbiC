#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class T>

void sort(T *niza,const int clena){
    for(int i=0;i<clena;i++){
        for(int j=i;j<clena;j++){
            if(niza[i]>niza[j]){
                T temp;
                temp = niza[i];
                niza[i]=niza[j];
                niza[j]=temp;
            }
        }
    }
}

int main(){
    int a[10] = {3,5,1,2,4,6,8,9,7,10};

    float b[10] = {1.2,2.4,3,5,6.7,4.3,5.2,8,10,9};

    cout<<"Pred sort";
    cout<<endl;
    cout<<"Niza int";
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Niza float";
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    sort(a,10);
    sort(b,10);
    cout<<endl;
    cout<<"Posle sort";
    cout<<endl;
    cout<<"Niza int";
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Niza float";
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
