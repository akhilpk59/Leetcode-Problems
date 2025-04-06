#include<iostream>
#include<vector>
using std::vector;

vector<int> merge(vector<int> numsL, vector<int> numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    vector<int> answer;
    int i = 0;
    int j = 0;
    while (i<nL&&j<nR){
        if (numsL[i]>=numsR[j]) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergesort(vector<int>& nums){
    int n = nums.size();
    if (n<=1) return;
    vector<int> numsL;
    vector<int> numsR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) numsL.push_back(nums[i]);
    for (int i=mid+1;i<n;i++) numsR.push_back(nums[i]);
    mergesort(numsL);
    mergesort(numsR);
    nums = merge(numsL,numsR);
}

int hIndex(vector<int>& citations){
    mergesort(citations);
    int highest = citations[0];
    int n = citations.size();
    for (int i = highest;i>=0;i--){
        int count = 0;
        for (int j=0;j<n;j++){
            if (citations[j]>=i) count++;
        }
        if (count>=i) return i;
    }
    return 0;
}

int main(){
    vector<int> citations = {4,4,0,0};
    std::cout<<hIndex(citations)<<std::endl;
    return 0;
}