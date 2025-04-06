#include<iostream>
#include<vector>
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val(x) , next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

vector<int> merge(vector<int> arrL, vector<int> arrR){
    int nL = arrL.size();
    int nR = arrR.size();
    int i = 0;
    int j = 0;
    vector<int> answer;
    while (i<nL&&j<nR) {
        if (arrL[i]<=arrR[j]) answer.push_back(arrL[i++]);
        else answer.push_back(arrR[j++]);
    }
    while (i<nL) answer.push_back(arrL[i++]);
    while (j<nR) answer.push_back(arrR[j++]);
    return answer;
}

void mergeSort(vector<int>& arr){
    int n = arr.size();
    if (n<=1) return;
    vector<int> arrL;
    vector<int> arrR;
    int mid = (n-1)/2;
    for (int i=0;i<=mid;i++) arrL.push_back(arr[i]);
    for (int i = mid+1;i<n;i++) arrR.push_back(arr[i]);
    mergeSort(arrL);
    mergeSort(arrR);
    arr = merge(arrL,arrR);
}

ListNode* sortList (ListNode*& head){
    if (head==NULL||head->next==NULL) return head;
    vector<int> arr;
    ListNode* temp = head;
    while (temp!=NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    mergeSort(arr);
    temp = head;
    for (auto value : arr) {
        temp->val = value;
        temp = temp->next;
    }
    return head;
}

int main(){

    return 0;
}