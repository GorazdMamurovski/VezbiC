#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;


class Dropki
{
public:
    Dropki(int b = 1,int i=1);
    void pecatiN();
    Dropki soberD(Dropki a);
    Dropki podeliD(Dropki a);
    Dropki odezmiD(Dropki a);
    Dropki mnoziD(Dropki a);
    int vratiIm();
    int vratiBr();
    void pecatiR();

private:
    int broitel;
    int imenitel;
};

int Dropki::vratiIm(){
    return imenitel;
}

int Dropki::vratiBr(){
    return broitel;
}

Dropki Dropki::soberD(Dropki a){
    int broitelZ = 0;
    int imenitelZ = 0;
    imenitelZ = imenitel*a.vratiIm();
    broitelZ = (broitel*(imenitelZ/imenitel))+(a.vratiBr()*(imenitelZ/a.vratiIm()));
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::podeliD(Dropki a){
    int broitelZ = 0;
    int imenitelZ = 0;
    broitelZ = broitel*a.vratiIm();
    imenitelZ = imenitel*a.vratiBr();
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::odezmiD(Dropki a){
    int broitelZ = 0;
    int imenitelZ = 0;
    imenitelZ = imenitel*a.vratiIm();
    broitelZ = (broitel*(imenitelZ/imenitel))-(a.vratiBr()*(imenitelZ/a.vratiIm()));
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::mnoziD(Dropki a){
    int broitelZ = 0;
    int imenitelZ = 0;
    broitelZ = broitel*a.vratiBr();
    imenitelZ = imenitel*a.vratiIm();
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}
void Dropki::pecatiR(){
    if(broitel==-1 && imenitel==-1){
        cout<<"Ne se deli so 0"<<endl;
    }
    else
    {
        float rez = ((float)broitel/imenitel);
        cout <<rez <<endl;
    }
}
void Dropki::pecatiN(){
    if(broitel==-1 && imenitel==-1){
        cout<<"Ne se deli so 0"<<endl;
    }
    else
    {
        cout << broitel << "/" <<imenitel <<endl;
    }
}
Dropki::Dropki(int i,int m){
    if(m==0)
    {
        broitel=-1;
        imenitel=-1;
    }
    else
    {
        int broi;
        int im;
        broitel=i;
        imenitel=m;
        broi=broitel;
        im=imenitel;
        if(i>=m)
        {
            for(int s=1;s<i;s++)
            {
                if(broitel%s==0 && imenitel%s==0)
                {

                    broitel/=s;
                    imenitel/=s;
                }
            }
        }
        else{
            for(int s=1;s<m;s++)
            {
                if(broitel%s==0 && imenitel%s==0)
                {
                    broitel/=s;
                    imenitel/=s;

                }
            }
        }
    }
}

int main()
{
    int a,b,c,d;
    cout<<"Vnesi imenitel i broitel za dropka 1"<<endl;
    cin>>a>>b;
    cout<<"Vnesi imenitel i broitel za dropka 2"<<endl;
    cin>>c>>d;
    Dropki dropka1(a,b),dropka2(c,d),dropka3;
    dropka1.pecatiN();
    dropka1.pecatiR();
    dropka2.pecatiN();
    dropka2.pecatiR();
    dropka3 = dropka1.soberD(dropka2);
    dropka3.pecatiN();
    dropka3 = dropka1.mnoziD(dropka2);
    dropka3.pecatiN();
    dropka3 = dropka1.odezmiD(dropka2);
    dropka3.pecatiN();
    dropka3 = dropka1.podeliD(dropka2);
    dropka3.pecatiN();
}

