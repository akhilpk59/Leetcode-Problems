#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isMatch(string s,string p){
    if (p==s) return true;
    int sl = s.length();
    int pl = p.length();
    int si = 0;
    int pi = 0;
    stack <char> ast;

    while(si<sl&&pi<pl){
        
    }
}

int main(){

    string s = "";
    string p = "";
    cout<<boolalpha<<isMatch(s,p)<<endl;
    return 0;
}