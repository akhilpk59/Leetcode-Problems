#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

int pow(int n){
    if (n==0) return 1;
    else return 10*pow(n-1);
}

int D2S (string s){
    int answer = 0;
    int n = s.length();
    for (int i=n-1;i>=0;i--){
        int num = s[i]-48;
        answer += num*pow(n-1-i);
    }
    return answer;
}

vector<string> evaluate(string& s, int m=3){
    int n = s.length();
    vector<string> answer;
    if (n==0) return answer;
    if ((n-(3*m))>3) return answer;
    string temp = "";
    temp +=s[0];
   // if (n!=1&&temp=="0") return answer;
    if (m==0){
        if (D2S(s)>255) return answer;
        if ((n==1)||(n>1&&s[0]!='0')) answer.push_back(s);
        return answer;
    }
    string rem = s;
    rem.erase(rem.begin());
    vector<string> remain = evaluate(rem,m-1);
    for (auto val : remain) {
        string temp1 = temp + '.';
        temp1+=val;
        answer.push_back(temp1);
    }

    if (n==1) return answer;
    
    temp+=s[1];
    if (temp[0]!='0'){
    rem = s;
    rem.erase(rem.begin(),rem.begin()+2);
    remain = evaluate(rem,m-1);
    for (auto val : remain) {
        string temp1 = temp + '.';
        temp1+=val;
        answer.push_back(temp1);
    }
    if (n==2) return answer;
    temp+=s[2];
    if (D2S(temp)>255) return answer;
    rem = s;
    rem.erase(rem.begin(),rem.begin()+3);
    remain = evaluate(rem,m-1);
    for (auto val : remain) {
        string temp1 = temp + '.';
        temp1+=val;
        answer.push_back(temp1);
    }
    }
    return answer;
}

vector<string> restoreIpAddresses(string s){
    vector<string> answer;
    answer = evaluate(s);
    return answer;
}

int main(){
    string s;
    std::getline(std::cin,s);
    vector<string> answer = restoreIpAddresses(s);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}