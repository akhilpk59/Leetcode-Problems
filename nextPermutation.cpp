#include<iostream>
#include<vector>

using std::vector;

void swap (int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

vector<int> merge(vector<int> numsL,vector<int> numsR){
    vector<int> answer;
    int nL = numsL.size();
    int nR = numsR.size();
    int i=0;
    int j=0;

    while (i<nL&&j<nR){
        if (numsL[i]<=numsR[j]) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }

    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort(vector<int>& nums, int start, int end){
    if (start>=end) return;
    int mid = (start+end)/2;
    mergeSort(nums,start,mid);
    mergeSort(nums,mid+1,end);
    vector<int> numsL;
    vector<int> numsR;
    for (int i=start;i<=mid;i++) numsL.push_back(nums[i]);
    for (int i=mid+1;i<=end;i++) numsR.push_back(nums[i]);
    vector<int> answer = merge(numsL,numsR);
    for (int i=start;i<=end;i++) nums[i] = answer[i-start];
    return;
}

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    if (n==1) return;
    int stop = -1;
    for (int i=n-2;i>=0;i--){
        if (nums[i]>=nums[i+1]) continue;
        else {
            stop = i;
            break;
        }
    }

    if (stop==-1) {
        mergeSort(nums,0,n-1);
        return;
    }
    else {
        int j = n-1;
        while (nums[stop]>=nums[j]) j--;
        swap(nums[stop],nums[j]);
        mergeSort(nums,stop+1,n-1);
        return;
    }
    return;
}

int main(){
    vector<int> nums = {1,1,5};
    for (auto val : nums) std::cout<<val<<" ";
    std::cout<<std::endl;
    nextPermutation(nums);
    for (auto val: nums) std::cout<<val<<" ";
    std::cout<<std::endl;

    return 0;
}