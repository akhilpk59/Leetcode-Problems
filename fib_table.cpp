#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    double fib[n+1];

    if (n==0) {
        cout<<0<<endl;
        return 0;
    }
    if (n==1) {
        cout<<1<<endl;
        return 0;
    }

    for (int i=0;i<n+1;i++) fib[i]=0;
    
    fib[1] = 1;

    for (int i=0;i<n;i++){
        if (i!=n-1) {
            fib[i+1] += fib[i];
            fib[i+2] +=fib[i];
        }
        else fib[i+1] +=fib[i];
    }
    cout<<fib[n]<<endl;
    return 0;
}