#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool match(string p, string target){
    int n = p.length();
    if (n>target.length()) return false;
    for (int i=0;i<n;i++){
        if (p[i]!=target[i]) return false;
    }
    return true;
}

int main() {
    string target;
    getline(cin,target);
    string word[] = {"a","aa","aaa","aaaa","aaaaa"};
    int n = sizeof(word)/sizeof(word[0]);
    int l = target.length();
    vector<vector<vector<string>>> answer(l+1);
    vector<string> empty;
    //answer[0][0] = empty;
    //cout<<"I am here"<<endl;
    for (int i=0;i<=l;i++){
        if (i==0){ 
            vector<string> temp;
            for (int j=0;j<n;j++){
                int k = word[j].length();
                string t = target;
                t.erase(t.begin(),t.begin()+i);
                if (match(word[j],t)) {
                    temp.push_back(word[j]);
                    answer[i+k].push_back(temp);
                    temp.pop_back();
                }
            }  
        }
        else if (!answer[i].empty()){
            int y = answer[i].size();
            for (int z=0;z<y;z++){
                vector<string> temp = answer[i][z];
                for (int j=0;j<n;j++){
                    int k = word[j].length();
                    string t = target;
                    t.erase(t.begin(),t.begin()+i);
                    if (match(word[j],t)) {
                        temp.push_back(word[j]);
                        answer[i+k].push_back(temp);
                        temp.pop_back();
                    }
                }
            }
        }
    }
    if (answer[l].size()==0) {
        cout<<"No combination possible"<<endl;
        return 0;
    }
    for (auto val : answer[l]){
        for (auto str : val){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}