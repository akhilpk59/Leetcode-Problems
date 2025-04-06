#include<iostream>
#include<vector>

using namespace std;

static vector<int> solve;
static bool flag = true;
static vector<int> compare;

vector<int> bestSum(int target, int arr[], int n){
    if (target==0){
        flag = true;
        return solve;
    }
    if (target<0){
        flag = false;
        return solve;
    }
    for (int i=0;i<n;i++){
        int remainder = target - arr[i];
        solve = bestSum(remainder,arr,n);
        if (flag){
            solve.push_back(arr[i]);
        }
    }
    
    return solve;
}

int main(){
    int n;
    cin>>n;
    int arr[] = {1,2,5,25};
    int l = sizeof(arr)/sizeof(arr[0]);
    //vector<int> answer;
    compare = bestSum(n,arr,l);
    if (compare.size()==0) {
        cout<<"No combination exists"<<endl;
        return 0;
    }
    for (auto val : compare){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}