#include<iostream>
#include<map>
using namespace std;

map<int, bool> memo;

bool canSum(int target, int nums [], int n){
    if (target==0) return true;
    else if (target<0) return false;
    if (memo.find(target)!=memo.end()) return memo[target];

    for (int i=0;i<n;i++){
        int remainder = target - nums[i];
        if (canSum(remainder,nums,n)) {
            if (memo.find(target)==memo.end()) memo[target] = true;
            return true;
        }
    }
    if (memo.find(target)==memo.end()) memo[target] = false;
    return false;
}
int main(){
    int target;
    cin>>target;
    int nums[] ={2,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<boolalpha<<canSum(target,nums,n)<<endl;
    return 0;
}