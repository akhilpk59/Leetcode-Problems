#include<iostream>
#include<vector>
using namespace std;

void merge (vector<int> &a, int start, int end){
int k = (start+end)/2;
int i = start;
int j = k+1;
vector<int> b;
while((i<k+1)&&(j<end+1)){
    if (a[i]<a[j]){
        b.push_back(a[i]);
        i++;
    }
    else {
        b.push_back(a[j]);
        j++;
    }
}
if (i==k+1){
    while (j<end+1){
        b.push_back(a[j]);
        j++;
    }
}
else if (j==end+1){
    while(i<k+1){
        b.push_back(a[i]);
        i++;
    }
}
int x = start;
int l = 0;
while (x<end+1){
    a[x++] = b[l++];
}

}

void merge_sort(vector<int>& a, int start, int end){
    if (start>=end) return;
    int k = (end+start)/2;
    merge_sort(a,start,k);
    merge_sort(a,k+1,end); 
    merge(a,start,end);
}
int main(){
    vector<int> a = {9,1,4,-8,2,5,4,7,3,-3,6,4,-1};
    int n = a.size();
    merge_sort(a,0,n-1);
    for (auto val : a){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}