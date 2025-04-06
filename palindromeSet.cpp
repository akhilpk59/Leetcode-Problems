#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

bool palindrome(string s){
    int n = s.length();
    if (n==1) return true;
    for (int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]) return false;
    }
    return true;
}

vector<vector<string>> partition(string s){
    int n = s.length();
    vector<vector<string>> answer;
    if (n==0) return answer;
    if (n==1){
        vector<string> temp;
        temp.push_back(s);
        answer.push_back(temp);
        return answer;
    }
    string temp = "";
    for (int i=0;i<n;i++){
        temp+=s[i];
        if (palindrome(temp)){
            string remain = s;
            remain.erase(remain.begin(),remain.begin()+i+1);
            vector<vector<string>> rem = partition(remain);
            if (rem.size()==0) {
                vector<string> check;
                check.push_back(temp);
                answer.push_back(check);
            }
            for (auto val : rem){
                val.insert(val.begin(),temp);
                answer.push_back(val);
            }
        }
    }
    return answer;
}

int main(){
    string s;
    std::getline(std::cin,s);
    vector<vector<string>> answer = partition(s);
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}