#include<iostream>
#include<vector>

using std::vector;

bool canJump(vector<int>& nums){
    int n = nums.size();
    if (n==1) return true;
    bool check[n];
    for (int i=0;i<n;i++) check[i] = false;
    check[0]= true;
    for (int i=0;i<n;i++){
        if (check[i]){
            int temp = nums[i];
            for (int j=1;j<=temp;j++){
                if (i+j<n) check[i+j] = true;
            }
        }
    }
    return check[n-1];
}

int main(){
    vector<int> nums = {3,2,1,0,4};
    std::cout<<canJump(nums)<<std::endl;
    return 0;
}