#include<iostream>
#include<string>
#include<vector>
#include<map>
using std::string;
using std::vector;

vector<string> generateParenthesis(int l){
    if (l==1) {
        vector<string> brack;
        brack.push_back("()");
        return brack;
    }
    // if (l==2){
    //     vector<string>brack;
    //     brack.push_back("(())");
    //     brack.push_back("()()");
    //     return brack;
    // }
    vector<string> answer;
    std::map <string, int> store;
    int ind = 1;
    vector<string> prev = generateParenthesis(l-1);
    int n = prev.size();
    for (int i=0;i<n;i++){
        string temp ="(" + prev[i]+")";
        if (store.find(temp)==store.end()) store[temp] = ind++;
        temp = prev[i] +"()";
        if (store.find(temp)==store.end()) store[temp] = ind++;
        temp = "()" + prev[i];
        if (store.find(temp)==store.end()) store[temp] = ind++;
    }
    for (auto it=store.begin();it!=store.end();it++) answer.push_back(it->first);
    return answer;
}

int main(){
    int n;
    std::cin>>n;
    vector<string> answer;
    answer = generateParenthesis(n);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}