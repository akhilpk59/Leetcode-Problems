#include<iostream>
#include<vector>
using namespace std;

//static int counting = 0;

void swap (int& a, int& b){
    int temp = a;
    a=b;
    b=temp;
}

void quick_sort(vector<int>& a, int start, int end){
  //  if (counting==5) return;
    if ((start>=end)||(end<=0)) return;
    else if ((end-start)==1){
        if (a[start]>a[end]) swap (a[start],a[end]);
        return;
    }
    int n = (end - start) + 1;
    int part = a[end];
    int ei = n-1;
    int si = 0;
    int b[n];
    for (int i=start;i<end;i++){
        if (a[i]<part) b[si++] = a[i];
        else b[ei--] = a[i];
    }
    b[si] = part;
    // cout<<si<<endl;
    for (int i = start,k=0;i<=end;i++,k++){
        a[i] = b[k];
    }
    // for (auto val : a){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    // cout<<start<<" "<<si-1<<endl;
    // cout<<si+1<<" "<<end<<endl;
    //cout<<counting<<endl;
    //counting++;
    // cout<<"---------------------------------"<<endl;
    quick_sort(a,start,start+si-1);
    quick_sort(a,start+si+1,end);
}

int main(){
    vector<int> a = {4,3,-2,5,6,1,8,-9,9,7,2,-5,10};
    int n = a.size();
    quick_sort(a,0,n-1);
    for (auto val : a){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}