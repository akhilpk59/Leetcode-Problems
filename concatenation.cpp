#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
// bool match(string temp, vector<string> words){
//     int n = words.size();
//     for (int i=0;i<n;i++){
//         if (words[i]==temp) return true;
//     }
//     return false;
// }
static map <string, bool> result;

bool findstring(string& s, vector<string>& words){
    //if (result.find(s)!=result.end()) return result[s];
    if (words.size()==0) return true;
    int n = words[0].length();
    if (s.length()<n) {
       // result[s] = false;
        return false;
    }
    string temp = s;
    string s1 = s;
    temp.erase(temp.begin()+n,temp.end());
   // if (!match(temp,words)) return false;
    s.erase(0,n);
    auto it = find(words.begin(),words.end(),temp);
    if (it==words.end()) {
        //result[s1] = false;
        return false;
    }
    words.erase(it);
    return findstring(s,words);
    //result[s1] = findstring(s,words);
   // return result[s1];
}

vector<int> findSubstring(string s, vector<string>& words){
    vector<int> answer;
    int n = s.length();
    int l = words[0].length();
    int k = words.size();
    for (int i=0;i<=(n-(l*k));i++){
        string temp = s;
        vector<string> arr = words;
        temp.erase(temp.begin(),temp.begin()+i);
        temp.erase(temp.begin()+(l*k),temp.end());
        if (findstring(temp,arr)) {
            answer.push_back(i); 
        }
    }
    return answer;
}

int main(){
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    //getline(cin,s);
    //vector<string> words = {"bar","foo","the"};
    vector<int> answer;
    answer = findSubstring(s,words);
    for (auto val : answer){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}