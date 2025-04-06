#include<iostream>
#include<map>

using namespace std;

map <int, double> fibonacci;

double fibo(int n){
    if (n<=2) return 1;
    if (fibonacci.find(n)==fibonacci.end()) fibonacci[n] = fibo(n-1) + fibo(n-2);
    return fibonacci[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}