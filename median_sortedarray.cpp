#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double target;
        int num = ((m+n)/2)+1;
        if ((m+n)%2!=0) target = searching(nums1,nums2,m,n,num);
        else target = (searching(nums1,nums2,m,n,num) + searching(nums1,nums2,m,n,num-1))/2;
        return target;
    }

private:
    double searching (vector<int>& nums1, vector<int>& nums2, int m, int n, int num){
        int result;
        int i = 0;
        int j = 0;
        for (int k=0;k<num;k++){
            if ((nums1[i]<=nums2[j])&&(i<m)&&(j<n)){
                result = nums1[i];
                i++;
            }
            else if ((nums1[i]>nums2[j])&&(i<m)&&(j<n)){
                result = nums2[j];
                j++;
            }
            else {
                if (i==m){
                    while (k!=num){
                        result = nums2[j];
                        k++;
                        j++;
                    }
                    return result;
                }
                else if (j==n){
                    while (k!=num){
                        result = nums1[i];
                        k++;
                        i++;
                    }
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums1 = {1,2,4,7,10,13,15};
    vector<int> nums2 = {3,4,4,6,8,9,10};
    Solution test;
    cout<<test.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}