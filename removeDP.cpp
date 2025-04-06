#include<iostream>
#include<vector>

using std::vector;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    if (n==1) return 1;
    int count = 1;
    int temp = nums[0];
    for (auto it = nums.begin()+1; it!=nums.end();it++){
        if (*it==temp) {
            count++;
        if (count>2) {
            it = nums.erase(it);
            count--;
            it--;
        }
        }
        else {
            temp = *it;
            count = 1;
        }
    }
    return nums.size();
}

int main(){
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    std::cout<<removeDuplicates(nums)<<std::endl;
    return 0;
}