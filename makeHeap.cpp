#include<iostream>
#include<vector>
using std::vector;

void swap (int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>& nums){
    int n = nums.size();
    if (n<=1) return;
    for (int i=n-1;i>=0;i--){
        int lc = (2*i)+1;
        int rc = (2*i)+2;
        if (lc>=n&&rc>=n) continue;
        else if (rc>=n){
            if (nums[lc]>nums[i]) swap(nums[i],nums[lc]);
        }
        else {
            if (nums[i]>=nums[lc]&&nums[i]>=nums[rc]) continue;
            else if (nums[i]>=nums[lc]) swap (nums[i],nums[rc]);
            else if (nums[i]>=nums[rc]) swap (nums[i],nums[lc]);
            else {
                if (nums[lc]>nums[rc]) swap (nums[i],nums[lc]);
                else swap (nums[i],nums[rc]);
            }
        }
    }
}

int findKthLargest(vector<int>& nums, int k){
    int n = nums.size();
    if (n==1) return nums[0];
    int count = 0;
    heapify(nums);
    // std::cout<<"max heap : nums : ";
    // for (auto val : nums) std::cout<<val<<" ";
    // std::cout<<std::endl;
    while (k>1){
        nums[0] = nums.back();
        // std::cout<<"nums[0] : "<<nums[0]<<std::endl;
        count--;
        nums.erase(nums.end()-1);
        heapify(nums);
        // std::cout<<"max heap : nums : ";
        // for (auto val : nums) std::cout<<val<<" ";
        k--;
    }
    return nums[0];
}

int main(){
    int k;
    std::cin>>k;
    vector<int> nums = {-1,2,0};
    std::cout<<findKthLargest(nums,k)<<std::endl;
    return 0;
}