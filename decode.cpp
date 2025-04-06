#include<iostream>
#include<string>
#include<set>
#include<map>
using std::string;

std::map <string, int> result;
int evaluate(string s){
    if (result.find(s)!=result.end()) return result[s];
    if (s[0]=='0'||s=="") return 0;
    std::set<string> letters1 = {"1","2","3","4","5","6","7","8","9"};
    std::set<string> letters2 = {"10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
    int n = s.length();
    // if (n==0) return 0;
    if (n==1){
        if (letters1.find(s)!=letters1.end()) return 1;
        else return 0;
    }
    // if (n==2){
    //     int answer = 0;
    //     string temp = "";
    //     temp+=s[0];
    //     if (letters1.find(temp)!=letters1.end()) answer++;
    //     temp+=s[1];
    //     if (letters2.find(temp)!=letters2.end()&&s[1]!='0') answer++;
    //     return answer;
    // }
    string temp1 = "";
    temp1+=s[0];
    string temp2 = temp1;
    temp2+=s[1];
    if (letters1.find(temp1)!=letters1.end()&&letters2.find(temp2)!=letters2.end()) {
        string check1 = s;
        string check2 = s;
        check1.erase(check1.begin());
        check2.erase(check2.begin(),check2.begin()+2);
        if (result.find(check1)==result.end()) result[check1] = evaluate(check1);
        if (result.find(check2)==result.end()) result[check2] = evaluate(check2);
        result[s] = result[check1] + result[check2];
        return result[s];
    }
    else if (letters1.find(temp1)!=letters1.end()) {
        string check1 = s;
        check1.erase(check1.begin());
        if (result.find(check1)==result.end()) result[check1] = evaluate(check1);
        result[s] = result[check1];
        return result[s];
    }
    else {
        string check2 = s;
        check2.erase(check2.begin(),check2.begin()+2);
        if (result.find(check2)==result.end()) result[check2] = evaluate(check2);
        result[s] = result[check2];
        return result[s];
    }
}

int numDecodings(string s){
    if (s[0]=='0') return 0;
    else if (s.length()==1) return 1;
    else return evaluate(s);
}

int main(){
    string s = "230";
    std::cout<<numDecodings(s)<<std::endl;
    return 0;
}