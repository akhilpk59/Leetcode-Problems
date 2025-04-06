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
//static int check = 0;

bool findstring(string& s, vector<string>& words){
    if (result.find(s)!=result.end()) return result[s];
    
    int n = words[0].length();
    int l = s.length();
    string s1 = s;
    for (int i=0;i<=l-n;i++){
        string temp = s1;
        temp.erase(temp.begin()+n,temp.end());
       // cout<<"current temp inside boolean function : "<<temp<<" "<<check++<<endl;
        auto it = find(words.begin(),words.end(),temp);
        if (it==words.end()) {
            result[s] = false;
         //   cout<<"false temp : "<<s<<endl;
            return false;
        }
        words.erase(it);
        if (words.size()==0) {
            result[s] = true;
          //  cout<<"true temp : "<<s<<endl;
            return true;
        }
        s1.erase(0,n);
    }
    
    result[s] = false;
   // cout<<"false temp : "<<s<<endl;
    return false;
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
     //   cout<<"current temp in vector function : "<<temp<<" "<<check++<<endl;
        if (findstring(temp,arr)) {
            answer.push_back(i); 
        }
    }
    return answer;
}

int main(){
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
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