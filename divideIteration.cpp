#include<iostream>

int divide (int dividend, int divisor){
    if (dividend==divisor) return 1;
    if (dividend==-2147483648){
        if (divisor==-2147483648) return 1;
        else if (divisor==2147483647) return -1;
        if (divisor>0){
            if (divisor==1) return -2147483648;
            int rem = dividend + divisor;
            int count = 1;
            rem = 0 - rem;
            while (rem>=divisor){
                rem-= divisor;
                count++;
            }
            return 0-count;
        }
        else {
            if (divisor==-1) return 2147483647;
            int rem = dividend - divisor;
            int count = 1;
            rem = 0 - rem;
            divisor = 0 - divisor;
            while (rem>=divisor){
                rem-=divisor;
                count++;
            }
            return count;
        }
    }
    if (divisor==-2147483648) return 0;
    if (divisor==2147483647) {
        if (dividend==-2147483647) return -1;
        else return 0;
    }
    bool nDividend = false;
    bool nDivisor = false;
    if (dividend<0) {
        nDividend = true;
        dividend = 0 - dividend;
    }
    if (divisor<0) {
        nDivisor = true;
        divisor = 0 - divisor;
    }
    int count = 0;
    while (dividend>=divisor){
        dividend-=divisor;
        count++;
    }
    return (!(nDividend^nDivisor)) ? count : 0 - count;
}

int main() {
    int dividend, divisor;
    std::cin>>dividend>>divisor;
    std::cout<<divide(dividend,divisor)<<std::endl;
    return 0;
}