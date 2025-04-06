#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

static vector<vector<string>> result;
static vector<string> answer;
static map <string, vector<vector<string>>> finale;

bool match(string target, string word[], int n){
    for (int i=0;i<n;i++){
        if (target.length()<word[i].length()) continue;
        int l = word[i].length();
        int count = 0;
        for (int j=0;j<l;j++){
            if (word[i][j]!=target[j]) continue;
            count++;
        }
        if (count==l) return true;
    }
    return false;
}

bool single_match(string target, string p){
    if (target.length()<p.length()) return false;
    int n = p.length();
    for (int i=0;i<n;i++){
        if (p[i]!=target[i]) return false;
    }   
    return true;
}


vector<vector<string>> allConstruct(string target, string word[], int n){
    //if (finale.find(target)!=finale.end()) return finale[target];
    if (target=="") {
        result.push_back(answer);
        return result;
    }
    if (!match(target,word,n)) {
        return result;
    }

    for (int i=0;i<n;i++){
        if (!single_match(target,word[i])) continue;
        answer.push_back(word[i]);
        int l = word[i].length();
        string p = target;
        p.erase(0,l);
        result = allConstruct(p,word,n);
        //finale[p] = result;
        answer.pop_back();
    }
  //  finale[target] = result;
    return result;
}

int main(){
    string target;
    getline(cin,target);
    string word[] = {"a","aa","aaa","aaaa","aaaaa"};
    int n = sizeof(word)/sizeof(word[0]);
    vector<vector<string>> answering;
    answering = allConstruct(target,word,n);
    if (answering.size()==0){
        cout<<"there is no way to create the input string using the given word array"<<endl;
        return 0;
    }
    for (auto val : answering){
        for (auto str : val){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;   
}