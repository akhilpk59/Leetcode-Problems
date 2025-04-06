#include<iostream>
#include<string>
#include<vector>

using namespace std;
// bool find (string s, vector<string> words, int index){
//     int sl = s.length();
//     int wordsl = words[index].length();
//     int k = 0;
//     for (int i=0;i<sl;i++){
//         if (s[i]==words[index][k]){
//             while(k<wordsl){
//                 if (i+k==sl) return false;
//                 else if (s[i+k]==words[index][k]) k++;
//                 else break;
//             }
//             if (k==wordsl) return true;
//             else {
//                 i = i+k-1;
//                 k=0;
//             }
//         }
//     }
//     return false;
// }

int find (string s, vector<string> words){
    int l = words.size();
    for (int i=0;i<l;i++){
        if (s==words[i]) return i;
    }
    return -1;
}

vector<int> findSubstring(string s, vector<string>& words){
    vector<int> answer;
    int sl = s.length();
    int wl = words[0].length();
    int vl = words.size();
    int tl = wl*vl;
    for (int i=0;i<=sl-tl;i++){
        string temp ="";
        vector<string> words_temp = words;
        for (int j=i;j<i+wl;j++) temp+=s[j];
        if (find(temp,words_temp)==-1) continue;
        else {
            int count = 0;
            while (find(temp,words_temp)!=-1&&words_temp.size()!=0){
                int index = find(temp,words_temp);
                words_temp.erase(words_temp.begin()+index);
                count+=wl;
                temp = "";
                for (int j=i+count;j<i+count+wl;j++) temp+=s[j];
            }
            if (words_temp.size()==0){
                answer.push_back(i);
            }
            else i = i+wl-1;
        }
        }
    return answer;
}

int main(){
    string s="wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    vector<int>answer = findSubstring(s,words);
    for (auto val : answer) cout<<val<<" ";
    return 0;
}