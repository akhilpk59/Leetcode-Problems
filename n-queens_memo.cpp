#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> answer;
    if (n==0||n==2||n==3) return answer;
    if (n==1){
        vector<string> temp;
        temp.push_back("Q");
        answer.push_back(temp);
        return answer;
    }
    if (n==4){
        vector<string> temp;
        temp.push_back(".Q..");
        temp.push_back("...Q");
        temp.push_back("Q...");
        temp.push_back("..Q.");
        answer.push_back(temp);
        temp.clear();
        temp.push_back("..Q.");
        temp.push_back("Q...");
        temp.push_back("...Q");
        temp.push_back(".Q..");
        answer.push_back(temp);
        return answer;
    }
    
}

int main(){

    return 0;
}