#include<iostream>

using namespace std;

int main(){
    int target;
    cin>>target;
    int arr[] = {7,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool sum[target+1];
    
    for (int i=0;i<=target;i++) sum[i] = false;

    sum[0] = true;

    for (int i = 0;i<=target;i++){
        if (sum[i]){
            for (int j=0;j<n;j++){
                int temp = i + arr[j];
                if (temp<=target) sum[temp] = true;
            }
        }
    }

    cout<<boolalpha<<sum[target]<<endl;
    return 0;
}