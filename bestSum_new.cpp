#include<iostream>
#include<vector>
#include<map>

using namespace std;

static vector<int> solve;
static bool flag = true;
static map <int, vector<int>> result;

vector<int> bestSum (int target, int arr[], int n){
    if (result.find(target)!=result.end()) return result[target];
    if (target==0){
        flag = true;
        return solve;
    }
    if (target<0){
        flag = false;
        return solve;
    }
    vector<int> compare;

    for (int i=0;i<n;i++){
        
        int remain = target - arr[i];
        solve = bestSum(remain,arr,n);
        if (flag) solve.push_back(arr[i]);
        if (solve.size()!=0){
            if (solve.size()<compare.size()||compare.size()==0){
                compare = solve;
                //solve.clear();
            }
            solve.clear();
        }     
    }
    // solve.clear();
    flag = true;
    result[target] = compare;
    return compare;
}

int main(){
    int target;
    cin>>target;
    int arr[] = {1,2,5,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> answer;
    answer = bestSum(target,arr,n);
    for (auto val : answer){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}