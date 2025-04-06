#include<iostream>
#include<vector>
using std::vector;

int maxim(int a, int b, int c){
    return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
}
int maxProduct(vector<int>& nums){
    int n = nums.size();
    if (n==0) return 0;
    if (n==1) return nums[0];
    int countNegative = 0;
    bool zero[n];
    bool negative[n];
    int countZero = 0;
    for (int i=0;i<n;i++) {
        zero[i] = false;
        negative[i] = false;
    }
    for (int i=0;i<n;i++) {
        if (nums[i]<0) {
            countNegative++;
            negative[i] = true;
        }
        else if (nums[i]==0) {
            zero[i] = true;
            countZero++;
        }
    }
    if (countZero==n) return 0;
    if (countZero==0){
            int answer = 1;
        if (countNegative%2==0) {            
            for (auto val : nums) answer*=val;
            return answer;
        }
        else {
            int val1 = 1;
            int val2 = 1;
            bool start = false;
            int val3 = 1;

            for (int i=0;i<n;i++) {
                if (negative[i]) break;
                else val1*=nums[i];
            }
            for (int i=0;i<n;i++){
                if (negative[i]) {
                    countNegative--;
                    if (countNegative==0) break;
                    val2*=nums[i];
                }
                else val2*=nums[i];
            }
            for (int i=0;i<n;i++){
                if (negative[i]&&!start) {
                    start = true;
                }
                else {
                    if (!start) continue;
                    else val3*=nums[i];
                }
            }
            return maxim (val1,val2,val3);
        }  
    }

    else {
        int i = 0;
        int product = 1;
        bool flag = false;
        vector<int> temp;
        while (i<n){
            while (i<n&&!zero[i]){
                temp.push_back(nums[i]);
                i++;
            }
            int current = maxProduct(temp);
            if (current>product||!flag) {
                product = current;
                flag = true;
            }
            temp.clear();
            i++;
        }
        return (product>0) ? product : 0;
    }
}

int main(){
    vector<int> nums = {6,3,-10,0,2};
    std::cout<<maxProduct(nums)<<std::endl;
    return 0;
}