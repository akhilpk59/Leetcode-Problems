#include<iostream>
#include<string>
#include<vector>
#include<map>
using std::string;
using std::vector;

vector<vector<string>> groupAnagrams (vector<string>& strs){
    int n = strs.size();
    if (n<=1){
        vector<vector<string>> answer;
        answer.push_back(strs);
        return answer;
    }
    std::map<std::map<char,int>, vector<string>> total;
    vector<vector<string>> answer;
    for (int i=0;i<n;i++){
        int l = strs[i].length();
        std::map <char,int> freq;
        for (int j=0;j<l;j++){
            if (freq.find(strs[i][j])!=freq.end()) freq[strs[i][j]]++;
            else freq[strs[i][j]] = 1;
        }
        if (total.find(freq)==total.end()) {
            vector<string> temp;
            temp.push_back(strs[i]);
            total[freq] = temp;
        }
        else total[freq].push_back(strs[i]);
    }
    for (auto it = total.begin();it!=total.end();it++) answer.push_back(it->second);
    return answer;
}

int main(){

    vector<string> strs = {"a"};
    vector<vector<string>> answer = groupAnagrams(strs);

    for (auto val : answer){
        for (auto str : val) std::cout<<str<<" ";
        std::cout<<std::endl;
    }

    return 0;
}