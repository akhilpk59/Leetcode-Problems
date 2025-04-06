#include<iostream>
#include<vector>
using std::vector;



vector<vector<int>> combine (int k, int n, vector<int> nums){
    vector<vector<int>> answer;
    int l = nums.size();
    if (l==0){
        if (n!=0||k!=0) return answer;
        else {
            vector<int> temp;
            answer.push_back(temp);
            return answer;
        }
    }
    if (n==0){
        if (k==0) {
            vector<int> temp;
            answer.push_back(temp);
            return answer;
        }
        return answer;
    }
    
    if (l==1){
        vector<int> temp;
        if (nums[0]==n&&k==1) {
            temp.push_back(nums[0]);
            answer.push_back(temp);
            return answer;
        }
        else return answer;
    }
    
    for (int i=0;i<l;i++){
        if (nums[i]>n) return answer;
        vector<int> remaining = nums;
        remaining.erase(remaining.begin(),remaining.begin()+i+1);
        vector<vector<int>> remain = combine(k-1,n-nums[i],remaining);
        int k = remain.size();
        if (k!=0){
            for (int j=0;j<k;j++) {
                remain[j].insert(remain[j].begin(),nums[i]);
                answer.push_back(remain[j]);
            }
        }
    }
    return answer;
}

vector<vector<int>> combinationSum3(int k,int n){
    vector<vector<int>> answer;
    if (n<=2) return answer;
    int minim = (k*(k+1))/2;
    if (n<minim) return answer;
    else if (n==minim){
        vector<int> temp;
        for (int i=1;i<=k;i++) temp.push_back(i);
        answer.push_back(temp);
        return answer;
    }
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    return combine(k,n,nums);
}

int main(){
    int k;
    int n;
    std::cin>>k>>n;
    vector<vector<int>> answer = combinationSum3(k,n);
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}