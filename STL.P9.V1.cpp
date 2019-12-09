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



class ApogolemoB : public exception {
public:
   ApogolemoB::ApogolemoB()
      : exception( "obid za delenje so nula" ) {}
};

void proverka(int a,int b){
    if(a>b){
        throw ApogolemoB();
    }
}

int main(){
    srand(time(0));
    std::vector< int > v1;

    for(int x=0;x<rand()%9999;x++){
        v1.push_back(x);
    }

    std::vector< int > v2;

    for(int x=0;x<rand()%9999;x++){
        v2.push_back(x);
    }

    try {
        cout<<v1.size()<<" "<<v2.size()<<endl;
        proverka(v1.size(),v2.size());
        copy(v1.begin(),v1.end(),v2.begin());

    } catch (ApogolemoB &exception) {
        cout<<"Goleminata na vtoriot vektor e pomala od prviot. Nemoze da se kopira"<<endl;
    }

    return 0;
}
