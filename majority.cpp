#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

vector<int> majorityElement(vector<int>& nums){
    int n = nums.size();
    map<int,int> store;
    for (int i=0;i<n;i++){
        if (store.find(nums[i])!=store.end()) store[nums[i]]++;
        else store[nums[i]] = 1;
    }
    int target = n/3;
    vector<int> answer;
    for (auto it = store.begin();it!=store.end();it++){
        if (it->second>target) answer.push_back(it->first);
    }
    return answer;
}