#include<iostream>
#include<vector>
#include<map>
using std::vector;
using std::map;

vector<int> productExceptSelf (vector<int>& nums){
    int index = -1;
    int zeroCount = 0;
    int n = nums.size();
    vector<int> answer;
    int product = 1;
    for (int i=0;i<n;i++){
        if (nums[i]==0) {
            zeroCount++;
            index = i;
        }
        else product*=nums[i];
        if (zeroCount==2) break;
    }
    bool nFlag = false;
    if (product<0) nFlag = true;
    map<int,int> store;
    if (zeroCount==2){
        for (int i=0;i<n;i++) answer.push_back(0);
        return answer;
    }
    else if (zeroCount==0){
        for (int i=0;i<n;i++){
            if (nums[i]==1||nums[i]==-1){
                if (nums[i]==1) answer.push_back(product);
                else answer.push_back(0-product);
                continue;
            }
            if (store.find(nums[i])!=store.end()) {
                answer.push_back(store[nums[i]]);
                continue;
            }
            int temp = product;
            if (temp<0) temp = 0 - temp;
            int target = 0;
            int subtractor = nums[i];
            bool nFlagSubtractor = false;
            if (subtractor<0) {
                nFlagSubtractor = true;
                subtractor = 0 - subtractor;
            }
            while (temp!=0){
                temp-=subtractor;
                target++;
            }
            if ((nFlagSubtractor&&nFlag)||(!nFlagSubtractor&&!nFlag)) {
                store[nums[i]] = target;
                answer.push_back(target);
            }
            else {
                store[nums[i]] = 0 - target;
                answer.push_back(0-target);
            }
        }
        return answer;
    }
    else {
        for (int i=0;i<n;i++){
            if (i==index) answer.push_back(product);
            else answer.push_back(0);
        }
        return answer;
    }
}

int main(){

    return 0;
}