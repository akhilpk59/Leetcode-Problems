#include<iostream>
#include<vector>
using std::vector;

int maxProduct (vector<int>& nums){
    int n = nums.size();
    if (n==1) return nums[0];
    int i = 0;
    int Maxim = nums[0];
    int current = 1;
    while (i<n){
        int prev = current;
        current *= nums[i];
        if (nums[i]>current) {
            if (nums[i]>Maxim) Maxim = nums[i];
            current = nums[i];
            i++;
            continue;
        }
        if (current>Maxim) Maxim = current;
        else if (prev>current){
            current = 1;
            continue;
        }

    }
}

int main(){

    return 0;
}