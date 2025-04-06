#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

int square(int n) {
    return n*n;
}
map<int,int> store;

int compute(vector<int> squares, int n){
    if (store.find(n)!=store.end()) return store[n];
    if (n==0) return 0;
    int m = squares.size();
    int minim = n;
    for (int i=0;i<m;i++){
        if ((n-squares[i])<0) continue;
        if (store.find(n-squares[i])==store.end()) store[n-squares[i]]= compute(squares,n-squares[i]);
        int current = store[n-squares[i]];
        if ((1+current)<minim) minim = 1 + current;
    }
    store[n] = minim;
    return store[n];
}

int numSquares(int n){  
    if (n==1) return 1;
    int count = 1;
    while (square(count)<=n) count++;
    vector<int> squares;
    for (int i=count-1;i>=1;i--) squares.push_back(square(i));
    if (squares[0]==n) return 1;
    return compute(squares,n);   
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<numSquares(n)<<std::endl;
    return 0;
}