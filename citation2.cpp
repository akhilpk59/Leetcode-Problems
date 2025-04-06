#include<iostream>
#include<vector>

using std::vector;

int hIndex(vector<int>& citations){
    int n = citations.size();
    int start = 0;
    int end = n-1;
    int current = 0;
    while (start<=end){
        int mid = (start+end)/2;
        if (citations[mid]>(n-mid)) {
            if ((n-mid)>current) current = n - mid;
            else return n - mid;
            end = mid-1;
        }
        else {
            if (citations[mid]>current) current = citations[mid];
            else return citations[mid];
            start = mid+1;
        }
    }
    return current;
}

int main(){

    return 0;
}