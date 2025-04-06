#include<iostream>
#include<string>
#include<vector>

using namespace std;

string D2S (int n){
    string temp = "";
    char val = '0' + n;
    temp += val;
    return temp;
}

int factorial (int n){
    if (n==0||n==1) return 1;
    return n*factorial(n-1);
}

string getPermutation (int& n, int& k, vector<int>& nums){
    if (n==1) return D2S(nums[0]);
    int x = (k%factorial(n-1)!=0) ? k/factorial(n-1) : (k/factorial(n-1)) - 1;
    string answer;
    answer+=D2S(nums[x]);
    nums.erase(nums.begin()+x);
    k -= (x*factorial(n-1));
    n--;
    return answer + getPermutation(n,k,nums);
}

string getPermutation (int n, int k){
    if (n==1) return "1";
    vector<int> nums;
    for (int i=1;i<=n;i++) nums.push_back(i);
    return getPermutation(n,k,nums);
}

int main() {
    int n,k;
    cin>>n>>k;
    string answer;
    answer = getPermutation(n,k);
    cout<<answer<<endl;
    return 0;
}