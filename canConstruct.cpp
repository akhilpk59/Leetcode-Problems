#include<iostream>
#include<string>
#include<map>

using namespace std;

map <string, bool> result;

bool match(string p, string str){
    if (p.length()>str.length()) return false;
    int n = p.length();
    for (int i=0;i<n;i++){
        if (p[i]!=str[i]) return false;
    }
    return true;
}

bool canConstruct(string str, string arr[], int n){
    if (result.find(str)!=result.end()) return result[str];
    if (str=="") return true;
    for (int i=0;i<n;i++){
        if (match(arr[i],str)){
            int l = arr[i].length();
            string p = str;
            p.erase(0,l);
            if (canConstruct(p,arr,n)) {
                result[str] = true;
                return true;
            }
        }
    }
    result[str] = false;
    return false;
}

int main(){ 
    string str;
    getline(cin,str);
    string arr[] = {"e","ee","eee","eeee","eeeee","eeeeee"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<boolalpha<<canConstruct(str,arr,n)<<endl;
    return 0;
}