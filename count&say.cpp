#include<iostream>
#include<string>

using std::string;

string D2S (int n){
    string answer = "";
    char temp = '0' + n;
    answer+=temp;
    return answer;
}

string RLE (string s){
    if (s=="1") return "11";
    string answer = "";
    int n = s.length();
    int count = 0;
    char temp = s[0];
    for (int i=0;i<n;i++){
        if (temp==s[i]) count++;
        else {
            answer = answer + D2S(count) + temp ;
            temp = s[i];
            count = 1;
        }
    }
    answer = answer + D2S(count) + temp;
    return answer;
}

string countAndSay (int n){
    if (n==1) return "1";
    string count[n];
    count[0] = "1";
    for (int i=1;i<n;i++){
        count[i] = RLE(count[i-1]);
    }
    return count[n-1];
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<countAndSay(n)<<std::endl;
    return 0;
}