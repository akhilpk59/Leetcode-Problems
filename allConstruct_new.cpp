#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

static map <string, vector<vector<string>>> result;

bool match(string target, string p){
    int n = p.length();
    if (target.length()<n) return false;
    for (int i=0;i<n;i++){
        if (target[i]!=p[i]) return false;
    }
    return true;
}

vector<vector<string>> allConstruct (string target, string word[], int n){
   if (result.find(target)!=result.end()) return result[target];
    if (target=="") {
        vector<vector<string>> pushing;
        vector<string> blank;
        pushing.push_back(blank);
        return pushing;
    }
    vector<vector<string>> temp;
    for (int i=0;i<n;i++){
        if (!match(target, word[i])) continue;
        string p = target;
        int l = word[i].length();
        p.erase(0,l);
        vector<vector<string>> looping = allConstruct(p,word,n);
       if (result.find(p)==result.end()) result[p] = looping;
        int m = looping.size();
        for (int j=0;j<m;j++){
            looping[j].insert(looping[j].begin(),word[i]);
            temp.push_back(looping[j]);
        }
    }
   result[target] = temp;
    return temp;
}

int main(){
    string target;
    getline(cin,target);
    string word[] = {"a","aa","aaa","aaaa","aaaaa"};
    int n = sizeof(word)/sizeof(word[0]);
    vector<vector<string>> answer;
    answer = allConstruct(target,word,n);
    if (answer.size()==0){
        cout<<"no combination exists"<<endl;
        return 0;
    }
    for (auto val : answer){
        for (auto str : val){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}