#include<iostream>

int countPrimes(int n){
    if (n<=2) return 0;
    bool arr[n];
    for (int i=0;i<n;i++) arr[i] = true;
    arr[0] = arr[1] = false;
    for (int i = 2;i<n;i++){
        if (arr[i]){
            int count = 2;
            while (count*i<n){
                arr[count*i] = false;
                count++;
            }
        }
    }
    int counter = 0;
    for (int i =0;i<n;i++){
        if (arr[i]) counter++;
    }
    return counter;
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<countPrimes(n)<<std::endl;
    return 0;
}