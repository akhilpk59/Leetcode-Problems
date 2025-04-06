#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    double median[m+n];

    for (int i=0;i<=(m+n)/2;i++){
        if (nums1.size()==0){
            median[i] = nums2[0];
            nums2.erase(nums2.begin());
        }
        else if (nums2.size()==0){
            median[i]= nums1[0];
            nums1.erase(nums1.begin());
        }
        else {
            if (nums1[0]<nums2[0]){
                median[i] = nums1[0];
                nums1.erase(nums1.begin());
            }
            else {
                median[i] = nums2[0];
                nums2.erase(nums2.begin());
            }
        }
    }
    if ((m+n)%2!=0) return median[((m+n)/2)];
    else return (median[((m+n)/2)-1] + median[(m+n)/2])/2;
}

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    cout<<findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}