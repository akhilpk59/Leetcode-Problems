#include<iostream>
#include<string>
#include<vector>
std::string longestCommonPrefix(std::vector<std::string> strs){
    int n  = strs.size();
    std::string answer = strs[0];
    for (int i=1;i<n;i++){
        if (answer[0]!=strs[i][0]||answer=="") return "";
        int k = answer.length();
        int l = strs[i].length();
        int j = 1;
        //int m = 1;
        //answer = strs[i][0];
        std::string temp = "";
        temp = strs[i][0];
        while (j<k&&j<l){
            if (answer[j]==strs[i][j]) temp +=strs[i][j++];
            else break;
        }
        answer = temp;
        std::cout<<answer<<std::endl;
    }
    return answer;
}

int main(){
    std::vector<std::string> strs = {"abca","aba","aaab"};
    std::cout<<longestCommonPrefix(strs)<<std::endl;
    return 0;

}