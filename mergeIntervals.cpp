#include<iostream>
#include<vector>

using std::vector;

vector<vector<int>> join (vector<vector<int>> intervalsL, vector<vector<int>> intervalsR){
    int nL = intervalsL.size();
    int nR = intervalsR.size();
    vector<vector<int>> answer;
    int i = 0;
    int j = 0;
    while (i<nL&&j<nR){
        if (intervalsL[i][0]<=intervalsR[j][0]) answer.push_back(intervalsL[i++]);
        else answer.push_back(intervalsR[j++]);
    }
    while (i<nL) answer.push_back(intervalsL[i++]);
    while (j<nR) answer.push_back(intervalsR[j++]);
    return answer;
}

void mergeSort(vector<vector<int>>& intervals){
    int n = intervals.size();
    if (n<=1) return;
    int mid = (n-1)/2;
    vector<vector<int>> intervalsL;
    vector<vector<int>> intervalsR;
    for (int i=0;i<=mid;i++) intervalsL.push_back(intervals[i]);
    for (int i=mid+1;i<n;i++) intervalsR.push_back(intervals[i]);
    mergeSort(intervalsL);
    mergeSort(intervalsR);
    intervals = join(intervalsL,intervalsR);
}

int min (int x, int y){
    return (x<y) ? x : y;
}

int max(int x,int y){
    return (x>y) ? x : y; 
}

vector<vector<int>> merge (vector<vector<int>>& intervals){
    int n = intervals.size();
    if (n<=1) return intervals;
    mergeSort(intervals);
    vector<vector<int>> answer;
    vector<int> temp = intervals[0];
    for (int i=1;i<n;i++){
        if (intervals[i][0]>temp[1]){
            answer.push_back(temp);
            temp = intervals[i];
        }
        else {
            int minim = min(temp[0],intervals[i][0]);
            int maxim = max(temp[1],intervals[i][1]);
            temp.clear();
            temp.push_back(minim);
            temp.push_back(maxim);
        }
    }
    answer.push_back(temp);
    return answer;
}
int main(){
    vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> answer = merge(intervals);
    for (auto val : answer){
        for (auto nums : val)std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}