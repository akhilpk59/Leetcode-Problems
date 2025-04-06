#include<iostream>
#include<vector>
using std::vector;

int check(int arr[], int start, int end){
    if ((end-start)<2) return -1;
    int mid = (start+end)/2;
    if (arr[mid-1]<arr[mid]&&arr[mid+1]<arr[mid]) return mid;
    else {
        int num1 = check (arr,start,mid);
        if (num1!=-1) return num1;
        int num2 = check (arr,mid,end);
        return num2;
    }
}

int findPeakElement(vector<int> nums){
    int n = nums.size();
    if (n==1) return 0;
    if (n==2) return (nums[0]<nums[1]) ? 1 : 0;
    if (n==3) {
        if (nums[0]>nums[1]) return 0;
        else if (nums[2]>nums[1]) return 2;
        else return 1;
    }
    int arr[n];
    for (int i=0;i<n;i++) arr[i] = nums[i];
    int num = check(arr,0,n-1);
    if (num!=-1) return num;
    else return -1;
}

int main(){
    vector<int> nums = {1,2,1,3,5,6,4};
    std::cout<<findPeakElement(nums)<<std::endl;
    return 0;
}