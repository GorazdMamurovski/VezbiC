#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <numeric>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Motor{
public:
    Motor();
};

Motor::Motor() throw (runtime_error){
    throw runtime_error("Motor error");
}


class Avtomobil : public Motor{
public:
    Avtomobil();
};

Avtomobil::Avtomobil():Motor(){

}

class Garaza: public Avtomobil{
public:
    Garaza();
};

Garaza::Garaza() : Avtomobil(){
    try {

    } catch (runtime_error &error) {
        throw runtime_error("main error");
        cout<<"Error "<<error.what()<<endl;
    }
}

int main(){
    try {
        Garaza g;
    } catch (runtime_error &error) {
        cout<<"Main error "<<error.what()<<endl;
    }

    return 0;
}
