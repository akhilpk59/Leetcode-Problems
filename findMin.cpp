#include<iostream>
#include<vector>
using std::vector;

int findMin(vector<int>& nums){
    int n = nums.size();
    if (n==1) return nums[0];
    if (nums[0]<nums[n-1]) return nums[0];
    int start = 0;
    int end = n-1;
    while (end-start>1){
        int mid = (start+end)/2;
        if (nums[mid]<nums[start]) end = mid;
        else start = mid;
    }
    return (nums[start]<nums[end]) ? nums[start] : nums[end];
}

int main(){
    vector<int> nums = {11,13,15,17};
    std::cout<<findMin(nums)<<std::endl;
    return 0;
}