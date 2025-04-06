#include<iostream>
#include<map>
using std::map;

int countPrimes(int n){
    if (n<=1) return 0;
    if (n==2) return 1;
    map<int,int> primes;
    primes[2] = 1;
    for (int i=3;i<n;i++){
        bool composite = false;
        for (auto it=primes.begin();it!=primes.end();it++){
            if ((i%it->first)==0) {
                composite = true;
                break;
            }
        }
        if (!composite) primes[i] = 1;
    }
    return primes.size(); 
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<countPrimes(n)<<std::endl;
    return 0;
}