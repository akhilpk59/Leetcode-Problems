#include<iostream>
#include<map>
#include<vector>
using std::map;
using std::vector;

int square(int n){
    return n*n;
}

// bool checkPerfect(int n){
//     if (n==1) return true;
//     for (int i=2;i<=n-1;i++){
//         int current = square(i);
//         if (n<current) return false;
//         if (n%current==0) return checkPerfect(n/current);
//     }
//     return false;
// }

map<int,int> store;

int numSquares (int n){
    if (store.find(n)!=store.end()) return store[n];
    if (n==1) {
        store[1] = 1;
        return 1;
    }
    // if (checkPerfect(n)) {
    //     store[n] = 1;
    //     return 1;
    // }
    int count = 1;
    while (square(count)<=n) count++;

    vector<int> squares;

    for (int i=count-1;i>=1;i--){
        squares.push_back(square(i));
    }
    if (squares[0]==n){
        store[n] = 1;
        return 1;
    }
    int lowest = n;
    int m = squares.size();

    for (int i=0;i<m;i++){
        if (store.find(n-squares[i])==store.end()) store[n-squares[i]] = numSquares(n-squares[i]);
        int count = store[n-squares[i]];
        if ((1+count)<lowest) lowest = 1 + count;
    }
    store[n] = lowest;
    return lowest;  
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<numSquares(n)<<std::endl;
    return 0;
}