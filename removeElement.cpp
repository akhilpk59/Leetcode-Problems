#include<iostream>
#include<vector>
using std::vector;

int removeElement(vector<int> nums, int val){
    auto it = nums.begin();
    while (it!=nums.end()){
        if (*(it)==val){
            it = nums.erase(it);
        }
        else it++;
    }
    return nums.size();
}

int main(){
    int val;
    std::cin>>val;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    std::cout<<removeElement(nums,val)<<std::endl;
    return 0;
}