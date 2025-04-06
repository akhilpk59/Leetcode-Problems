#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>& a){
    int n = a.size();
    for (int i=0;i<n-1;i++){
        int min = a[i];
        int index = i;
        for (int j=i+1;j<n;j++){
            if (a[j]<min){
                min = a[j];
                index = j;
            }
        }
        a[index]= a[i];
        a[i] = min;
    }
}
int main(){
    vector<int> a = {4,3,6,-2,1,5,7};
    selection_sort(a);
    for (auto val : a){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}