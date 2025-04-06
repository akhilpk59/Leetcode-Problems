#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, int> result;

bool compare(string str, string p){
    if (p.length()>str.length()) return false;
    int n = p.length();
    for (int i=0;i<n;i++){
        if (p[i]!=str[i]) return false;
    }
    return true;
}

bool matching(string str, string arr[], int n){
    for (int i=0;i<n;i++){
        if (str.length()<arr[i].length()) continue;
        int l = arr[i].length();
        int count = 0;
        for (int j=0;j<l;j++){
            if (str[j]==arr[i][j]) count++;
        }
        if (count==l) return true;
    }
    return false;
}

int countConstruct(string str, string arr[], int n){
    if (result.find(str)!=result.end()) return result[str];
    if (str=="") return 1;
    if (!matching(str,arr,n)) return 0;
    
    int answer = 0;
   // cout<<"did we get here?"<<" str: "<<str<<endl;
    for (int i=0;i<n;i++){
        if (!compare(str,arr[i])) continue;
        int l = arr[i].length();
        string p = str;
        p.erase(0,l);
        answer+= countConstruct(p,arr,n);
    }
    result[str] = answer;
    return answer;
}

int main(){

    string str;
    getline(cin,str);
    string arr[] = {"e", "ee","eee","eeee","eeeee","eeeeee"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countConstruct(str,arr,n)<<endl;
    return 0;
    }