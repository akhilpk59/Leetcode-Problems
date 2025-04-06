#include<iostream>

double myPow(double x, int n){
    if (x==1) return 1;
    if (n==0) return 1;
    else if (n<0){
     if (n!=-2147483648) return (1/myPow(x,-n));
     else return (1/myPow(x,2147483647))/x;
    }
    int exp = n;
    double answer = 1;
    while(exp>0) {
        answer*=x;
        exp--;
    }
    return answer;
}

int main(){
    double x;
    std::cin>>x;
    int n;
    std::cin>>n;
    std::cout<<myPow(x,n)<<std::endl;
    return 0;
}