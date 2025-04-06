#include<iostream>
#include<string>
#include<stack>

bool isValid(std::string s){
    int n = s.length();
    std::stack <char> bracket;
    for (int i=0;i<n;i++){
       if (s[i]=='('||s[i]=='{'||s[i]=='[') bracket.push(s[i]);
       else {
        switch(s[i]){
            case ')' :
                if (bracket.empty()||bracket.top()!='(') return false;
                else bracket.pop();
                break;
            case '}' : 
                if (bracket.empty()||bracket.top()!='{') return false;
                else bracket.pop();
                break;
            case ']' : 
                if (bracket.empty()||bracket.top()!='[') return false;
                else bracket.pop();
                break;
        }
       }
    }
    if (!bracket.empty()) return false;
    return true;
}

int main(){ 
    std::string s;
    std::getline(std::cin,s);
    std::cout<<std::boolalpha<<isValid(s)<<std::endl;
    return 0;
}