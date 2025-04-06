#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int target;
    cin>>target;
    int arr[] = {1,2,5,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> answer(target+1);

    for (int i=0;i<=target;i++){
        if (!answer[i].empty()||i==0){
            for (int j=0;j<n;j++){
                vector<int> temp = answer[i];
                temp.push_back(arr[j]);
                if (i+arr[j]<=target){
                    if ((answer[i+arr[j]].size()==0)||(temp.size()<answer[i+arr[j]].size())) answer[i+arr[j]] = temp;
                }
            }
        }
    }
    if (answer[target].size()==0){
        cout<<"No combination exists"<<endl;
        return 0;
    }
    for (auto val : answer[target]){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}