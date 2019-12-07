#include <map>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct prioritet{
    int proces;
    double prioritetV;
public:
    prioritet(int,double);
};

prioritet::prioritet(int a,double b){
    proces=a;
    prioritetV=b;
}

struct sporedi{
    bool operator()(prioritet const& p1, prioritet const& p2){
            return p1.prioritetV < p2.prioritetV;
    }
};


int main(){
    std::priority_queue<  prioritet,vector<prioritet>,sporedi > priorities;
    int proces;
    double prio;
    int meni;
    while(1){
        cout<<"Vnesi proces (0 za kraj)"<<endl;
        cin>>proces;
        if(proces==0){
            break;
        }
        cout<<"Vnesi prioritet "<<endl;
        cin>>prio;
        priorities.push(prioritet(proces,prio));

    }
    while (!priorities.empty()) {
            prioritet p = priorities.top();
            priorities.pop();
            cout <<"Proces:"<< p.proces << " Prioritet " << p.prioritetV << "\n";
        }
    cout << endl;
    return 0;
}
