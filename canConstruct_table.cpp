#include<iostream>
#include<string>

using namespace std;

bool match (string p, string target){
    int n = p.length();
    if (n>target.length()) return false;
    for (int i=0;i<n;i++){
        if (p[i]!=target[i]) return false;
    }
    return true;
}

int main(){

    string target;
    getline(cin,target);
    int l = target.length();
    string word[] = {"e","ee","eee","eeee","eeeee","eeeeee"};
    int n = sizeof(word)/sizeof(word[0]);
    bool answer[l+1];
    for (int i=0;i<=l;i++) answer[i] = false;
    answer[0] = true;
    for (int i=0;i<=l;i++){
        if (answer[i]){
            string p = target;
            p.erase(p.begin()+i,p.end());
            for (int j=0;j<n;j++){
                string temp = p + word[j];    
                if (match(temp,target)) {
                    int m = temp.length();
                    answer[m] = true;
                }
            }
        }
    }
    cout<<boolalpha<<answer[l]<<endl;
    return 0;
}