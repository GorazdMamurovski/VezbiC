#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <iterator>

int main(){
    std::deque< int > d;
    std::ostream_iterator< int > output( cout, " " );
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    std::vector<int> v;
    for(int i=d.size()-1;i>=0;i--){
        v.push_back(d[i]);
    }
    std::copy( d.begin(), d.end(), output );
    cout<<endl;
    std::copy( v.begin(), v.end(), output );
    return 0;
}
