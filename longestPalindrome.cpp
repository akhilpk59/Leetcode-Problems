#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using std::string;
using std::vector;

bool checkPalindrome (string s, int j, int k){
    if (j>k) return false;
    while (j<k) {
        if (s[j++]!=s[k--]) return false;
    }
    return true;
}

string longestPalindrome(string s){
    if (s=="") return "";
    int n = s.length();
    if (n==1) return s;
    std::unordered_map <char, vector<int>> indices;
    for (int i=0;i<n;i++){
        if (indices.find(s[i])==indices.end()){
            vector<int> temp;
            temp.push_back(i);
            indices[s[i]] = temp;
        }
        else {
            indices[s[i]].push_back(i);
        }
    }
    // for (auto it = indices.begin();it!=indices.end();it++){
    //     // std::cout<<it->first<<" ";
    //     vector<int> temp = it->second;
    //     for (auto val : temp) {
    //         std::cout<<val<<" ";
    //     }
    //     std::cout<<std::endl;
    // }

    int maxim = 0;
    string maximStr = "";
    int current = 0;
    for (auto it = indices.begin();it!=indices.end();it++){
        vector <int> temp = it->second;
        int l = temp.size();
        for (int j=0;j<l-1;j++){
            for (int k=l-1;k>=j+1;k--){
                int L = temp[k]-temp[j]+1;
                // std::cout<<"Char : "<<it->first<< " L : "<<L<<" k : "<<k<<" j : "<<j<<std::endl;
                if (L>maxim&&checkPalindrome(s,temp[j],temp[k])) {
                    maxim = L;
                    string T = s;
                    T.erase(T.begin()+temp[k]+1,T.end());
                    T.erase(T.begin(),T.begin()+temp[j]);
                    // std::cout<<T<<std::endl;
                    maximStr = T;
                }
            }
        }
    }
    return maximStr;
}

int main(){
    string s = "cbbd";
    std::cout<<longestPalindrome(s)<<std::endl;
    return 0;
}