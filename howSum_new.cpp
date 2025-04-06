#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<int, vector<int>> result;
static vector<int> solve;
static bool flag = true;

vector<int> howSum (int target, int arr[], int n){
    
   if (result.find(target)!=result.end()) return result[target];

    if (target==0){
        flag = true;
        return solve;
    }
    if (target<0){
        flag = false;
        return solve;
    }

    for (int i=0;i<n;i++){
        int remain = target - arr[i];
        solve = howSum(remain, arr, n);
        if (flag) {
            solve.push_back(arr[i]);
           if (result.find(target)==result.end()) result[target] = solve;
            return solve;
        }
    }
    //vector<int> blank;
    if (result.find(target)==result.end()) {
        result[target] = solve;
    }
    return solve;
}
int main(){
    int n;
    cin>>n;
    int arr[] = {7,14};
    int l = sizeof(arr)/sizeof(arr[0]);
    vector<int> answer = howSum(n, arr, l);
    if (answer.size()==0) {
        cout<<"No combination exists"<<endl;
        return 0;
    }
    int count = 0;
    for (auto val : answer){
        cout<<val<<" ";
        count+= val;
    }
    cout<<endl;
    cout<<count<<endl;
    // cout<<"____________________________________________________________________________"<<endl;
    // count = 0;
    // for (auto val : result[n]){
    //     cout<<val<<" ";
    //     count+=val;
    // }
    // cout<<endl;
    // cout<<count<<endl;
    return 0;
}