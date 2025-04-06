#include<iostream>
#include<vector>
#include<map>
#include<utility>
using std::vector;

vector<int> merge(vector<int> mergeL, vector<int> mergeR){
    int nL = mergeL.size();
    int nR = mergeR.size();
    int i = 0;
    int j = 0;
    vector<int> answer;
    while (i<nL&&j<nR){
        if (mergeL[i]<=mergeR[j]) answer.push_back(mergeL[i++]);
        else answer.push_back(mergeR[j++]);
    }
    while (i<nL) answer.push_back(mergeL[i++]);
    while (j<nR) answer.push_back(mergeR[j++]);
    return answer;
}

void mergeSort(vector<int>& candidates){
    int n = candidates.size();
    if (n<=1) return;
    int mid = (n-1)/2;
    vector<int> candidatesL;
    vector<int> candidatesR;
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
    std::map< std::map<int, int>, int> total;
    int ind = 1;
    for (int i=0;i<n;i++){
        vector<int> ele = answer[i];
        int m = ele.size();
        std::map <int , int> freq;
        for (int j=0;j<m;j++){
            if (freq.find(ele[j])!=freq.end()) freq[ele[j]]++;
            else freq[ele[j]] = 1;
        }
        if (total.find(freq)==total.end()) total[freq] = ind++;
        else return false;
    }
    std::map<int,int> freq2;
    int k = temp.size();
    for (int i=0;i<k;i++) {
        if (freq2.find(temp[i])!=freq2.end()) freq2[temp[i]]++;
        else freq2[temp[i]]=1;
    }
    if (total.find(freq2)!=total.end()) return false;
    else return true;
}

std::map <std::pair<int, vector<int>> , vector<vector<int>>> result;

vector<vector<int>> combinationSum2(vector<int> candidates, int target){
    vector<vector<int>> answer;
    int n = candidates.size();
    if (n==0) return answer;
    mergeSort(candidates);
    std::pair<int, vector<int>> numes;
    numes.first = target;
    numes.second = candidates;
    if (result.find(numes)!=result.end()) return result[numes];
    for (int i =0;i<n;i++){
        if (target<candidates[i]) {
            result[numes] = answer;
            return answer;
        }
        else {
            if (target==candidates[i]){
                vector<int> temp1;
                temp1.push_back(candidates[i]);
                if (noDuplicate(answer,temp1)) answer.push_back(temp1);
                result[numes] = answer;
                return answer;
            }
            vector<int> modified = candidates;
            auto it = std::find(modified.begin(),modified.end(),candidates[i]);
            modified.erase(it);
            // if (candidates[i]==3) {
            //     for (auto view : modified) std::cout<<view<<" ";
            //     // std::cout<<"target - candidates[i] : "<<target<<" - "<<candidates[i]<<" : "<<target-candidates[i]<<std::endl;
            // }
            vector<vector<int>> temp;
            std::pair<int, vector<int>> less;
            less.first = target - candidates[i];
            less.second = modified;
            if (result.find(less)==result.end()) result[less] = combinationSum2(modified,target-candidates[i]);
            temp = result[less];
            if (temp.size()==0) continue;
            for (auto val : temp){
                val.push_back(candidates[i]);
                if (noDuplicate(answer,val)) answer.push_back(val);
            }
        }
    }
    result[numes] = answer;
    return answer;
}

int main(){
    vector<int> candidates = {4,4,2,1,4,2,2,1,3};
    int target;
    std::cin>>target;
    vector<vector<int>> answer = combinationSum2(candidates,target);
    std::cout<<"----------------------"<<std::endl;
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }

    return 0;
}