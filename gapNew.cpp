#include<iostream>
#include<vector>
using std::vector;

vector<int> merge(vector<int> numsL, vector<int> numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    int i = 0;
    int j = 0;
    vector<int> answer;
    while (i<nL&&j<nR){
        if (numsL[i]<=numsR[j])answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort(vector<int>& nums){
    int n = nums.size();
    if (n<=1) return;
    vector<int> numsL;
    vector<int> numsR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) numsL.push_back(nums[i]);
    for (int i = mid+1;i<n;i++) numsR.push_back(nums[i]);
    mergeSort(numsL);
    mergeSort(numsR);
    nums = merge(numsL,numsR);
}

int maximumGap(vector<int>& nums){
    int n = nums.size();
    if (n<2) return 0;
    mergeSort(nums);
    int gap = 0;
    for (int i = 1;i<n;i++){
        int diff = nums[i] - nums[i-1];
        if (diff>gap) gap = diff;
    }
    return gap;
}

int main(){

    return 0;
}