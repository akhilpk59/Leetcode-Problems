#include<iostream>
#include<map>
#include<vector>
using namespace std;

static vector<int> answer;
static bool flag = false;
map<int, vector<int>> result;


void howSum(int target, int arr[], int n){
   // if (result.find(target)!=result.end()) return;
    if (target==0) {
        flag = true;
        return;
    }
    else if (target<0) {
        answer.erase(answer.end()-1);
        flag = false;
        return;
    }
    for (int i=0;i<n;i++){
        int remainder = target - arr[i];
        answer.push_back(arr[i]);
        howSum(remainder,arr,n);
        if (!flag) answer.erase(answer.end()-1);
        if (flag) return;
    }
   // result[target] = answer;
    return;
}

int main(){
    int target;
    cin>>target;
    int arr[] = {2,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    howSum(target,arr,n);
    if (answer.size()==0){
        cout<<"There is no combination of elements in the array that can add up to the target"<<endl;
        return 0;
    }
    for (auto val : answer){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}