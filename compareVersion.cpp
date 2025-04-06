#include<iostream>
#include<string>
using std::string;

int pow (int n){
    if (n==0) return 1;
    else return 10*pow(n-1);
}

int S2D(string t){
    if (t=="") return 0;
    while (t!=""&&t[0]=='0') t.erase(t.begin());
    int n = t.length();
    if (n==0) return 0;
    int value = 0;
    for (int i=n-1;i>=0;i--){
        value+=(t[i]-48)*pow(n-1-i);
    }
    return value;
}

int compareVersion(string version1, string version2){
    if (version1==""&&version2=="") return 0;
    int v1 = version1.length();
    int v2 = version2.length();
    string temp1 = "";
    string temp2 = "";
    int i = 0;
    int j = 0;
    while(i<v1){
        if (version1[i]=='.') break;
        else temp1+=version1[i];
        i++;
    }
    while(j<v2){
        if (version2[j]=='.') break;
        else temp2+=version2[j];
        j++;
    }
    int D1 = S2D(temp1);
    int D2 = S2D(temp2);
    
    if (D1<D2) return -1;
    else if (D1>D2) return 1;
    else {
        string next1 = version1;
        if (i<v1) next1.erase(next1.begin(),next1.begin()+i+1);
        else next1 = "";
        string next2 = version2;
        if (j<v2) next2.erase(next2.begin(),next2.begin()+j+1);
        else next2 = "";
        return compareVersion(next1,next2);
    }
    
}

int main(){
    string v1 = "1.0.0.11";
    string v2 = "1.0.0.1";
    std::cout<<compareVersion(v1,v2)<<std::endl;
    return 0;
}