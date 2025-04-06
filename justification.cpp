#include<iostream>
#include<string>
#include<vector>

using namespace std;
void fullJustify(vector<string> & words, int maxWidth, vector<string>& answer){
    int n = words.size();
    if (n==0) return;
    int counter = 0;
    int current_length = 0;
    string result = "";
    for (int i=0;i<n;i++){
        current_length+=words[i].length();
        counter++;
        if ((current_length+counter-1)<maxWidth) continue;
        else break;
    }
    if ((current_length+counter-1)<maxWidth){
        for (int i=0;i<counter-1;i++){
            result+=words[i];
            result+=' ';
        }
        result+=words[counter-1];
        int x = result.length();
        int remain = maxWidth - x;
        for (int i=0;i<remain;i++) result+=' ';
        // cout<<result<<" /////this was less"<<endl;
        answer.push_back(result);
        return;
    }
    int spaces = -1;
    if ((current_length+counter-1)>maxWidth) {
        counter--;
        spaces = maxWidth - current_length + words[counter].length();
    }
    else if ((current_length+counter-1)==maxWidth){
        spaces = maxWidth - current_length;
    }

    // cout<<"counter : "<<counter<<" spaces : "<<spaces;
    if (counter==1) {
        result +=words[counter-1];
        int y = result.length();
        int remaining = maxWidth - y;
        for (int i=0;i<remaining;i++) result += ' ';
        words.erase(words.begin());
        answer.push_back(result);
        fullJustify(words,maxWidth,answer);
    }
    else {
        int width = spaces/(counter-1);
        int rem = spaces%(counter-1);
        // cout<<" width : "<<width<<" rem : "<<rem<<endl;
        string space_temp = "";
        for (int i=0;i<width;i++) space_temp +=' ';
        for (int i=0;i<counter-1;i++){
            result+=words[i];
            result+=space_temp;
            if (rem>0) result+=' ';
            rem--;
        }
        if (rem>0) {
            result+=' ';
            rem--;
        }
        result+=words[counter-1];
        words.erase(words.begin(),words.begin()+counter);
        answer.push_back(result);
        // cout<<result<<" //////this was more or equal"<<endl;
        fullJustify(words,maxWidth,answer);
    }
}

vector<string> fullJustify (vector<string>& words, int maxWidth){
    vector<string> answer;
    fullJustify(words,maxWidth,answer);
    return answer;
}

int main(){
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    int maxWidth;
    cin>>maxWidth;
    vector<string>answer;
    answer = fullJustify(words,maxWidth);
    // cout<<"_______________________"<<endl;
    for (auto val : answer){
        cout<<val<<"//"<<val.length()<<endl;
    }
    return 0;
}