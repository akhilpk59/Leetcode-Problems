#include<iostream>
#include<string>

using std::string;

int pow(int exp){
    if (exp==0) return 1;
    else return 10*pow(exp-1);
}

int S2D(string answer){
    if (answer=="0"||answer=="") return 0;
    bool nSign = false;
     if (answer=="-2147483648") return -2147483648;
    if (answer[0]=='-') {
       
        nSign = true;
        answer.erase(answer.begin());
    }
    int exp = 0;
    int n = answer.length();
    int ans = 0;
    for (int i=n-1;i>=0;i--){
        ans += (answer[i]-48)*pow(exp++);
    }
    if (nSign) ans = 0 - ans;
    return ans;
}

void cleanUp(string& s){
    while (s[0]==' ') s.erase(s.begin());
    string answer = "";
    char sign = ' ';
    if (s[0]=='-') {
        sign ='-';
        s.erase(s.begin());
    }
    else if (s[0]=='+') {
        sign = '+';
        s.erase(s.begin());
    }
    // std::cout<<"sign : "<<sign<<std::endl;
    int n = s.length();
    for (int i=0;i<n;i++){
        if (answer==""&&s[i]=='0') continue;
        else if (!(s[i]>='0'&&s[i]<='9')) break;
        else answer+= s[i];
    }
    // std::cout<<"answer before sign : "<<answer<<std::endl;
    if (answer.length()>10) {
        if (sign =='-') answer = "2147483648";
        else answer = "2147483647";
    }
    else if (answer.length()==10){
        if (answer>="2147483648"&&sign=='-') answer = "-2147483648";
        else if (answer>"2147483647"&&(sign=='+'||sign==' ')) answer = "2147483647";
        else if (sign=='-') answer = '-' + answer;
    }
    else {
        if (sign=='-') answer = '-' + answer;
    }
    s = answer;
    // std::cout<<answer<<std::endl;
}

int myAtoi(string s){
    cleanUp(s);
    return S2D(s);
}

int main(){
    string s = "-2147483648";
    std::cout<<myAtoi(s)<<std::endl;
    return 0;
}