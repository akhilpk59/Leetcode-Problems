#include<iostream>
#include<vector>
using std::vector;

int pow(int n){
    if (n==0) return 1;
    else return 2*pow(n-1);
}

void swap (int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void correction(int arr[],int n, int j, int last){
    if (j>last) return;
    int left = (2*j) + 1;
    int right = (2*j) + 2;
    if (left>=n&&right>=n) return;
    else if (right>=n){
        if (arr[left]>arr[j]) swap (arr[left],arr[j]);
    }
    else {
        if (arr[left]<=arr[j]&&arr[right]<=arr[j]) return;
        else {
            if (arr[left]<=arr[j]){
                swap(arr[right],arr[j]);
                correction(arr,n,right,last);
            }
            else if (arr[right]<=arr[j]){
                swap(arr[left],arr[j]);
                correction(arr,n,left,last);
            }
            else {
                int maxim = (arr[left]>arr[right]) ? arr[left] : arr[right];
                if (maxim==arr[left]){
                    swap(arr[left],arr[j]);
                    correction(arr,n,left,last);
                }
                else {
                    swap(arr[right],arr[j]);
                    correction(arr,n,right,last);
                }
            }
        }
    }
}

void correction(vector<int>& arr, int j, int last){
    int n = arr.size();
    if (j>last) return;
    int left = (2*j) + 1;
    int right = (2*j) + 2;
    if (left>=n&&right>=n) return;
    else if (right>=n){
        if (arr[left]>arr[j]) swap (arr[left],arr[j]);
    }
    else {
        if (arr[left]<=arr[j]&&arr[right]<=arr[j]) return;
        else {
            if (arr[left]<=arr[j]){
                swap(arr[right],arr[j]);
                correction(arr,right,last);
            }
            else if (arr[right]<=arr[j]){
                swap(arr[left],arr[j]);
                correction(arr,left,last);
            }
            else {
                int maxim = (arr[left]>arr[right]) ? arr[left] : arr[right];
                if (maxim==arr[left]){
                    swap(arr[left],arr[j]);
                    correction(arr,left,last);
                }
                else {
                    swap(arr[right],arr[j]);
                    correction(arr,right,last);
                }
            }
        }
    }
}

void heapify(int arr[], int n){
    if (n==1) return;
    int count = 0;
    int check = n;
    while (check>0){
        count++;
        check/=2;
    }
    int last = pow(count-1)-2;
    for (int j=n-1;j>=0;j--){
        if (j>last) continue;
        correction(arr,n,j,last);
    }
}

void heapify(vector<int>& arr){
    int n = arr.size();
    if (n<=1) return;
    int count = 0;
    int check = n;
    while (check>0){
        count++;
        check/=2;
    }
    int last = pow(count-1)-2;
    for (int j=n-1;j>=0;j--){
        if (j>last) continue;
        correction(arr,j,last);
    }
}

vector<int> heapSort(vector<int>& arr){
    int n = arr.size();
    heapify(arr);
    int counter = n;
    vector<int> answer;
    while (counter>0){
        // std::cout<<arr[0]<<" : max element"<<std::endl;
        answer.insert(answer.begin(),arr[0]);
        counter--;
        arr.erase(arr.begin());
        heapify(arr);
    }
    return answer;
}

void insert(int arr[], int val, int n){
    if (arr[n-1]!=-1) return;
    int j = 0;
    while (j<n&&arr[j]!=-1) j++;
    arr[j] = val;
    int parentIndex = (j-1)/2;

    while (parentIndex>=0&&arr[parentIndex]<arr[j]) {
        swap(arr[parentIndex],arr[j]);
        j = parentIndex;
        parentIndex = (j-1)/2;
    }
}

vector<int> create (int arr[], int n){
    int answer[n];
    answer[0] = arr[0];
    for (int i=1;i<n;i++) answer[i] = -1;
    for (int i=1;i<n;i++){
        insert(answer,arr[i],n);
    }
    vector<int> result;
    for (int i=0;i<n;i++) result.push_back(answer[i]);
    return result;
}

int main(){

    int arr[] = {10,15,20,5,25,35,30,40,3,27,1,212,79,34,16,54,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> heap;
    for (int i=0;i<n;i++) heap.push_back(arr[i]);

    vector<int> heap1 = create(arr,n); //max heap implementation
    for (int i=0;i<n;i++) std::cout<<heap1[i]<<" ";
    std::cout<<std::endl;
    heapify(arr,n);
    for (int i=0;i<n;i++) std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
    vector<int> answer = heapSort(heap);
    for (int i=0;i<n;i++) std::cout<<answer[i]<<" ";
    std::cout<<std::endl;

    return 0;
}