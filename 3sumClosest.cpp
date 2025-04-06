#include<iostream>
#include<map>
#include<set>
#include<vector>
using std::vector;

vector<int> merge(vector<int> numsL, vector<int> numsR){
    vector<int> result;
    int nL = numsL.size();
    int nR = numsR.size();
    int i=0;
    int j=0;
    while (i<nL&&j<nR){
        if (numsL[i]<=numsR[j]) result.push_back(numsL[i++]);
        else result.push_back(numsR[j++]);
    }
    while (i<nL) result.push_back(numsL[i++]);
    while (j<nR) result.push_back(numsR[j++]);
    return result;
}

void mergeSort(vector<int>& nums){
    int n = nums.size();
    if (n<=1) return;
    int mid = (n-1)/2;
    vector<int> numsL;
    vector<int> numsR;
    for (int i=0;i<=mid;i++){
        numsL.push_back(nums[i]);
    }
    for (int i=mid+1;i<n;i++){
        numsR.push_back(nums[i]);
    }
    mergeSort(numsL);
    mergeSort(numsR);
    nums = merge(numsL,numsR);
}

int mod (int x){
    return (x>=0) ? x : 0-x;
}

int threeSumClosest(vector<int>& nums, int target){
    mergeSort(nums);
    for (auto val : nums) std::cout<<val<<" ";
    std::cout<<std::endl;
    int n = nums.size();
    int diff = 0;
    bool flag = true;
    int sum;
    int finale;
    // bool nFlag = false; 
    for (int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        sum = nums[i] + nums[j] +nums[k];
        if (sum==target) return target;
        else if (sum<target) j++;
        else k--;
        if (mod(sum-target)<mod(diff)||flag){
            diff = mod(sum-target);
            flag = false;
            finale = sum;
        }
        // for (int j=i+1;j<n-1;j++){
        // int k = n-1;
        // int current;
        // while (j<k){
        //     current = check  - nums[j] - nums[k];
        //     if (current==0) return target;
        //     if (mod(current)<mod(minim)||flag) {
        //         // if (current<0) nFlag = true;
        //         // else nFlag = false;
        //         minim = current;
        //         std::cout<<"nums : "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" minim : "<<minim<<" current: "<<current<<std::endl;
        //         flag = false;
        //     }
        //     k--;
        // }
        // // while(j<k){
        // //     current = check - nums[j] - nums[k];
        // //     if (current==0) return target;
        // //     if (mod(current)<minim||flag) {
        // //         if (current<0) nFlag = true;
        // //         else nFlag = false;
        // //         minim = current;
        // //         flag = false;
        // //     }
        // //     k--;
        // // }           
        // }
    }
    return finale;
}

int main(){
    vector<int> nums = {-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1};
    int target;
    std::cin>>target;
    std::cout<<threeSumClosest(nums,target)<<std::endl;
    return 0;
}