#include<iostream>
#include<string>

using namespace std;

bool match (string p, string target){
    int n = p.length();
    if (n>target.length()) return false;
    for (int i = 0;i<n;i++){
        if (p[i]!=target[i]) return false;
    }
    return true;
}

int main(){
    string target;
    getline(cin, target);
    string word[] = {"e","ee","eee","eeee","eeeee","eeeeee"}; 
    int n = sizeof(word)/sizeof(word[0]);
    int l = target.length();
    int answer[l+1];
    answer[0] = 1;
    for (int i=1;i<=l;i++) answer[i] = 0;
    for (int i=0;i<=l;i++){
        if (answer[i]!=0){
            string temp = target;
            temp.erase(temp.begin()+i,temp.end());
           // cout<<temp<<" ";
            for (int j=0;j<n;j++){
                string p = temp + word[j];
              //  cout<<p<<" ";
                int k = p.length();
                if (match(p,target)) {
                    answer[k] += answer[i];
                }

            }
        }
       // cout<<endl;
    }

    cout<<answer[l]<<endl;
    return 0;
}