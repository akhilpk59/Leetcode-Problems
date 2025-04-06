#include<iostream>
#include<vector>

using std::vector;

int jump (vector<int>& nums){
    int n = nums.size();
    if (n<=1) return 0;
    int arr[n];
    for (int i =0;i<n;i++) arr[i] = 0;
    arr[0] = 1;
    int count = 0;
    for (int i=0;i<n;i++){
        if (arr[i]==0) continue;
        int change = nums[i];
        for (int j=1;j<=change;j++){
           if (((i+j)<n)&&((arr[i+j]>arr[i])||arr[i+j]==0)) arr[i+j] = arr[i] + 1;
        }
        if (arr[n-1]!=0) return arr[n-1]-1;
    }
    return count;
}

int main(){
    vector <int> nums = {1,2,1,1,1};
    std::cout<<jump(nums)<<std::endl;
    return 0;
}