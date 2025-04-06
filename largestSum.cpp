#include<iostream>
#include<vector>

using std::vector;

int maxim(int x, int y, int z){
    return (x>y) ? ((x>z) ? x : z) : ((y>z) ? y: z);
}

int maxSubArray(vector<int>& nums){
    int n = nums.size();
    if (n==1) return nums[0];
    int maxsum = nums[0];
    int current = nums[0];
    for (int i=1;i<n;i++){
        current +=nums[i];
        if (nums[i]>current) {
            maxsum = maxim(nums[i],current,maxsum);
            current = maxsum;
            continue;
        }
        if (current>maxsum) maxsum = current;
    }
    return maxsum;
}

int main(){
    vector<int> nums = {1};
    std::cout<<maxSubArray(nums)<<std::endl;
    return 0;
}