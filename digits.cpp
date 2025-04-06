#include<iostream>
#include<string>
#include<vector>
#include<map>

using std::string;
using std::vector;

vector<string> letterCombinations(string digits){
    vector<string> answer;
    if (digits=="") return answer;
    int n = digits.length();
    std::map <char,vector<char>> nums;
    nums['2'] = {'a','b','c'};
    nums['3'] = {'d','e','f'};
    nums['4'] = {'g','h','i'};
    nums['5'] = {'j','k','l'};
    nums['6'] = {'m','n','o'};
    nums['7'] = {'p','q','r','s'};
    nums['8'] = {'t','u','v'};
    nums['9'] = {'w','x','y','z'};

    vector<char> temp = nums[digits[0]];
    int l = temp.size();
    string rem = digits;
    rem.erase(rem.begin());
    vector<string> rest = letterCombinations(rem);
    int m = rest.size();
    if (m==0){
        for (int i=0;i<l;i++) {
            string s;
            s+=temp[i];
            answer.push_back(s);
        }
        return answer;
    }
    for (int j = 0;j<l;j++){
        for (int k=0;k<m;k++){
            string check = "";
            check += temp[j] + rest[k];
            answer.push_back(check);
        }
    }
    return answer;
}

int main(){
    string digits;
    std::getline(std::cin, digits);
    vector<string> answer = letterCombinations(digits);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}