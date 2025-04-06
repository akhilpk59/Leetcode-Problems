#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<map>
using std::vector;

static bool flag = true;
static std::map <int, vector<vector<int>>> result;

vector <int> merge(vector <int> numsL, vector <int> numsR){
    int nL = numsL.size();
    int nR = numsR.size();
    int i = 0;
    int j=0;
    vector<int> answer;
    while (i<nL&&j<nR){
        if (numsL[i]<=numsR[j]) answer.push_back(numsL[i++]);
        else answer.push_back(numsR[j++]);
    }
    while (i<nL) answer.push_back(numsL[i++]);
    while (j<nR) answer.push_back(numsR[j++]);
    return answer;
}

void mergeSort(vector<int>& candidates){
    int n = candidates.size();
    if (n<=1) return;
    vector<int> candidatesL;
    vector<int> candidatesR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) candidatesL.push_back(candidates[i]);
    for (int i=mid+1;i<n;i++) candidatesR.push_back(candidates[i]);
    mergeSort(candidatesL);
    mergeSort(candidatesR);
    candidates = merge(candidatesL,candidatesR);
    return;
}

bool noDuplicate(vector<vector<int>> answer, vector<int> temp){
    int n = answer.size();
    if (n==0) return true;
    std::map <std::map<int,int>,int> total;
    int ind = 1;
    for (int i = 0;i<n;i++){
        vector<int> temp1 = answer[i];
        int l = temp1.size();
        std::map <int, int> check;
        for (int j=0;j<l;j++){
            if (check.find(temp1[j])!=check.end()) check[temp1[j]]++;
            else check[temp1[j]] = 1; 
        }
        if (total.find(check)==total.end()) {
            total[check] = ind++;
        }
        else return false;
    }
    int k = temp.size();
    std::map<int,int> verify;
    for (int i=0;i<k;i++){
        if (verify.find(temp[i])!=verify.end()) verify[temp[i]]++;
        else verify[temp[i]] = 1;
    }
    if (total.find(verify)!=total.end()) return false;
    else return true;
}

vector<vector<int>> combinationSum (vector<int>& candidates, int target){
    vector<vector<int>> answer;
    int n = candidates.size();
    if (n==0) return answer;
    if (flag) {
        mergeSort(candidates);
        flag = false;
    }
    // if (target<candidates[0]) return answer;

    for (int i=0;i<n;i++){
        if (target<candidates[i]) {
            if (result.find(target)==result.end()) result[target] = answer;
            return answer;
        }
        else {
            if (target==candidates[i]) {
                vector<int> temp1; 
                temp1.push_back(candidates[i]);
                if (noDuplicate(answer,temp1)) answer.push_back(temp1);
                if (result.find(target)==result.end()) result[target] = answer;
                return answer;
            }
            vector<vector<int>> temp;
            if (result.find(target-candidates[i])==result.end()) result[target-candidates[i]] = combinationSum(candidates, target-candidates[i]);
            temp = result[target-candidates[i]];
            if (temp.size()==0) continue;
            else {
                for (auto val : temp) {
                    val.push_back(candidates[i]);
                    if (noDuplicate(answer,val)) answer.push_back(val);
                }
            }
        }
    }
    if (result.find(target)==result.end()) result[target] = answer;
    return answer;
}

int main(){
    vector<int> candidates = {3,5,8};
    int target;
    std::cin>>target;
    vector<vector<int>> answer = combinationSum(candidates,target);
    for (auto val : answer){
        for (auto num : val) std::cout<<num<<" ";
        std::cout<<std::endl;
    }
    return 0;
}