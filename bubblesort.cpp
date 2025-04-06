#include<iostream>
#include<vector>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &a){
    int n = a.size();
    for (int i=0; i<n;i++){
        int swapping = 0;
        for (int j=0;j<n-i-1;j++){
            if (a[j+1]<a[j]){
                swap (a[j],a[j+1]);
                swapping++;
            }
        }
        if (swapping==0) return;
    }
}
int main(){
    vector<int> a {4,6,2,5,3,1,7};
    bubble_sort(a);
    for (auto value : a){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}