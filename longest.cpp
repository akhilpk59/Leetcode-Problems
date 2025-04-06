#include<iostream>
#include<vector>
using std::vector;

int compute (vector<int> nums, int start){
    int n = nums.size();
    if (n==0) return 0;
    if (n==1){
        return (start<nums[0]) ? 1 : 0;
    }
    int maxim = 0;
    for (int i=0;i<n;i++){
        if (nums[i]<=start) continue;
        vector<int> temp = nums;
        temp.erase(temp.begin(),temp.begin()+i+1);
        int remain = compute(temp,nums[i]);
        if (maxim<1+remain) maxim = 1 + remain;
    }
    return maxim;
}

int lengthOfLIS (vector<int>& nums){
    int n = nums.size();
    if (n==0) return 0;
    if (n==1) return 1;
    int maxim = 0;
    for (int i=0;i<n;i++){
        vector<int> temp = nums;
        temp.erase(temp.begin(),temp.begin()+i+1);
        int remain = compute(temp,nums[i]);
        if (1+remain>maxim) maxim = 1 + remain;
    }
    return maxim;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout<<lengthOfLIS(nums)<<std::endl;
    return 0;
}