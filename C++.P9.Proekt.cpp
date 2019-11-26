
#include <cstring>
#include <cassert>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;


class Matrica{
    friend std::ostream &operator<<(std::ostream &,const Matrica &);
    friend std::istream &operator>>(std::istream &,Matrica &);
private:
    int red;
    int kolona;
    int** ptr;
    static int vkupnoMatrici;
public:
    Matrica(int =5,int =5);
    Matrica operator+(Matrica m1);
    Matrica operator-(Matrica m1);
    Matrica operator*(Matrica m1);
    bool operator==(const Matrica&) const;
    const Matrica &operator=(const Matrica&);



};

int Matrica::vkupnoMatrici = 0;

bool Matrica::operator==(const Matrica &mat) const {
    if(kolona!=mat.kolona || red!=mat.red){
        return false;
    }
    for(int i=0;i<red;i++){
        for(int j=0;j<kolona;j++){
            if(ptr[i][j]!=mat.ptr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

const Matrica &Matrica::operator=(const Matrica &mat){
    if(&mat!=this){
        if(red!=mat.red || kolona!=mat.kolona){
            delete []ptr;
            kolona=mat.kolona;
            red=mat.red;
            ptr = new int*[kolona];
            for(int i=0;i<red;i++)
            {
                ptr[i] = new int[kolona];
            }
            assert(ptr!=0);

        }
        for(int i=0;i<red;i++){
            for(int j=0;j<kolona;j++){
                ptr[i][j] = mat.ptr[i][j];
            }
        }

    }
    return *this;
}

Matrica Matrica::operator+(Matrica m1){
    Matrica nova = Matrica(red,m1.kolona);
    if(red!=m1.red || kolona!=m1.kolona){
        cout<<"Dropkata ne e od isti red i kolona";
    }
    else {
        for(int i=0;i<red;i++){
            for(int j=0;j<kolona;j++){
                nova.ptr[i][j]=ptr[i][j]+m1.ptr[i][j];
            }
        }
    }
    return nova;
}

Matrica Matrica::operator-(Matrica m1){
    Matrica nova = Matrica(red,kolona);
    if(red!=m1.red || kolona!=m1.kolona){
        cout<<"Dropkata ne e od isti red i kolona";
    }
    else {
        for(int i=0;i<red;i++){
            for(int j=0;j<kolona;j++){
                nova.ptr[i][j]=ptr[i][j]-m1.ptr[i][j];
            }
        }
    }
    return nova;
}

Matrica Matrica::operator*(Matrica m1){
    Matrica nova = Matrica(red,m1.kolona);
    if(red!=m1.kolona){
        cout<<"Dropkata ne e od isti red od prvata matrica so kolonata od vtorata";
    }
    else {
        for(int i=0;i<red;i++){
            for(int j=0;j<m1.kolona;j++){
                nova.ptr[i][j]=0;
                for(int a=0;a<m1.red;a++){
                    nova.ptr[i][j]+=ptr[i][a]*m1.ptr[a][j];
                }
            }
        }
    }
    return nova;
}

Matrica::Matrica(int redM,int kolonaM){
    red = (redM>0 ? redM:5);
    kolona = (kolonaM>0 ? kolonaM:5);
    ptr = new int*[kolona];
    for(int i=0;i<red;i++)
    {
        ptr[i] = new int[kolona];
    }
    assert(ptr!=0);
    vkupnoMatrici++;
    for(int i=0;i<red;i++){
        for(int j=0;j<kolona;j++){
            ptr[i][j] = 0;
        }
    }
}

std::ostream &operator<<(std::ostream &output,const Matrica &a){
    for(int i=0;i<a.red;i++){
        for(int j=0;j<a.kolona;j++){
            output<<a.ptr[i][j]<<" ";
        }
        output<<endl;
    }
    return output;
}

std::istream &operator>>(std::istream &input,Matrica &a){
    for(int i=0;i<a.red;i++){
        for(int j=0;j<a.kolona;j++){
            cout << "Vnesi clen so red "<< i << " i kolona "<< j<<endl;
            input>>a.ptr[i][j];
        }
    }
    return input;
}

int main(){
    Matrica a = Matrica(2,2);
    Matrica b = Matrica(2,2);
    Matrica c = Matrica(2,2);
    cin>>a>>b;
    c=a*b;
    cout<<"a*b="<<endl;
    cout<<c;
    cout<<endl;
    c=a+b;
    cout<<"a+b="<<endl;
    cout<<c;
    cout<<endl;
    c=a-b;
    cout<<"a-b="<<endl;
    cout<<c;
    cout<<endl;
    c=a;
    cout<<"c=a: "<<endl;
    cout<<c;
    cout<<endl;

    cout<<"c==a: "<<endl;
    if(c==b){
        cout<<"a i c se isti";
    }
    else
    {
        cout<<"a i c ne se isti";
    }
    cout<<endl;


    return 0;


}
