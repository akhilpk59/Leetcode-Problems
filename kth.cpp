#include<iostream>
#include<vector>

using std::vector;

vector<int> merge(vector<int> L, vector<int> R){
    int nL = L.size();
    int nR = R.size();
    int i = 0;
    int j = 0;
    vector<int> answer;
    while (i<nL&&j<nR){
        if (L[i]>=R[j]) answer.push_back(L[i++]); 
        else answer.push_back(R[j++]); 
    }
    while (i<nL) answer.push_back(L[i++]);
    while (j<nR) answer.push_back(R[j++]);
    return answer;
}

void mergeSort(vector<int>& nums){
    int n = nums.size();
    if (n==1) return;
    vector<int> numsL;
    vector<int> numsR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) numsL.push_back(nums[i]);
    for (int i=mid+1;i<n;i++) numsR.push_back(nums[i]);
    mergeSort(numsL);
    mergeSort(numsR);
    nums = merge(numsL,numsR);
}

int findKthLargest(vector<int>& nums, int k){
    mergeSort(nums);
    return nums[k-1];
}

int main(){

    return 0;
}