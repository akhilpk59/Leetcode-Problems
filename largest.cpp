#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

string D2S(int nums){
    if (nums==0) return "0";
    string answer = "";
    while (nums!=0){
        char temp = '0' + (nums%10);
        answer = temp + answer;
        nums/=10;
    }
    return answer;
}

void swap(string& a, string& b){
    string temp = a;
    a = b;
    b = temp;
}

bool pat(string a, string b){
    int m = a.length();
    int n = b.length();
    int count = 0;
    for (int i=0;i<m;i++) {
        if (a[i]!=b[i]) break;
        count++;
    }
    return (count==m);
}

bool check(char a, string b){
    int n = b.length();
    for (int i=0;i<n;i++){
        if (b[i]<a) return false;
        else if (b[i]>a) return true;
    }
    return false;
}

bool check(string a, string b){
    int m = a.length();
    for (int i=0;i<m;i++){
        if (a[i]>b[i]) return false;
        else if (a[i]<b[i]) return true;
    }
    return false;
}

bool cmp(string a, string b){
    int m = a.length();
    int n = b.length();
    // if (m==1) return false;
    // if (n==1) return true;
    if (m>n) return !cmp(b,a);
    if (pat(a,b)){
        if (m==n) return false;
        string temp = b;
        temp.erase(temp.begin(),temp.begin()+m);
        if (m==1) return check(a[0],temp);
        else return cmp(a,temp);
    }
    else return check(a,b);
}

void sort(vector<string>& store){
    int n = store.size();
    if (n<=1) return;
    for (int i=0;i<n-1;i++){
        int swapping = 0;
        for (int j=0;j<n-i-1;j++){
            if (cmp(store[j],store[j+1])) {
                swap (store[j],store[j+1]);
                swapping++;
            }
        }
        if (swapping==0) return;
    }
}

void catching(vector<int>nums, int num, string& answer){
    int n = nums.size();
    if (n==0) return;
    vector<string> store;
    char check = '0' + num;
    for (int i=0;i<n;i++){
        string temp = D2S(nums[i]);
        if (temp[0]==check) store.push_back(temp);
    }
    sort (store);
    for (auto val : store) answer += val;
}

string largestNumber(vector<int>& nums){
    int n = nums.size();
    if(n==1){
        string answer = D2S(nums[0]);
        return answer;
    }
    string answer = "";
    for (int i=9;i>0;i--) catching (nums,i,answer);
    for (auto val : nums) {
        if (val==0) answer+='0';
    }
    int l = answer.length();
    int count = 0;
    for (int i=0;i<l;i++){
        if (answer[i]=='0') count++;
        else break;
    }
    if (count==l) answer = "0";
    return answer;    
}

int main(){
    vector<int> nums = {1113,111311};
    std::cout<<largestNumber(nums)<<std::endl;
    return 0;
}