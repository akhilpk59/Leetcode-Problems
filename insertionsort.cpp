#include<iostream>
#include<vector>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(vector<int>& a){
    int n = a.size();

    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (a[j]>a[i]) swap(a[j],a[i]);
        }
    }
}

int main(){

    vector<int> a = {4,1,4,3,5,4,7,6,4,4,2,4};
    insertion_sort(a);
    for (auto val : a){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}