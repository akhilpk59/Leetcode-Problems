#include<iostream>
#include<vector>
using std::vector;

int maximumGap(vector<int>& nums){
    int n = nums.size();
    if (n<2) return 0;
    vector<bool> exist;
    for (int i=0;i<1000000001;i++) exist.push_back(false);
    for (auto val : nums) exist[val] = true;
    int gap = 0;
    int current = 0;
    bool start = false;
    for (int i=0;i<1000000001;i++){
        if (!exist[i]&&!start) continue;
        else if (exist[i]&&!start) {
            start = true;
            current++;
        }
        else if (exist[i]&&start) {
            if (current>gap) gap = current;
            current = 1;
        }
        else if (!exist[i]&&start) current++;
    }
    return gap;
}

int main(){
    vector<int> nums = {3,6,9,1};
    std::cout<<maximumGap(nums)<<std::endl;
    return 0;
}