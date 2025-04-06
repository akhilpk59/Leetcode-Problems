#include<iostream>
#include<string>
#include<vector>
#include<map>
using std::string;
using std::vector;

string open(int i){
    string result = "";
    while(i>0) {
        result +="(";
        i--;
    }
    return result;
}
string close(int i){
    string result = "";
    while(i>0) {
        result +=")";
        i--;
    }
    return result;
}

vector<string> generateParenthesis(int n){
    if (n==1) {
        vector<string> temp;
        temp.push_back("()");
        return temp;
    }
    vector<string> answer;
    std::map <string,int> store;
    int ind = 1;
    string first = open(n)+close(n);
    if (store.find(first)==store.end()) {
        store[first] = ind++;
        // answer.push_back(first);
    }

    for (int i=n-1;i>=1;i--){
        string temp1 = open(i);
        string temp2 = close(i);
        vector <string> tempa = generateParenthesis(n-i);
        vector<string> tempb = generateParenthesis(i);
        int aN = tempa.size();
        int bN = tempb.size();
        for (int j=0;j<aN;j++){
            string val = temp1 + tempa[j] + temp2;
            if (store.find(val)==store.end()) store[val] = ind++;
            // answer.push_back(val);
            for (int k=0;k<bN;k++){
                string value1 = tempb[k]+tempa[j];
                string value2 = tempa[j]+tempb[k];
                if (store.find(value1)==store.end()) store[value1] = ind++;
                if (store.find(value2)==store.end()) store[value2] = ind++;
                // answer.push_back(value1);
                // answer.push_back(value2);
            }
        }
    }
    for (auto it=store.begin();it!=store.end();it++) answer.push_back(it->first);
    return answer;
}

int main(){
    vector<string> answer;
    int n;
    std::cin>>n;
    answer = generateParenthesis(n);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}