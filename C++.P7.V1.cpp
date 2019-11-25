#include <iostream>

using std::cout;
using std::endl;

#include <cstring>
#include <cassert>

class Dropki{
    int broitel;
    int imenitel;
public:
    Dropki();
    Dropki(int i,int m);
    friend std::ostream &operator<<(std::ostream &out,const Dropki &d);
    Dropki operator+(Dropki d1);
    Dropki operator-(Dropki d1);
    Dropki operator*(Dropki d1);
    Dropki operator/(Dropki d1);
    Dropki operator+(int a);
    Dropki operator-(int a);
    Dropki operator*(int a);
    Dropki operator/(int a);
};

Dropki::Dropki(){
    imenitel=1;
    broitel=1;
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

Dropki Dropki::operator+(Dropki d1){
    int broitelZ = 0;
    int imenitelZ = 0;
    imenitelZ = imenitel*d1.imenitel;
    broitelZ = (broitel*(imenitelZ/imenitel))+(d1.broitel*(imenitelZ/d1.imenitel));
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::operator-(Dropki d1){
    int broitelZ = 0;
    int imenitelZ = 0;
    imenitelZ = imenitel*d1.imenitel;
    broitelZ = (broitel*(imenitelZ/imenitel))-(d1.broitel*(imenitelZ/d1.imenitel));
    Dropki razlika(broitelZ,imenitelZ);
    return razlika;
}

Dropki Dropki::operator*(Dropki d1){
    int broitelZ = 0;
    int imenitelZ = 0;
    broitelZ = broitel*d1.broitel;
    imenitelZ = imenitel*d1.imenitel;
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::operator/(Dropki d1){
    int broitelZ = 0;
    int imenitelZ = 0;
    broitelZ = broitel*d1.imenitel;
    imenitelZ = imenitel*d1.broitel;
    Dropki delenje(broitelZ,imenitelZ);
    return delenje;
}


Dropki Dropki::operator+(int a){
    int broitelZ = a*imenitel;
    int imenitelZ = imenitel;
    broitelZ=broitelZ+broitel;
    Dropki zbir(broitelZ,imenitelZ);
    return zbir;
}

Dropki Dropki::operator-(int a){
    int broitelZ = a*imenitel;
    int imenitelZ = imenitel;
    broitelZ=broitelZ-broitel;
    Dropki razlika(broitelZ,imenitelZ);
    return razlika;
}

Dropki Dropki::operator*(int a){
    int broitelZ = broitel;
    int imenitelZ = imenitel;
    Dropki mnozenje(broitelZ*a,imenitelZ);
    return mnozenje;
}

Dropki Dropki::operator/(int a){
    int broitelZ = imenitel*a;
    int imenitelZ = broitel;
    Dropki delenje(broitelZ,imenitelZ);
    return delenje;
}


std::ostream & operator<<(std::ostream &out,const Dropki &d){
    out << d.broitel <<"/"<<d.imenitel;
    return out;
}

int main(){
    Dropki d1(2,4),d2(2,8),d3;
    cout<<"Dropkata d1 e "<<d1<<" Dropkata d2 e "<<d2<<endl;
    d3=d1+d2;
    cout <<" d1+d2 "<< d3<<endl;
    d3=d1*d2;
    cout<<" d1*d2 "<<d3<<endl;
    d3=d1/d2;
    cout<<" d1/d2 "<<d3<<endl;
    d3=d1-d2;
    cout<<" d1-d2 "<<d3<<endl;
    d3=d1*3;
    cout<<" d1*3 "<<d3<<endl;
    d3=d1+3;
    cout<<" d1+3 "<<d3<<endl;
    d3=d1-3;
    cout<<" d1-3 "<<d3<<endl;
    d3=d1/3;
    cout<<" d1/3 "<<d3<<endl;
    return 0;
}
