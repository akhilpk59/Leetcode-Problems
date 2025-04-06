#include<iostream>
#include<string>
#include<unordered_map>
using std::string;

int lengthOfLongestSubstring(string s){
    if (s=="") return 0;
    int n = s.length();
    if (n==1) return 1;
    std::unordered_map<char,int> check;
    string temp = "";
    int index = 1;
    int current = 0;
    int maxim = 0;
    for (int i=0;i<n;i++){
        if (check.find(s[i])==check.end()){
            check[s[i]] = index++;
            temp+=s[i];
            current++;
            if (maxim<current) maxim = current;
        }
        else {
            int val = check[s[i]];
            int mapSize = check.size();
            for (int k=0;k<mapSize;k++){
                if (k<val){
                auto it = check.find(temp[k]);
                check.erase(it);
                }
                else {
                    auto it = check.find(temp[k]);
                    it->second -=val;
                }
            }
            temp.erase(temp.begin(),temp.begin()+val);
            current = temp.length();
            i = i - 1;
            index = temp.length()+1;
        }
    }
    return maxim;
}


int main(){
    string s = "pwwkew";
    std::cout<<lengthOfLongestSubstring(s)<<std::endl;
    return 0;
}