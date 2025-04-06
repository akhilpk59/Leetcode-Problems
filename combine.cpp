#include<iostream>
#include<vector>
#include<map>
#include<string>
using std::vector;
using std::string;

string D2S (int num){
    if (num==0) return "0";
    string answer = "";
    while (num!=0){
        char temp = '0' + num%10;
        answer = temp + answer;
        num/=10;
    }
    return answer;
} 
std::map <string, vector<vector<int>>> result;

vector<vector<int>> combine (int n,int k, int start){
    string check = D2S(n)+D2S(k)+D2S(start);
    if (result.find(check)!=result.end()) return result[check];
    vector<vector<int>> answer;
    if (k==0) {
        vector<int> temp;
        answer.push_back(temp);
        return answer;
    }
    // else if (k==1){
    //     vector<int> temp;
    //     temp.push_back(start);
    //     answer.push_back(temp);
    //     return answer;
    // }
    for (int i=start;i<=n-k+1;i++){
        vector<int> temp;
        temp.push_back(i);
        string c = D2S(n)+D2S(k-1)+D2S(i+1);
        if (result.find(c)==result.end()) result[c]=combine(n,k-1,i+1);
        vector<vector<int>> rem = result[c];
        int m = rem.size();
        for (int j=0;j<m;j++){
            rem[j].insert(rem[j].begin(),i);
            answer.push_back(rem[j]);
        }
    }
    result[check] = answer;
    return answer;
}
vector<vector<int>> combine (int n, int k){
    vector<vector<int>> answer;
    if (n==1) {
        vector<int> temp;
        temp.push_back(1);
        answer.push_back(temp);
        return answer;
    }
    answer = combine(n,k,1);
    return answer;
}

int main(){
    int n;
    int k;
    std::cin>>n>>k;
    vector<vector<int>> answer = combine(n,k);
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}