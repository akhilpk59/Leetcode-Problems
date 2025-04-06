#include<iostream>
#include<string>
#include<map>
using std::string;
using std::map;

int minim (int a, int b){
    return (a<b) ? a: b;
}

string i2S(int n){
    if (n==0) return "0";
    string answer = "";
    while (n!=0){
        char temp = '0' + (n%10);
        answer = temp + answer;
        n/=10;
    }
    return answer;
}

string getHint (string secret, string guess){
    int m = secret.length();
    int cows = 0;
    int bulls = 0;
    map<char,int> storeS;
    map<char,int> storeG;
    for (int i=0;i<m;i++){
        if (secret[i]==guess[i]) bulls++;
        if (storeS.find(secret[i])==storeS.end()) storeS[secret[i]] = 1;
        else storeS[secret[i]]++;
        if (storeG.find(guess[i])==storeG.end()) storeG[guess[i]] = 1;
        else storeG[guess[i]]++;
    }

    for (auto it=storeG.begin();it!=storeG.end();it++){
        if (storeS.find(it->first)==storeS.end()) continue;
        int numG = it->second;
        int numS = storeS[it->first];
        cows+=minim(numG,numS);
    }
    cows-=bulls;
    return i2S(bulls) + "A" + i2S(cows) + "B";
}

int main(){

    return 0;
}