#include<iostream>
#include<string>
#include<unordered_set>
using std::string;

int lengthOfLongestSubstring(string s){
    if (s=="") return 0;
    int n = s.length();
    if (n==1) return 1;    
    int maxim = 0;
    int current = 0;
    int index = 0;
    bool flag = false;
    std::unordered_set <char> letter;
    for (int i=0;i<n;i++){
        if (letter.find(s[i])==letter.end()){
            letter.insert(s[i]);
            if (!flag) {
                index = i;
                flag = true;
            }
            current++;
            if (maxim<current) maxim = current;
        }
        else {
            current = 0;
            letter.clear();
            i = index;
            flag = false;
        }
    }
    return maxim;
}

int main(){
    string s = "dvdf";
    std::cout<<lengthOfLongestSubstring(s)<<std::endl;
    return 0;
}