#include <iostream>

#include "RixJson.h"

using namespace std;
using namespace Rix;

int main()
{
    string jsonDoc = R"({'Test':'666', 'What':[0,1,{'a':'b','f':3.14}], 'ee':{'a':3.4,'is':false}})", s;
    //while(getline(cin, s)) jsonDoc += s + '\n'; 
    cout<<">====| Test Begin |====<"<<endl;
    cout<<"> Test Json:"<<endl<<jsonDoc<<endl<<endl;
    
    Json::Parser p(jsonDoc);
    Json::Object o = p.Parse();
    cout<<"> Generating beautiful json string:"<<endl;
    cout<<o.ToStr(true)<<endl<<endl;
    cout<<"> Generating not so beautiful json string:"<<endl;
    cout<<o.ToStr(false)<<endl<<endl;

    cout<<">====| Test Finished |====<"<<endl;

    return 0;
}