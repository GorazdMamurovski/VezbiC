#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Oblik{
public:
    virtual string getName() const=0;
    virtual void print() const =0;
};

class DvoDimenzionalni:public Oblik{
    virtual double plostina() const;

};

double DvoDimenzionalni::plostina() const{
    return 0.0;
}

class TroDimenzionalni:public DvoDimenzionalni{
    virtual double volumen() const;
};

double TroDimenzionalni::volumen() const{
    return 0.0;
}

class Kvadrat:public DvoDimenzionalni{
private:
    double a;
public:
    Kvadrat(double a);
    virtual double plostina() const;
    virtual string getName() const;
    virtual void print() const ;
};

Kvadrat::Kvadrat(double broj){
    a=broj;
}


double Kvadrat::plostina() const{
    return a*a;
}

string Kvadrat::getName() const{
    return "Kvadrat";
}

void Kvadrat::print() const{
    cout<<"Kvadratot so strana "<<a<<" ima plostina "<<Kvadrat::plostina()<<endl;
}

class Triagolnik:public DvoDimenzionalni{
private:
    double a,b,c;
    double visina;
public:
    Triagolnik(double r,double h);
    Triagolnik(double r,double g,double h);
    Triagolnik(double r,double g,double m,double h);
    virtual double plostina() const;
    virtual string getName() const;
    virtual void print() const ;
};

Triagolnik::Triagolnik(double s,double h){
    a=s;
    b=s;
    c=s;
    visina =h;
}

Triagolnik::Triagolnik(double s,double g,double h){
    a=s;
    b=s;
    c=g;
    visina =h;
}

Triagolnik::Triagolnik(double s,double g,double m,double h){
    a=s;
    b=g;
    c=m;
    visina =h;
}

double Triagolnik::plostina() const{
    return (b*0.5)*visina;
}

string Triagolnik::getName() const{
    return "Triagolnik";
}

void Triagolnik::print() const{
    cout<<"Triagolnikot so strani "<<a<<" "<<b<<" "<<c<<" i visina "<<visina<<" ima plostina "<<plostina()<<endl;
}


class Krug:public DvoDimenzionalni{
private:
    double radius;
public:
    Krug(double r);
    double getDiametar() const;
    double getCircumference() const;
    virtual double plostina() const;
    virtual string getName() const;
    virtual void print() const ;
};

Krug::Krug(double r){
    radius=r;
}

double Krug::getDiametar() const{
    return 2*radius;
}

double Krug::getCircumference() const{
    return 3.14159 * getDiametar();
}

double Krug::plostina() const{
    return 3.14159 * radius * radius;
}

string Krug::getName() const{
    return "Krug";
}

void Krug::print() const{
    cout<<"Krugot so radius "<<radius<<" ima plostina "<<plostina()<<endl;
}

class Kocka:public Kvadrat{
private:
    double strana;
public:
    Kocka(double a);
    virtual double plostina() const;
    virtual double volumen() const;
    virtual string getName() const;
    virtual void print() const ;
};

Kocka::Kocka(double a):Kvadrat(a){
    strana=a;
}

double Kocka::plostina() const{
    return 6*Kvadrat::plostina();
}

double Kocka::volumen() const{
    return strana*strana*strana;
}

string Kocka::getName() const{
    return "Kocka";
}

void Kocka::print() const{
    Kvadrat::print();
    cout<<"Kockata so strana "<<strana<<" ima plostina "<<Kocka::plostina()<<" i volumen "<<Kocka::volumen()<<endl;
}

class Cilinder:public Krug{
private:
    double visina;
public:
    Cilinder(double r,double h);
    virtual double plostina() const;
    virtual double volumen() const;
    virtual string getName() const;
    virtual void print() const ;
};

Cilinder::Cilinder(double r,double h):Krug(r){
    visina=h;
}

double Cilinder::plostina() const{
    return 2*Krug::plostina() + getCircumference()*visina;
}

double Cilinder::volumen() const{
    return Krug::plostina()*visina;
}

string Cilinder::getName() const{
    return "Cilinder";
}

void Cilinder::print() const{
    Krug::print();
    cout<<"Cilinderot so visina "<<visina<<" ima plostina "<<plostina()<<" i volumen "<<volumen()<<endl;
}

class Topka:public TroDimenzionalni{
private:
    double radius;
public:
    Topka(double r);
    virtual double plostina() const;
    virtual double volumen() const;
    virtual string getName() const;
    virtual void print() const ;
};

Topka::Topka(double r){
    radius=r;
}

double Topka::plostina() const{
    return 4*(radius*radius)*3.14159;
}

double Topka::volumen() const{
    return (4*(radius*radius*radius)*3.14159)/3;
}

string Topka::getName() const{
    return "Topka";
}

void Topka::print() const{
    cout<<"Topkata so radius "<<radius<<" ima plostina "<<plostina()<<" i volumen "<<volumen()<<endl;
}

int main(){
    Kocka kocka(3);
    kocka.print();
    Triagolnik triagolnik(5,5);
    triagolnik.print();
    Kvadrat kvadrat(5);
    kvadrat.print();
    Krug krug(5);
    Cilinder cilinder(3.3,10);
    cilinder.print();
    krug.print();
    Topka topka(3.2);
    topka.print();

    return 0;
}
