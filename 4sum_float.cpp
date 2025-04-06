#include<iostream>
#include<vector>
#include<set>
#include<map>
using std::vector;

vector<double> merge (vector<double> numsL, vector<double> numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    int i = 0;
    int j = 0;
    vector<double> answer;
    while (i<nL&&j<nR){
        if (numsL[i]<=numsR[j]) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort(vector<double>& nums){
    int n = nums.size();
    if (n<=1) return;
    int mid = (n-1)/2;
    vector<double> numsL;
    vector<double> numsR;

    for (int i=0;i<=mid;i++) numsL.push_back(nums[i]);
    for (int i=mid+1;i<n;i++) numsR.push_back(nums[i]);
    mergeSort(numsL);
    mergeSort(numsR);
    nums = merge(numsL,numsR);
}

vector<vector<double>> fourSum (vector<double>& nums, double target){
    int n = nums.size();
    vector<vector<double>> answer;
    if (n<=3) return answer;
    mergeSort(nums);
    std::map <std::set<double>, int> store;
    int ind = 1;
    for (int i=0;i<n-3;i++){
        for (int j=i+1;j<n-2;j++){
            double rem = target - nums[i] - nums[j];
            int k = j+1;
            int l = n-1;
            while (k<l){
                if ((nums[k]+nums[l])==rem){
                    std::set<double> temp;
                    temp.insert(nums[i]);
                    temp.insert(nums[j]);
                    temp.insert(nums[k]);
                    temp.insert(nums[l]);
                    if (store.find(temp)==store.end()) store[temp] = ind++;
                    k++;
                    l--;
                }
                else if ((nums[k]+nums[l])>rem) l--;
                else k++;
            }
        }
    }
    for (auto it = store.begin();it!=store.end();it++){
        std::set<double> temp = it->first;
        vector<double> keep;
        for (auto itr = temp.begin();itr!=temp.end();itr++){
            keep.push_back(*itr);
        }
        if (keep.size()==1) {
            keep.push_back(keep[0]);
            keep.push_back(keep[0]);
            keep.push_back(keep[0]);
        }
        else if (keep.size()==2){
            if ((2*(keep[0]+keep[1]))==target)  {
                keep.push_back(keep[0]);
                keep.push_back(keep[1]);
            }
            else if (((3*keep[0])+keep[1])==target){
                keep.push_back(keep[0]);
                keep.push_back(keep[0]);
            }
            else {
                keep.push_back(keep[1]);
                keep.push_back(keep[1]);
            }
        }
        else if (keep.size()==3){
            if (((2*keep[0]) + keep[1] + keep[2])==target) keep.push_back(keep[0]);
            else if (((2*keep[1]) + keep[0] + keep[2])==target) keep.push_back(keep[1]);
            else keep.push_back(keep[2]);
        }
        answer.push_back(keep);
    }
    return answer;
}


int main(){
    vector<vector<double>> answer;
    vector<double> nums = {0,0,0,-1000000000,-1000000000,-1000000000,-1000000000};
    double target;
    std::cin>>target;
    answer = fourSum(nums,target);

    for (auto val : answer){
        for (auto ele : val) std::cout<<ele<<" ";
        std::cout<<std::endl;
    }

    return 0;
}