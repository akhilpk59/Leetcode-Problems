#include<iostream>
#include<vector>
using std::vector;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    if (n==1) return 1;
    int temp = nums[0];
    auto it = nums.begin()+1;
    while (it!=nums.end()){
        if (*(it) == temp) {
            it = nums.erase(it);
            continue;
        }
        else {
            temp = *(it);
            it++;
        }
    }
    n = nums.size();
    return n;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    std::cout<<removeDuplicates(nums)<<std::endl;
    for (auto val : nums){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}