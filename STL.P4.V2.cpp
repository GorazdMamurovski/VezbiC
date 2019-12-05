#include <vector>

#include <iostream>
#include <algorithm>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void sortString(char *str1,char *str2)
{
   sort(&str1[0], &str1[strlen(str1)]);
   sort(&str2[0], &str2[strlen(str2)]);
   if(!strcmp(str1,str2)){
       cout<<"zborot e anagram"<<endl;
   }
   else
   {
       cout<<"zborot ne e anagram"<<endl;
   }
}

int main(){
    vector <char*> anagram1;
    vector <char*> anagram2;
    char zbor1[10] = "slatko";
    char zbor2[10] = "staklo";
    anagram1.push_back(zbor1);
    anagram2.push_back(zbor2);
    sortString(anagram1[0],anagram2[0]);



    return 0;
}
