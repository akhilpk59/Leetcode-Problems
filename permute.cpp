#include<iostream>
#include<vector>
#include<map>
using std::vector;

void cleanUp (vector<vector<int>> & answer){
    std::map <vector<int>,int> check;
    int ind = 1;
    vector<vector<int>> store = answer;
    int n = store.size();
    if (n==1) return;
    for (int i=0;i<n;i++){
        vector<int> temp = store[i];
        if (check.find(temp)!=check.end()){
            auto f = std::find(answer.begin(),answer.end(),temp);
            answer.erase(f);
        }
        else check[temp] = ind++;
    }
    return;
}

vector<vector<int>> permute (vector<int>& nums){
    int n = nums.size();
    if (n==1) {
        vector<vector<int>> answer;
        answer.push_back(nums);
        return answer;
    }
    vector<vector<int>> answer;
    for (int i=0;i<n;i++){
        int num = nums[i];
        vector<int> temp = nums;
        temp.erase(temp.begin()+i);
        vector<vector<int>> combo = permute(temp);
        for (auto val : combo){
            val.push_back(num);
            answer.push_back(val);
        }
    }
    cleanUp(answer);
    return answer;
}

int main (){
    vector<int> nums = {1,2,3};
    vector<vector<int>> answer = permute(nums);
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}