#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

// static int count = 0;

string merge(string l, string r){
    int nL = l.length();
    int nR = r.length();
    int i = 0;
    int j = 0;
    string temp = "";
    while (i<nL&&j<nR){
        if (l[i]<=r[j]) temp+=l[i++];
        else temp+=r[j++];
    }
    while (i<nL) temp+=l[i++];
    while (j<nR) temp+=r[j++];
    return temp;
}

void mergeSort(string& s){
    int n = s.length();
    if (n<=1) return;
    string sL = "";
    string sR = "";
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) sL+= s[i];
    for (int i = mid+1;i<n;i++) sR+=s[i];
    mergeSort(sL);
    mergeSort(sR);
    s = merge(sL,sR);
}

bool pattern(string check, string finale){
    int nC = check.size();
    int nF = finale.size();
    int i=0;
    int j=0;
    while (i<nC&&j<nF){
        if (check[i]==finale[j]) i++;
        j++;
    }
    if (j==nF&&i!=nC) return false;
    else return true;
}

void swap(char& a,char& b){
    char temp = a;
    a=b;
    b = temp;
}

void next (string& tempS, string s){
    if (pattern(tempS,s)) return;
    int n = tempS.size();
    
    do {
        std::cout<<tempS<<std::endl;
        int breakage = 0;
        char prev = tempS[0];
        char target1 = '1';
        char current;      
        int index = -1;  
        for (int i=1;i<n;i++){
            current = tempS[i];
            if (current>prev) prev = current;
            else {
                if (i!=1) target1 = tempS[i-2];
                index = i;
                break;
            }
        }
        if (target1=='1') {
            swap (tempS[n-1],tempS[n-2]);
            continue;
        }
        if (target1<current) swap(tempS[index-2],tempS[index]);
        else swap(tempS[index-2],tempS[index-1]);
        string check = tempS;
        check.erase(check.begin(),check.begin()+index-1);
        mergeSort(check);
        int m = check.size();
        for (int i=0;i<m;i++) tempS[n-1-i] = check[m-1-i];
    }   while (!pattern(tempS,s));
}

void check(int breakage, string& answer, string s, char temp){

    string tempS = answer;
    tempS.insert(tempS.begin()+breakage+1,temp);
    next(tempS,s);
    answer = tempS;
}

string removeDuplicateLetters(string s){
    int n = s.length();
    if (n==1) return s;
    vector<vector<int>> indices;
    for (int i=0;i<26;i++){
        vector<int> temp;
        indices.push_back(temp);
    }
    for (int i=0;i<n;i++){
        int index = s[i] - 97;
        indices[index].push_back(i);
    }
    string answer = "";
    for (int i=25;i>=0;i--){
        if (indices[i].size()==0) continue;
        char temp = 'a' + i;
        if (answer=="") {
            answer = temp + answer;
            continue;
        }
        int m = answer.size();
        int breakage = -1;
        for (int j = m-1;j>=0;j--){
            if (indices[i].front()<indices[answer[j]-97].back()) continue;
            else breakage = j;
            break;
        }
        check(breakage, answer,s,temp);
    }
    return answer;
}

int main(){
    string s = "itsaninterestingwaytolookatthings";
    std::cout<<removeDuplicateLetters(s)<<std::endl;
    return 0;
}