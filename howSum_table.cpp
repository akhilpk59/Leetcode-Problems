#include<iostream>
#include<vector>

using namespace std;

int main(){
    int target;
    cin>>target;
    vector<vector<int>> answer(target+1);
    int arr[] = {7,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> empty;
    answer[0] = empty;
    for (int i=0;i<=target;i++){
        if (!answer[i].empty()||i==0){
            for (int j=0;j<n;j++){
                vector<int> temp = answer[i];
                temp.push_back(arr[j]);
                if (i+arr[j]<=target) answer[i+arr[j]] = temp;
            }
        }
    }
    if (answer[target].empty()){
        cout<<"No combination exists"<<endl;
        return 0;
    }
    for (auto val : answer[target]){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}