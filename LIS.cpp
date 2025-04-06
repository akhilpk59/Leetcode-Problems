#include<iostream>
#include<vector>
using std::vector;

int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    if (n==0||n==1) return n;
    int length[n];
    for (int i=0;i<n;i++) length[i]=1;
    
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (nums[j]>nums[i]){
                if (length[j]<length[i]+1) length[j] = length[i]+1;
            }
        }
    }

    int maxim = 0;
    for (int i=0;i<n;i++){
        if (length[i]>maxim) maxim = length[i];
    }
    return maxim;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout<<lengthOfLIS(nums)<<std::endl;
    return 0;
}